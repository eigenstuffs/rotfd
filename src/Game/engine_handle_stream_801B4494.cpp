/* Original engine registry and handle stream routines.
 * See docs/notes/game-engine-handle-stream.md. */
typedef unsigned int u32;
extern "C" {
    void*fn_801F7EB8(void*);
    void fn_80208BFC(void*,int);
    void fn_802083C8(void*,void*,void*,int);
    float fn_801F45D8();
    extern const float lbl_8037A220;
    extern const char lbl_802AC8F4[];
    void fn_801FA014(void*,const char*,...);
}
struct ObjectStorage_801B4494 {
    char unknown[8];
};
struct Object_801B4494:ObjectStorage_801B4494 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
};
struct Handle_801B4494 {
    u32 word;
};
struct RegistryKey_801B4494 {
    int index,unknown4;
    u32 key;
    RegistryKey_801B4494(int n) {
        fn_80208BFC(this,n);
    }
};
struct Entry_801B4494 {
    void*object;
    u32 key;
    char unknown8[8];
};
struct Array_801B4494 {
    int count,capacity;
    Handle_801B4494*data;
};
struct Owner_801B4494 {
    int count,capacity;
    Entry_801B4494*entries;
    char unknownC[0xB8-0xC];
    Array_801B4494 handles;
    void*registry;
};
struct Globals_801B4494 {
    char unknown[0x110];
    void*logger;
};
extern "C" Globals_801B4494 lbl_801E9D24;
extern "C" void fn_801B4494(Owner_801B4494*self) {
    float start=fn_801F45D8();
    int i;
    for(i=0; i<self->count; ++i) {
        if(self->entries[i].object) {
            RegistryKey_801B4494 key(-1);
            key.key=self->entries[i].key;
            key.index=i;
            void*entry;
            fn_802083C8(self->registry,&key,&entry,1);
        }
    }
    for(i=0; i<self->handles.count; ++i) {
        Object_801B4494*object=(Object_801B4494*)fn_801F7EB8(&self->handles.data[i]);
        object->slot10();
    }
    for(i=0; i<self->handles.count; ++i) {
        Object_801B4494*object=(Object_801B4494*)fn_801F7EB8(&self->handles.data[i]);
        object->slot14();
    }
    u32 ticks=(u32)(lbl_8037A220*(fn_801F45D8()-start));
    fn_801FA014(lbl_801E9D24.logger,lbl_802AC8F4,ticks/60000,(ticks/1000)%60,ticks%1000);
}
