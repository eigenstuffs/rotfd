#include "ai_abi.h"

char* __AIVersion = "<< Dolphin SDK - AI\trelease build: Sep  5 2002 05:34:25 (0x2301) >>";

static AISCallback __AIS_Callback = NULL;
static AIDCallback __AID_Callback = NULL;
u8* __CallbackStack = NULL;
u8* __OldStack = NULL;
static vs32 __AI_init_flag = FALSE;
static vs32 __AID_Active   = FALSE;

OSTime bound_32KHz = 0;
OSTime bound_48KHz = 0;
OSTime min_wait = 0;
OSTime max_wait = 0;
OSTime buffer = 0;

static void __AI_set_stream_sample_rate(u32 rate);
static void __AISHandler(s16 interrupt, OSContext* context);
static void __AIDHandler(s16 interrupt, OSContext* context);
extern void __AICallbackStackSwitch(AIDCallback cb);
extern void __AI_SRC_INIT(void);

AIDCallback AIRegisterDMACallback(AIDCallback callback)
{
	s32 oldInts;
	AIDCallback ret;

	ret            = __AID_Callback;
	oldInts        = OSDisableInterrupts();
	__AID_Callback = callback;
	OSRestoreInterrupts(oldInts);
	return ret;
}

void AIInitDMA(u32 address, u32 length)
{
	s32 previousInterruptState;

	previousInterruptState = OSDisableInterrupts();

	__DSPRegs[DSP_DMA_START_HI]    = (u16)((__DSPRegs[DSP_DMA_START_HI] & ~0x3FF) | (address >> 16));
	__DSPRegs[DSP_DMA_START_LO]    = (u16)((__DSPRegs[DSP_DMA_START_LO] & ~0xFFE0) | (address & 0xFFFF));
	__DSPRegs[DSP_DMA_CONTROL_LEN] = (u16)((__DSPRegs[DSP_DMA_CONTROL_LEN] & ~0x7FFF) | ((length >> 5) & 0xFFFF));

	OSRestoreInterrupts(previousInterruptState);
}

void AIStartDMA(void)
{
	SET_FLAG(__DSPRegs[DSP_DMA_CONTROL_LEN], DSP_DMA_START_FLAG);
}

void AIStopDMA(void)
{
	RESET_FLAG(__DSPRegs[DSP_DMA_CONTROL_LEN], DSP_DMA_START_FLAG);
}

u32 AIGetDMABytesLeft(void)
{
    return (__DSPRegs[DSP_DMA_BYTES_LEFT] & 0x7FFF) << 5;
}

BOOL AICheckInit(void)
{
    return __AI_init_flag;
}

static inline void AIResetStreamSampleCount(void)
{
	__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_COUNT) | AI_CONTROL_STREAM_SAMPLE_COUNT;
}

static inline void AISetStreamTrigger(u32 trigger)
{
	__AIRegs[AI_INTRPT_TIMING] = trigger;
}

void AISetStreamPlayState(u32 playState)
{
	s32 previousInterruptState;
	u8 rightVolume;
	u8 leftVolume;

	// If the requested state is the same as the current state, do nothing
	if (playState == AIGetStreamPlayState()) {
		return;
	}

	// If the sample rate is 0 and the requested state is play, initialize the sample rate converter
	if (AIGetStreamSampleRate() == 0 && playState == TRUE) {
		rightVolume = AIGetStreamVolRight();
		leftVolume  = AIGetStreamVolLeft();

		// Temporarily mute the audio
		AISetStreamVolRight(0);
		AISetStreamVolLeft(0);

		// Disable interrupts and initialize the sample rate converter
		previousInterruptState = OSDisableInterrupts();
		__AI_SRC_INIT();

		// Set the stream and state bits in the control register
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_COUNT) | AI_CONTROL_STREAM_SAMPLE_COUNT;
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_PLAY_STATE) | AI_CONTROL_PLAY_STATE;

		// Restore the previous interrupt state
		OSRestoreInterrupts(previousInterruptState);

		// Restore the audio volume
		AISetStreamVolLeft(rightVolume);
		AISetStreamVolRight(leftVolume);
	} else {
		// Set the state bit in the control register to the requested state
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_PLAY_STATE) | playState;
	}
}

u32 AIGetStreamPlayState(void)
{
	return __AIRegs[AI_CONTROL] & AI_CONTROL_PLAY_STATE;
}

void AISetDSPSampleRate(u32 rate)
{
	u32 playState;
	s32 previousInterruptState;
	u8 leftVolume;
	u8 rightVolume;
	u32 streamSampleRate;

	// If the requested rate is the same as the current rate, do nothing
	if (rate == AIGetDSPSampleRate()) {
		return;
	}

	// Clear the DSP sample rate bit in the control register
	__AIRegs[AI_CONTROL] &= ~AI_CONTROL_DSP_SAMPLE_RATE;

	if (rate == 0) {
		leftVolume       = AIGetStreamVolLeft();
		rightVolume      = AIGetStreamVolRight();
		playState        = AIGetStreamPlayState();
		streamSampleRate = AIGetStreamSampleRate();

		// Temporarily mute the audio
		AISetStreamVolLeft(0);
		AISetStreamVolRight(0);

		// Disable interrupts and initialize the sample rate converter
		previousInterruptState = OSDisableInterrupts();
		__AI_SRC_INIT();

		// Set the stream sample count, stream sample rate, and play state bits in the control register
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_COUNT) | AI_CONTROL_STREAM_SAMPLE_COUNT;
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_RATE) | (streamSampleRate * 2);
		__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_PLAY_STATE) | playState;

		// Set the DSP sample rate bit in the control register
		__AIRegs[AI_CONTROL] |= AI_CONTROL_DSP_SAMPLE_RATE;

		// Restore the previous interrupt state
		OSRestoreInterrupts(previousInterruptState);

		// Restore the audio volume
		AISetStreamVolLeft(leftVolume);
		AISetStreamVolRight(rightVolume);
	}
}

u32 AIGetDSPSampleRate(void)
{
	return ((__AIRegs[AI_CONTROL] >> 6) & 1) ^ 1;
}

static void __AI_set_stream_sample_rate(u32 rate)
{
	s32 previousInterruptState;
	s32 playState;
	u8 leftVolume;
	u8 rightVolume;
	s32 dspSampleRateState;

	// If the requested rate is the same as the current rate, do nothing
	if (rate == AIGetStreamSampleRate()) {
		return;
	}

	playState   = AIGetStreamPlayState();
	leftVolume  = AIGetStreamVolLeft();
	rightVolume = AIGetStreamVolRight();

	// Temporarily mute the audio
	AISetStreamVolRight(0);
	AISetStreamVolLeft(0);

	// Save the state of the DSP sample rate bit and clear it in the control register
	dspSampleRateState = __AIRegs[AI_CONTROL] & AI_CONTROL_DSP_SAMPLE_RATE;
	__AIRegs[AI_CONTROL] &= ~AI_CONTROL_DSP_SAMPLE_RATE;

	// Disable interrupts and initialize the sample rate converter
	previousInterruptState = OSDisableInterrupts();
	__AI_SRC_INIT();

	// Restore the DSP sample rate bit in the control register
	__AIRegs[AI_CONTROL] |= dspSampleRateState;

	// Set the stream sample count and stream sample rate bits in the control register
	__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_COUNT) | AI_CONTROL_STREAM_SAMPLE_COUNT;
	__AIRegs[AI_CONTROL] = (__AIRegs[AI_CONTROL] & ~AI_CONTROL_STREAM_SAMPLE_RATE) | (rate * 2);

	// Restore the previous interrupt state
	OSRestoreInterrupts(previousInterruptState);

	// Restore the audio play state and volume
	AISetStreamPlayState(playState);
	AISetStreamVolLeft(leftVolume);
	AISetStreamVolRight(rightVolume);
}

u32 AIGetStreamSampleRate(void)
{
	return (__AIRegs[AI_CONTROL] >> 1) & 1;
}

void AISetStreamVolLeft(u8 volume)
{
	__AIRegs[AI_VOLUME] = (__AIRegs[AI_VOLUME] & ~0xFF) | (volume & 0xFF);
}

u8 AIGetStreamVolLeft(void)
{
	return __AIRegs[AI_VOLUME];
}

void AISetStreamVolRight(u8 volume)
{
	__AIRegs[AI_VOLUME] = (__AIRegs[AI_VOLUME] & ~0xFF00) | ((volume & 0xFF) << 8);
}

u8 AIGetStreamVolRight(void)
{
	return __AIRegs[AI_VOLUME] >> 8;
}

void AIInit(u8* stack)
{
	// If AI is already initialized, do nothing
	if (__AI_init_flag == TRUE) {
		return;
	}

	// Register AI version
	OSRegisterVersion(__AIVersion);

	// Set bounds and buffer sizes in ticks
	bound_32KHz = OSNanosecondsToTicks(31524);
	bound_48KHz = OSNanosecondsToTicks(42024);
	min_wait    = OSNanosecondsToTicks(42000);
	max_wait    = OSNanosecondsToTicks(63000);
	buffer      = OSNanosecondsToTicks(3000);

	// Initialize AI stream settings
	AISetStreamVolRight(0);
	AISetStreamVolLeft(0);
	AISetStreamTrigger(0);
	AIResetStreamSampleCount();
	__AI_set_stream_sample_rate(1);
	AISetDSPSampleRate(0);

	// Clear callbacks and set callback stack
	__AIS_Callback  = 0;
	__AID_Callback  = 0;
	__CallbackStack = stack;

	// Set interrupt handlers and unmask interrupts
	__OSSetInterruptHandler(5, __AIDHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_DSP_AI);
	__OSSetInterruptHandler(8, __AISHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_AI);

	// Set AI initialisation flag to TRUE
	__AI_init_flag = TRUE;
}

void AIReset(void)
{
    __AI_init_flag = FALSE;
}

static void __AISHandler(s16 interrupt, OSContext* context)
{
	OSContext tmpContext;
	__AIRegs[AI_CONTROL] |= 8;
	OSClearContext(&tmpContext);
	OSSetCurrentContext(&tmpContext);
	if (__AIS_Callback != NULL) {
		__AIS_Callback(__AIRegs[AI_SAMPLE_COUNTER]);
	}
	OSClearContext(&tmpContext);
	OSSetCurrentContext(context);
}

static void __AIDHandler(s16 interrupt, OSContext* context)
{
	OSContext tempContext;
	u32 temp     = __DSPRegs[5];
	__DSPRegs[5] = (temp & ~0xA0) | 8;
	OSClearContext(&tempContext);
	OSSetCurrentContext(&tempContext);
	if (__AID_Callback && !__AID_Active) {
		__AID_Active = TRUE;
		if (__CallbackStack) {
			__AICallbackStackSwitch(__AID_Callback);
		} else {
			__AID_Callback();
		}

		__AID_Active = FALSE;
	}

	OSClearContext(&tempContext);
	OSSetCurrentContext(context);
}

