#include "game_controller.h"

#include "game_engine.h"

extern "C" {
extern const float lbl_8037A670;
extern struct {
    unsigned char prefix[0x10C];
    unsigned int flags;
    void *reporter;
    Engine *engine;
} lbl_801E9D24;
}
void Controller::set_rate(float rate)
{
    Controller *self = this;
    self->inverse_rate = lbl_8037A670 / rate;
    if (!(lbl_801E9D24.flags & 0x40000))
        lbl_801E9D24.engine->notify(6);
}
extern "C" {
#pragma dont_inline on
void fn_801EFD84(Controller *self) {}
#pragma dont_inline reset
void fn_801EFD88(Controller *self, float dt)
{
    for (int i = 0; i < self->count; ++i)
        if ((self->enabled & (1 << i)) && self->actions[i].callback)
            (self->*self->actions[i].callback)(dt);
}
}

extern "C" {
extern unsigned char lbl_8028F698[16];
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
int sprintf(char *, const char *, ...);
extern const char lbl_802AD480[], lbl_802AD490[];
extern const char lbl_8037A678[8], lbl_8037A680[8], lbl_8037A688[8];
}

typedef unsigned long size_t;
inline void *operator new(size_t, void *p) { return p; }
static inline void resize_actions(Controller *self, int n)
{
    if(n > self->count) {
        if(self->actions)
            self->actions = (Action *)fn_8028FAF4(lbl_8028F698,self->actions,self->capacity * sizeof(Action),n * sizeof(Action));
        else
            self->actions = (Action *)fn_8028FF24(lbl_8028F698,n * sizeof(Action));
        self->capacity = n;
        for(int i=self->count;i<n;++i) new (&self->actions[i]) Action;
        self->count=n;
    } else if(n < self->count) {
        for(int i=self->count-1;i>=n;--i) self->actions[i].~Action();
        if(self->actions)
            self->actions = (Action *)fn_8028FAF4(lbl_8028F698,self->actions,self->capacity * sizeof(Action),n * sizeof(Action));
        else
            self->actions = (Action *)fn_8028FF24(lbl_8028F698,n * sizeof(Action));
        self->capacity=n;
        self->count=n;
    }
}
extern "C" void fn_801EFE3C(Controller *self)
{
    resize_actions(self,5);
    sprintf(self->actions[0].name,lbl_802AD480);
    self->actions[0].callback=&Controller::set_rate;
    sprintf(self->actions[1].name,lbl_8037A678);
    self->actions[1].callback=&Controller::message;
    sprintf(self->actions[2].name,lbl_8037A680);
    self->actions[2].callback=&Controller::script;
    sprintf(self->actions[3].name,lbl_802AD490);
    sprintf(self->actions[4].name,lbl_8037A688);
    fn_801EFD84(self);
    for(int i=0;i<self->count;++i)
        if(i!=0) self->disable(1<<i);
    self->select(1);
}

void Controller::script(float) {}
void Controller::message(float) {}
