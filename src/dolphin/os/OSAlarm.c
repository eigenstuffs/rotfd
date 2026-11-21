/* Dolphin SDK alarm scheduling, GSQE78.
 * Adapted from the doldecomp/melee SDK reconstruction; see
 * reference/melee-sdk/PROVENANCE.md for source URLs and hashes.
 * The original assembly exception entry remains a fallback object.
 * Its C callback is exposed here solely to connect that partial split.
 */
#define NULL 0
#define TRUE 1
#define ASSERTLINE(line,condition) ((void)0)
#define ASSERTMSGLINE(line,condition,message) ((void)0)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed long long OSTime;
typedef double f64;
typedef int BOOL;
typedef u8 __OSException;
typedef struct OSContext
{
    /*0x000*/ u32 gpr[32];
    /*0x080*/ u32 cr;
    /*0x084*/ u32 lr;
    /*0x088*/ u32 ctr;
    /*0x08C*/ u32 xer;
    /*0x090*/ f64 fpr[32];
    /*0x190*/ u32 fpscr_pad;
    /*0x194*/ u32 fpscr;
    /*0x198*/ u32 srr0;
    /*0x19C*/ u32 srr1;
    /*0x1A0*/ u16 mode;
    /*0x1A2*/ u16 state;
    /*0x1A4*/ u32 gqr[8];
    /*0x1C4*/ f64 psf[32];
} OSContext;

typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);

struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm* prev;
    OSAlarm* next;
    OSTime period;
    OSTime start;
};


typedef void (*__OSExceptionHandler)(__OSException, OSContext *);
extern __OSExceptionHandler __OSGetExceptionHandler(__OSException);
extern __OSExceptionHandler __OSSetExceptionHandler(__OSException, __OSExceptionHandler);
extern OSTime __OSGetSystemTime(void), __OSTimeToSystemTime(OSTime);
extern void PPCMtdec(u32);
extern BOOL OSDisableInterrupts(void), OSRestoreInterrupts(BOOL);
extern void OSLoadContext(OSContext *), OSClearContext(OSContext *), OSSetCurrentContext(OSContext *);
extern void OSDisableScheduler(void), OSEnableScheduler(void), __OSReschedule(void);
extern void OSReport(const char *, ...);



// internal header


struct OSAlarmQueue {
    struct OSAlarm* head;
    struct OSAlarm* tail;
};

static struct OSAlarmQueue AlarmQueue;

// functions
static inline void SetTimer(struct OSAlarm* alarm);
static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler);
void DecrementerExceptionCallback(register __OSException exception,
                                         register OSContext* context);
extern void DecrementerExceptionHandler(__OSException exception,
                                        OSContext* context);

#define ASSERTREPORT(line, cond)                                              \
    if (!(cond)) {                                                            \
        OSReport("OSCheckAlarmQueue: Failed " #cond " in %d", line);          \
        return 0;                                                             \
    }

static inline BOOL OSCheckAlarmQueue(void)
{
    struct OSAlarm* alarm;

    ASSERTREPORT(0x70, AlarmQueue.head == NULL && AlarmQueue.tail == NULL ||
                           AlarmQueue.head != NULL && AlarmQueue.tail != NULL);
    ASSERTREPORT(0x71,
                 AlarmQueue.head == NULL || AlarmQueue.head->prev == NULL);
    ASSERTREPORT(0x72,
                 AlarmQueue.tail == NULL || AlarmQueue.tail->next == NULL);

    for (alarm = AlarmQueue.head; alarm; alarm = alarm->next) {
        ASSERTREPORT(0x75, alarm->next == NULL || alarm->next->prev == alarm);
        ASSERTREPORT(0x76, alarm->next != NULL || AlarmQueue.tail == alarm);
    }
    return TRUE;
}

static inline void SetTimer(struct OSAlarm* alarm)
{
    OSTime delta = alarm->fire - __OSGetSystemTime();

    if (delta < 0) {
        PPCMtdec(0);
    } else if (delta < 0x80000000) {
        PPCMtdec((u32) delta);
    } else {
        PPCMtdec(0x7fffffff);
    }
}

void OSInitAlarm(void)
{
    if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
        AlarmQueue.head = AlarmQueue.tail = NULL;
        __OSSetExceptionHandler(8, DecrementerExceptionHandler);
    }
}

void OSCreateAlarm(OSAlarm* alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
}

static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler)
{
    OSAlarm* next;
    OSAlarm* prev;

    if (0 < alarm->period) {
        OSTime time = __OSGetSystemTime();

        fire = alarm->start;
        if (alarm->start < time) {
            fire +=
                alarm->period * ((time - alarm->start) / alarm->period + 1);
        }
    }

    ASSERTLINE(0xD6, alarm->handler == 0);

    alarm->handler = handler;
    alarm->fire = fire;

    for (next = AlarmQueue.head; next; next = next->next) {
        if (next->fire <= fire) {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;

        if (prev) {
            prev->next = alarm;
        } else {
            AlarmQueue.head = alarm;
            SetTimer(alarm);
        }

        return;
    }

    ASSERTLINE(0xF3, next == 0);

    alarm->next = 0;
    prev = AlarmQueue.tail;
    AlarmQueue.tail = alarm;
    alarm->prev = prev;

    if (prev) {
        prev->next = alarm;
    } else {
        AlarmQueue.head = AlarmQueue.tail = alarm;
        SetTimer(alarm);
    }
}

void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
    BOOL enabled;
    ASSERTMSGLINE(0x114, tick > 0, "OSSetAlarm(): tick was less than zero.");
    ASSERTMSGLINE(0x115, handler, "OSSetAlarm(): null handler was specified.");
    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
    ASSERTLINE(0x11C, OSCheckAlarmQueue());
    OSRestoreInterrupts(enabled);
}

static inline void OSSetAbsAlarm(struct OSAlarm* alarm, long long time,
                   void (*handler)(struct OSAlarm*, struct OSContext*))
{
    int enabled;

    ASSERTMSGLINE(0x130, handler,
                  "OSSetAbsAlarm(): null handler was specified.");
    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, time, handler);
    ASSERTLINE(0x137, OSCheckAlarmQueue());
    OSRestoreInterrupts(enabled);
}

static inline void OSSetPeriodicAlarm(OSAlarm* alarm, OSTime start, OSTime period,
                        OSAlarmHandler handler)
{
    BOOL enabled;
    ASSERTMSGLINE(0x14D, period > 0,
                  "OSSetPeriodicAlarm(): period was less than zero.");
    ASSERTMSGLINE(0x14E, handler,
                  "OSSetPeriodicAlarm(): null handler was specified.");
    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = __OSTimeToSystemTime(start);
    InsertAlarm(alarm, 0, handler);
    ASSERTLINE(0x156, OSCheckAlarmQueue());
    OSRestoreInterrupts(enabled);
}

void OSCancelAlarm(OSAlarm* alarm)
{
    OSAlarm* next;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (alarm->handler == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == 0) {
        AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }
    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        AlarmQueue.head = next;
        if (next) {
            SetTimer(next);
        }
    }
    alarm->handler = 0;
    ASSERTLINE(0x189, OSCheckAlarmQueue());
    OSRestoreInterrupts(enabled);
}

void DecrementerExceptionCallback(register __OSException exception,
                                         register OSContext* context)
{
    OSAlarm* alarm;
    OSAlarm* next;
    OSAlarmHandler handler;
    OSTime time;
    OSContext exceptionContext;

    time = __OSGetSystemTime();
    alarm = AlarmQueue.head;
    if (alarm == 0) {
        OSLoadContext(context);
    }

    if (time < alarm->fire) {
        SetTimer(alarm);
        OSLoadContext(context);
    }

    next = alarm->next;
    AlarmQueue.head = next;
    if (next == 0) {
        AlarmQueue.tail = 0;
    } else {
        next->prev = 0;
    }
    ASSERTLINE(0x1C2, OSCheckAlarmQueue());
    handler = alarm->handler;
    alarm->handler = 0;
    if (0 < alarm->period) {
        InsertAlarm(alarm, 0, handler);
        ASSERTLINE(0x1CC, OSCheckAlarmQueue());
    }

    if (AlarmQueue.head) {
        SetTimer(AlarmQueue.head);
    }

    OSDisableScheduler();
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    handler(alarm, context);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
    OSEnableScheduler();
    __OSReschedule();
    OSLoadContext(context);
}

