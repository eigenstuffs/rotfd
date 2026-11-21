#include "Game/agent_controller_virtual_view_80062E18.h"
extern "C" {void fn_8007D6A0(void*,int);void fn_8025795C(void*,int,void*);void fn_80257828(void*,int,int,int);void fn_8025A3C8(void*,const OpaqueHandle&);int fn_8025E9FC(void*,int);void fn_8025E50C(void*);}
void Agent_80062E18::method_80064458(unsigned short value){value8A=value;}
void Agent_80062E18::method_80064460(unsigned char value){value88=value;}
void Agent_80062E18::method_80064468(unsigned long value){value84=value;}
void Agent_80062E18::method_80064470(int index){fn_8007D6A0((char*)resolve(getControllerHandle())+0x318,index);}
void Agent_80062E18::method_800644FC(int index,void*argument){fn_8025795C(this,index,argument);}
void Agent_80062E18::method_8006451C(int first,int second){fn_80257828(this,first,second,0);}
void Agent_80062E18::method_80064540(const OpaqueHandle&value){fn_8025A3C8(this,value);}
void Agent_80062E18::method_80064560(){slot_068();}
unsigned short Agent_80062E18::method_8006458C(){return value8A;}
unsigned char Agent_80062E18::method_80064594(){return value88;}
unsigned long Agent_80062E18::method_8006459C(){return value84;}
int Agent_80062E18::method_800645A4(int index){return fn_8025E9FC(this,index);}
void Agent_80062E18::method_800645C4(){fn_8025E50C(this);}
float Agent_80062E18::method_800645E4(){return scalar2C;}
void*Agent_80062E18::method_800645EC(){return resolve(&actor28);}
void Agent_80062E18::method_80064638(){}

