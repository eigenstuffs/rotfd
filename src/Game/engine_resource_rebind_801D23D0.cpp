/* Original engine keyed child and resource rebinding.
 * See docs/notes/game-engine-resource-rebind.md. */
typedef unsigned int u32;
struct Handle_801D23D0 {
    u32 word;
};
struct Manager_801D23D0;
struct HandleArray_801D23D0 {
    int count,capacity;
    Handle_801D23D0*data;
};
struct Record_801D23D0 {
    u32 unknown;
    Handle_801D23D0 handle;
    char unknown8[16];
};
template<class T>struct Array_801D23D0 {
    int count,capacity;
    T*data;
    T&operator[](int i) {
        return data[i];
    }
    int getCount()const {
        return count;
    }
};
struct Globals_801D23D0 {
    char unknown[0x118];
    Manager_801D23D0*manager;
    char unknown11C[0x144-0x11C];
    void*resources;
};
extern "C" Globals_801D23D0 lbl_801E9D24;
struct Owner_801D23D0 {
    char unknown[0x20];
    HandleArray_801D23D0 handles;
    char unknown2C[0x40-0x2C];
    Array_801D23D0<Record_801D23D0>first,second,third;
    char unknown64[0x70-0x64];
    Array_801D23D0<Array_801D23D0<u32> > groups;
};
extern "C" {
    void fn_801B3D80(Manager_801D23D0*,Handle_801D23D0*,HandleArray_801D23D0*);
    void fn_801D0CBC(Owner_801D23D0*);
    void fn_801B3FC8(Manager_801D23D0*,u32,u32*);
    u32 fn_801F4F8C(void*,const u32*);
}
extern "C" void fn_801D23D0(Owner_801D23D0*self) {
    int i;
    for(i=0; i<self->first.count; ++i)fn_801B3D80(lbl_801E9D24.manager,&self->first[i].handle,&self->handles);
    for(i=0; i<self->second.count; ++i)fn_801B3D80(lbl_801E9D24.manager,&self->second[i].handle,&self->handles);
    for(i=0; i<self->third.count; ++i)fn_801B3D80(lbl_801E9D24.manager,&self->third[i].handle,&self->handles);
    fn_801D0CBC(self);
    u32 key=0;
    for(i=0; i<self->groups.count; ++i) {
        for(int j=0; j<self->groups[i].getCount(); ++j) {
            fn_801B3FC8(lbl_801E9D24.manager,self->groups[i][j],&key);
            self->groups[i][j]=fn_801F4F8C(lbl_801E9D24.resources,&key);
        }
    }
}
