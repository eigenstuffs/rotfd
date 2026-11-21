#include "Game/engine_controller_port_update.h"

extern "C" {
extern int lbl_803780B8;
extern signed char lbl_803780BC, lbl_803780BD, lbl_803780BE;
int abs(int);
void fn_80275C08(ControllerPortView*);
}
static inline ControllerPortOutput* controllerPortOutput(ControllerPortView* self, int port) {
    return self->outputs + port;
}
extern "C" int fn_80275FC8(ControllerPortView*self,short port){
 if(!lbl_803780BC){lbl_803780B8=0;lbl_803780BC=1;}
 if(!lbl_803780BE){lbl_803780BD=0;lbl_803780BE=1;}
 ControllerPortOutput*out=controllerPortOutput(self,port);
 if(self->status[port].error==-3){out->disconnected=0;return 0;}
 if(self->status[port].error==-1){if(self->chord[port])out->disconnected=0;else out->disconnected=1;self->reset(port);return 0;}
 if(self->status[port].error==-2){out->disconnected=1;self->reset(port);return 0;}
 out->disconnected=0;
 if((self->status[port].buttons&0x1000)&&(self->status[port].buttons&0x800)&&(self->status[port].buttons&0x400))self->chord[port]=1;else self->chord[port]=0;
 if(self->status[port].buttons&8)out->up=255;else if(self->status[port].buttons&4)out->down=255;
 if(self->status[port].buttons&1)out->right=255;else if(self->status[port].buttons&2)out->left=255;
 if(self->status[port].buttons&0x800)out->a=255;
 if(self->status[port].buttons&0x400)out->b=255;
 if(self->status[port].buttons&0x100){if(!lbl_803780BD||lbl_803780B8<2){lbl_803780BD=1;lbl_803780B8=0;out->xButton=255;}}
 if(self->status[port].buttons&0x200)out->yButton=255;
 if(self->status[port].buttons&0x40)out->l=255;
 if(self->status[port].buttons&0x20)out->r=255;
 if(self->status[port].buttons&0x1000)out->extra=255;
 if(self->status[port].buttons&0x10)out->trigger=255;
 out->x=self->status[port].stickX*2;
 out->y=self->status[port].stickY*2;
 if(abs(out->x)<64)out->x=0;
 if(abs(out->y)<64)out->y=0;
 if(out->left)out->x=255;
 if(out->right)out->x=-255;
 if(out->up)out->y=255;
 if(out->down)out->y=-255;
 out->z=out->r-out->l;
 out->subX=self->status[port].subX*2;
 out->subY=self->status[port].subY*2;
 if(abs(out->subX)<64)out->subX=0;
 if(abs(out->subY)<64)out->subY=0;
 if(!port)fn_80275C08(self);
 if(lbl_803780BD)++lbl_803780B8;
 if(lbl_803780B8>5){lbl_803780B8=0;lbl_803780BD=0;}
 return 0;
}
