#ifndef GAME_ENGINE_CONTROLLER_PORT_UPDATE_H
#define GAME_ENGINE_CONTROLLER_PORT_UPDATE_H

typedef unsigned char ControllerPortByte;
struct ControllerPortPadStatus {unsigned short buttons;signed char stickX,stickY,subX,subY;ControllerPortByte left,right,analogA,analogB;signed char error;char pad;};
struct ControllerPortOutput {char unknown00[0x10];short x,y,z,subX,subY;char unknown1A[2];ControllerPortByte a,b,xButton,yButton,start,unknown21,up,left,right,down,trigger,extra,l,r;char unknown2A[2];int disconnected;char unknown30[0x10];};
struct ControllerPortPrefix {char unknown00[8];ControllerPortOutput*outputs;char unknown0C[0x10];};
struct ControllerPortView:ControllerPortPrefix {virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void reset(short);ControllerPortPadStatus status[4];char unknown50[0x21];signed char chord[4];};

extern "C" int fn_80275FC8(ControllerPortView*, short);

typedef char ControllerPortPadStatusSize[sizeof(ControllerPortPadStatus) == 12 ? 1 : -1];
typedef char ControllerPortOutputSize[sizeof(ControllerPortOutput) == 64 ? 1 : -1];
#endif
