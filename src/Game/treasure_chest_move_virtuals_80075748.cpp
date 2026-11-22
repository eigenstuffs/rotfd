/* Part of the original TreasureChestMove source: configureCallbacks and the members
 * after it, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: configureCallbacks).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h. */
#include "Game/move_classes.h"
struct FactoryCallback;
struct CTreasureChestMoveFields {char unknown00[0x198];FactoryCallback**callbacks;};
static inline CTreasureChestMoveFields*fields(CTreasureChestMove*self){return reinterpret_cast<CTreasureChestMoveFields*>(self);}
extern "C"{extern unsigned char lbl_801EF5C8[];extern const char lbl_8029CC50[],lbl_8029CC60[];void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);FactoryCallback*fn_80075044(FactoryCallback*,CTreasureChestMove*);FactoryCallback*fn_80075124(FactoryCallback*,CTreasureChestMove*);void fn_8007D8EC(CFSM*,FactoryCallback**);signed char fn_8007DA74(CFSM*,float);}
void CTreasureChestMove::configureCallbacks(){CTreasureChestMove*self=this;
FactoryCallback*p0=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,60,4);if(p0)p0=fn_80075044(p0,self);fields(self)->callbacks[0]=p0;
FactoryCallback*p1=(FactoryCallback*)fn_801EFA1C(lbl_801EF5C8,12,lbl_8029CC50,lbl_8029CC60,61,4);if(p1)p1=fn_80075124(p1,self);fields(self)->callbacks[1]=p1;
fn_8007D8EC(&static_cast<CFSM&>(*self),fields(self)->callbacks);configure(2);}
extern "C" void slot34__18CTreasureChestMoveFv(){}
extern "C" void slot38__18CTreasureChestMoveFf(CTreasureChestMove*self,float delta){fn_8007DA74(&static_cast<CFSM&>(*self),delta);}
