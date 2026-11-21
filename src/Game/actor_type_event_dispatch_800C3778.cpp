/* Actor type and action event dispatch; see docs/notes/game-actor-type-event-dispatch.md. */
typedef unsigned char Byte;
struct Actor{Byte unknown00[0x24];void* related;signed char enabled;Byte unknown29[3];int type;Byte unknown30[0x574-0x30];int state;};
struct Context{Byte unknown00[0x124];void*events;};
extern "C"{extern Context lbl_801E9D24;extern const float lbl_80379538;void fn_802603A0(void*,int,void*,float);}
extern "C" void fn_800C3778(Actor*self,int action){
if(self->enabled){
switch(self->type){
case 3:if(action==0)fn_802603A0(lbl_801E9D24.events,0xC6,self->related,lbl_80379538);break;
case 1:if(action==0)fn_802603A0(lbl_801E9D24.events,0xC8,self->related,lbl_80379538);else if(action==1)fn_802603A0(lbl_801E9D24.events,0xC9,self->related,lbl_80379538);break;
case 8:case 9:case 10:case 11:case 12:case 13:if(action==0)fn_802603A0(lbl_801E9D24.events,0xCC,self->related,lbl_80379538);else if(action==1)fn_802603A0(lbl_801E9D24.events,0xCB,self->related,lbl_80379538);break;
case 2:if(action==2){if(self->state==1)self->state=0;}else if(action==3){if(self->state==0)self->state=1;}else if(action==0){if(self->state==0)fn_802603A0(lbl_801E9D24.events,0xC8,self->related,lbl_80379538);else if(self->state==1)fn_802603A0(lbl_801E9D24.events,0xC9,self->related,lbl_80379538);}break;
}
}
}
