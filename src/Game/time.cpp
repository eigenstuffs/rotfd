/* Game tick conversion and frame delta, reconstructed from GSQE78. */
typedef unsigned long u32;
extern "C" u32 OSGetTick();
struct GameClock { char unknown[0x214];float fixedStep;u32 previous; };
static inline float elapsedMilliseconds()
{
    u32 tick=OSGetTick();
    return (float)tick/((float)(*(volatile u32*)0x800000F8/4)/1000.0f);
}
extern "C" {
float fn_801F45D8()
{
    return elapsedMilliseconds()/1000.0f;
}
float fn_801F463C(GameClock *clock)
{
    u32 now;
    if(clock->fixedStep!=0.0f)now=clock->previous+(u32)(1000.0f*clock->fixedStep/60.0f);
    else now=(u32)elapsedMilliseconds();
    float delta=(float)(int)(now-clock->previous)/1000.0f;
    if(delta>0.5f || delta<0.0f)delta=1.0f/30.0f;
    clock->previous=now;
    return delta;
}
}
