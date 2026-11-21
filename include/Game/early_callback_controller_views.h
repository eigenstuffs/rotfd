#ifndef GAME_EARLY_CALLBACK_CONTROLLER_VIEWS_H
#define GAME_EARLY_CALLBACK_CONTROLLER_VIEWS_H
struct EarlyControlCallback {
 virtual void slot0();
 virtual void start();
 virtual void update(float);
 virtual void stop();
 signed char exclusive;
};
struct EarlyCallbackController {
 void* table;
 signed char enabled;
 signed char changing;
 char unknown06[2];
 int current;
 int previous;
 int pending;
 int unknown14;
 unsigned long long active;
 unsigned long long activeCount;
 int count;
 EarlyControlCallback** callbacks;
};
extern "C" void fn_8007DCF4(EarlyCallbackController*,int);
extern "C" void fn_8007DB78(EarlyCallbackController*);
#endif
