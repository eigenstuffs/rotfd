/* Actor callbacks capture the owner and shared construction context. */
struct ActorCallback;
struct FactoryContext;
struct ActorController {
    virtual void slot08();
    virtual void slot0C();
    virtual void configure(int);
    char unknown04[0x28];
};
struct ActorFactory {
    char unknown00[0x318];
    ActorController controller;
    ActorCallback** slots;
};
extern "C" {
extern unsigned char lbl_801EF5C8[];
extern const char lbl_8029DC48[],lbl_8029DC58[];
void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
ActorCallback* fn_8008145C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80081778(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80081904(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80081A90(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80081C60(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800875A8(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80087A48(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800821D0(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800824A0(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800828A4(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80082BAC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083064(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008335C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083504(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083AAC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083DE4(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083F24(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80083C54(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008418C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80084460(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80084720(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80086254(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80085AF0(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80086E88(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80087834(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80088B80(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80087C38(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80087EBC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80088028(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008823C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80088544(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800886EC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800858EC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008A168(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008A400(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008A758(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008B310(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008B414(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80089210(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80089F4C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008499C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800854F0(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008BA4C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008BE6C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008C354(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008C7CC(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80088F7C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_80086860(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008CC44(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008CE30(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008CFD4(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_800E582C(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008D678(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008D940(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008E040(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008E0A8(ActorCallback*,ActorFactory*,FactoryContext*);
ActorCallback* fn_8008E5D4(ActorCallback*,ActorFactory*,FactoryContext*);
}
struct Object_80084F00 {
    char unknown00[0x48];
    Object_80084F00(unsigned long,unsigned long);
};
inline void* operator new(unsigned long,void* memory) { return memory; }
extern "C" void fn_80090500(ActorFactory* self,FactoryContext* context) {
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 240, 4);
        if (callback) callback = fn_8008145C(callback,self,context);
        self->slots[0] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 241, 4);
        if (callback) callback = fn_80081778(callback,self,context);
        self->slots[1] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 242, 4);
        if (callback) callback = fn_80081904(callback,self,context);
        self->slots[2] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 243, 4);
        if (callback) callback = fn_80081A90(callback,self,context);
        self->slots[3] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 244, 4);
        if (callback) callback = fn_80081C60(callback,self,context);
        self->slots[4] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 245, 4);
        if (callback) callback = fn_800875A8(callback,self,context);
        self->slots[5] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 246, 4);
        if (callback) callback = fn_80087A48(callback,self,context);
        self->slots[6] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 88, lbl_8029DC48, lbl_8029DC58, 247, 4);
        if (callback) callback = fn_800821D0(callback,self,context);
        self->slots[7] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 248, 4);
        if (callback) callback = fn_800824A0(callback,self,context);
        self->slots[8] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 249, 4);
        if (callback) callback = fn_800828A4(callback,self,context);
        self->slots[9] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 250, 4);
        if (callback) callback = fn_80082BAC(callback,self,context);
        self->slots[10] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 251, 4);
        if (callback) callback = fn_80083064(callback,self,context);
        self->slots[11] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 252, 4);
        if (callback) callback = fn_8008335C(callback,self,context);
        self->slots[12] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 253, 4);
        if (callback) callback = fn_80083504(callback,self,context);
        self->slots[13] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 254, 4);
        if (callback) callback = fn_80083AAC(callback,self,context);
        self->slots[14] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 255, 4);
        if (callback) callback = fn_80083DE4(callback,self,context);
        self->slots[36] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 256, 4);
        if (callback) callback = fn_80083F24(callback,self,context);
        self->slots[37] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 257, 4);
        if (callback) callback = fn_80083C54(callback,self,context);
        self->slots[15] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 258, 4);
        if (callback) callback = fn_8008418C(callback,self,context);
        self->slots[38] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 259, 4);
        if (callback) callback = fn_80084460(callback,self,context);
        self->slots[39] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 260, 4);
        if (callback) callback = fn_80084720(callback,self,context);
        self->slots[16] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 261, 4);
        if (callback) callback = fn_80086254(callback,self,context);
        self->slots[17] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 92, lbl_8029DC48, lbl_8029DC58, 262, 4);
        if (callback) callback = fn_80085AF0(callback,self,context);
        self->slots[18] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 263, 4);
        if (callback) callback = fn_80086E88(callback,self,context);
        self->slots[19] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 264, 4);
        if (callback) callback = fn_80087834(callback,self,context);
        self->slots[20] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 92, lbl_8029DC48, lbl_8029DC58, 265, 4);
        if (callback) callback = fn_80088B80(callback,self,context);
        self->slots[21] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 266, 4);
        if (callback) callback = fn_80087C38(callback,self,context);
        self->slots[23] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 267, 4);
        if (callback) callback = fn_80087EBC(callback,self,context);
        self->slots[24] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 268, 4);
        if (callback) callback = fn_80088028(callback,self,context);
        self->slots[25] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 269, 4);
        if (callback) callback = fn_8008823C(callback,self,context);
        self->slots[26] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 270, 4);
        if (callback) callback = fn_80088544(callback,self,context);
        self->slots[27] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 271, 4);
        if (callback) callback = fn_800886EC(callback,self,context);
        self->slots[28] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 272, 4);
        if (callback) callback = fn_800858EC(callback,self,context);
        self->slots[43] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 274, 4);
        if (callback) callback = fn_8008A168(callback,self,context);
        self->slots[29] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 275, 4);
        if (callback) callback = fn_8008A400(callback,self,context);
        self->slots[30] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 108, lbl_8029DC48, lbl_8029DC58, 276, 4);
        if (callback) callback = fn_8008A758(callback,self,context);
        self->slots[31] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 277, 4);
        if (callback) callback = fn_8008B310(callback,self,context);
        self->slots[32] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 88, lbl_8029DC48, lbl_8029DC58, 278, 4);
        if (callback) callback = fn_8008B414(callback,self,context);
        self->slots[35] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 80, lbl_8029DC48, lbl_8029DC58, 280, 4);
        if (callback) callback = fn_80089210(callback,self,context);
        self->slots[33] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 281, 4);
        if (callback) callback = fn_80089F4C(callback,self,context);
        self->slots[34] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 76, lbl_8029DC48, lbl_8029DC58, 282, 4);
        if (callback) callback = fn_8008499C(callback,self,context);
        self->slots[22] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 72, lbl_8029DC48, lbl_8029DC58, 283, 4);
        callback = (ActorCallback*)new(callback) Object_80084F00((unsigned long)self,(unsigned long)context);
        self->slots[40] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 80, lbl_8029DC48, lbl_8029DC58, 284, 4);
        if (callback) callback = fn_800854F0(callback,self,context);
        self->slots[41] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 286, 4);
        if (callback) callback = fn_8008BA4C(callback,self,context);
        self->slots[42] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 287, 4);
        if (callback) callback = fn_8008BE6C(callback,self,context);
        self->slots[44] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 288, 4);
        if (callback) callback = fn_8008C354(callback,self,context);
        self->slots[45] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 289, 4);
        if (callback) callback = fn_8008C7CC(callback,self,context);
        self->slots[46] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 72, lbl_8029DC48, lbl_8029DC58, 291, 4);
        if (callback) callback = fn_80088F7C(callback,self,context);
        self->slots[47] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 293, 4);
        if (callback) callback = fn_80086860(callback,self,context);
        self->slots[48] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 295, 4);
        if (callback) callback = fn_8008CC44(callback,self,context);
        self->slots[49] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 296, 4);
        if (callback) callback = fn_8008CE30(callback,self,context);
        self->slots[50] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 298, 4);
        if (callback) callback = fn_8008CFD4(callback,self,context);
        self->slots[51] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 80, lbl_8029DC48, lbl_8029DC58, 299, 4);
        if (callback) callback = fn_800E582C(callback,self,context);
        self->slots[52] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 68, lbl_8029DC48, lbl_8029DC58, 300, 4);
        if (callback) callback = fn_8008D678(callback,self,context);
        self->slots[53] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 88, lbl_8029DC48, lbl_8029DC58, 301, 4);
        if (callback) callback = fn_8008D940(callback,self,context);
        self->slots[54] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 303, 4);
        if (callback) callback = fn_8008E040(callback,self,context);
        self->slots[55] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 305, 4);
        if (callback) callback = fn_8008E0A8(callback,self,context);
        self->slots[56] = callback;
    }
    {
        ActorCallback* callback = (ActorCallback*)fn_801EFA1C(
            lbl_801EF5C8, 64, lbl_8029DC48, lbl_8029DC58, 307, 4);
        if (callback) callback = fn_8008E5D4(callback,self,context);
        self->slots[57] = callback;
    }
    self->controller.configure(58);
}
