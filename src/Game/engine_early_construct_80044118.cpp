/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void __ct__22ContainerBase_802563CCFv(void*);
    extern char lbl_802B4B50[];
    extern char __vt__23ContainerLayer_80044168[];
}

struct Agent_80044118 {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x5C];
    unsigned char field68;
    Agent_80044118();
};

Agent_80044118::Agent_80044118() {
    __ct__22ContainerBase_802563CCFv(this);
    field08 = __vt__23ContainerLayer_80044168;
    field08 = lbl_802B4B50;
    field68 = 1;
}
