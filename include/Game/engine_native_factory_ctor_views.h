#ifndef ENGINE_NATIVE_FACTORY_REFINEMENT_CONSTRUCTORS_H
#define ENGINE_NATIVE_FACTORY_REFINEMENT_CONSTRUCTORS_H
typedef unsigned long u32;
/* Native base constructor declarations and observed layouts. */
struct CallbackSingle_802ECA18 {
    u32 unknown00[2]; void* vtable; char unknown0C[0x2C];
    unsigned long long flags; char unknown40[0x38];
    CallbackSingle_802ECA18(); ~CallbackSingle_802ECA18();
};
struct Object_8002AD98:CallbackSingle_802ECA18 {
    u32 field78,field7C; float vector80[3]; u32 field8C,field90;
    Object_8002AD98();
};
struct Agent_80062E18 {
    u32 unknown00[2]; void* vtable; char unknown0C[0x2C];
    unsigned long long flags; char unknown40[0x54]; void* secondaryVtable;
    char unknown98[0x200-0x98];
    Agent_80062E18(); ~Agent_80062E18();
};
struct Object_8006565C:Agent_80062E18 {Object_8006565C();};
struct Object_8006590C:Agent_80062E18 {Object_8006590C();};
struct Object_80065C60:Agent_80062E18 {Object_80065C60();};
typedef char CallbackSingleSizeCheck[(sizeof(CallbackSingle_802ECA18)==0x78)?1:-1];
typedef char CollectableObjectSizeCheck[(sizeof(Object_8002AD98)==0x98)?1:-1];
typedef char ActorScriptAgentSizeCheck[(sizeof(Agent_80062E18)==0x200)?1:-1];
typedef char MediumAgentSizeCheck[(sizeof(Object_8006565C)==0x200)?1:-1];
typedef char SimpleAgentSizeCheck[(sizeof(Object_8006590C)==0x200)?1:-1];
typedef char ComplexAgentSizeCheck[(sizeof(Object_80065C60)==0x200)?1:-1];
#endif
