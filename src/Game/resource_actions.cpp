/* Indexed resource actions reconstructed from GSQE78.
 * See docs/notes/game-resource-actions.md. */
typedef unsigned long u32;
struct ActionPrefix {u32 unknown;short id,flags;};
struct RefEntry {int type;u32 reference,unknown;};
template<class T>struct RefArray {u32 prefix;int size,capacity;T*data;T&operator[](int i){return data[i];}};
struct RefRow:RefArray<RefEntry>{};
struct ActionList:RefArray<RefRow>{u32 extra;};
struct Action:ActionPrefix {virtual void reset();char unknownC[0x30];ActionList children;};
struct Result {int size;int capacity;void*data;};
struct Owner {u32 unknown[2];const void*vtable;int size,capacity;Action*data;u32 unknown18[6];float time;short flags;};
extern "C" {
void fn_801F72E4(ActionList*,float,float,float,void*,Result*,char);
char slot1C__12BaseObject_ZFv(Owner*);
void __ct__12BaseObject_ZFv(Owner*);
extern const char lbl_802E9DE8[],__vt__17Resource_802E9E20[];
extern const float lbl_8037A800;
}
static inline int findAction(Owner*o,int id){for(int i=0;i<o->size;++i)if(o->data[i].id==id)return i;return -1;}
static inline void initializeBase(Owner*o){__ct__12BaseObject_ZFv(o);o->vtable=__vt__17Resource_802E9E20;}
extern "C" {
char fn_801F694C(Owner*o,int id,float start,float end,float length,void*value,Result*out){
 int index=findAction(o,id);
 if(index>=0){fn_801F72E4(&o->data[index].children,start,end,length,value,out,0);if(out->size)return 1;}
 return 0;
}
char fn_801F69F4(Owner*o){
 if(!slot1C__12BaseObject_ZFv(o))return 0;
 for(int i=0;i<o->size;++i)o->data[i].reset();
 return 1;
}
Owner*fn_801F6A7C(Owner*o){
 initializeBase(o);
 o->vtable=lbl_802E9DE8;
 o->size=0;o->capacity=0;o->data=0;
 o->unknown18[0]=0;o->unknown18[1]=0;o->unknown18[2]=0;o->unknown18[3]=0;o->unknown18[4]=0;o->unknown18[5]=0;
 o->time=lbl_8037A800;o->flags=0;
 return o;
}
}

struct SmartHandle {u32 value;};
struct GameGlobals {char unknown[0x118];void*context;};
extern "C" {
extern GameGlobals lbl_801E9D24;
void __ct__15Handle_801F7F10Fv(SmartHandle*);
void fn_801B3F0C(void*,SmartHandle*,u32);
u32 fn_801F84D4(void*,SmartHandle*);
void __dt__15Handle_801F7F10Fv(SmartHandle*,short);
void fn_801F6AF8(ActionList*o){
 for(int i=0;i<o->size;++i){
  RefRow*row=&(*o)[i];
  for(int j=0;j<row->size;++j){
   int type=(*row)[j].type;
   if(type==14||type==16||type==23||type==25||type==33||type==15){
    SmartHandle h;__ct__15Handle_801F7F10Fv(&h);
    fn_801B3F0C(lbl_801E9D24.context,&h,(*o)[i][j].reference);
    (*o)[i][j].reference=fn_801F84D4(lbl_801E9D24.context,&h);
    __dt__15Handle_801F7F10Fv(&h,-1);
   }
  }
 }
}
}
