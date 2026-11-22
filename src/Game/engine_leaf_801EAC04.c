extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern void *fn_801EFA1C(const void *,unsigned int,const char *,const char *,int,int);

extern const char lbl_802ACF20[];

extern void fn_801EAC8C(void *);

extern const char platform_type_registry_ObjectCache_Z_h[];

void fn_801EAC04(void *object,int count,int size) {*(int *)((char *)object+0xc)=size;fn_801EAC8C(object);if(*(void **)((char *)object+0x10))fn_801EF610(lbl_801EF5C8,*(void **)((char *)object+0x10));*(void **)((char *)object+0x10)=fn_801EFA1C(lbl_801EF5C8,count**(int *)((char *)object+0xc)*16,lbl_802ACF20,platform_type_registry_ObjectCache_Z_h,32,4);}
