#include "Game/curve_owner_operations_table.h"
typedef unsigned long Word;
extern "C" {extern char lbl_8028F698[],lbl_801EF5C8[];void fn_8028FD50(void*,void*,unsigned long);void fn_801EF610(void*,void*);void fn_80243E90(void*,int);}
struct Handle_801F7F10{Word word;~Handle_801F7F10();};
struct CurveOwnerHandle1_BAF8:Handle_801F7F10{~CurveOwnerHandle1_BAF8(){}};
struct CurveOwnerHandle2_BAF8:CurveOwnerHandle1_BAF8{~CurveOwnerHandle2_BAF8(){}};
struct CurveBase_801B1088 {unsigned short flags,unknown;~CurveBase_801B1088();};
template<class T>struct CurveOwnerArray_BAF8 {int count,capacity;T*data;~CurveOwnerArray_BAF8(){if(data){for(int i=0;i<count;++i)data[i].~T();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}data=0;}}};
template<class T>struct CurveOwnerCurve_BAF8:CurveBase_801B1088 {CurveOwnerArray_BAF8<T>rows;~CurveOwnerCurve_BAF8(){}};
struct CurveOwnerRecord8_BAF8{Word fields[2];~CurveOwnerRecord8_BAF8(){}};
struct CurveOwnerRecord16_BAF8{Word fields[4];~CurveOwnerRecord16_BAF8(){}};
struct CurveOwner_BAF8 {Word unknown00[2];void*table;char unknown0C[0xB8-0xC];CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>a,b,c,d,e;CurveOwnerCurve_BAF8<CurveOwnerRecord16_BAF8>f;CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>g,h,i,j;CurveOwnerCurve_BAF8<CurveOwnerRecord16_BAF8>k;CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>l,m;CurveOwnerHandle2_BAF8 handle;};
extern "C" CurveOwner_BAF8* fn_801DBAF8(
    CurveOwner_BAF8* self, short deleting) {
    if (self) {
        self->table = &lbl_802EA6C0;
        self->handle.~CurveOwnerHandle2_BAF8();
        self->m.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->l.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->k.~CurveOwnerCurve_BAF8<CurveOwnerRecord16_BAF8>();
        self->j.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->i.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->h.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->g.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->f.~CurveOwnerCurve_BAF8<CurveOwnerRecord16_BAF8>();
        self->e.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->d.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->c.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->b.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        self->a.~CurveOwnerCurve_BAF8<CurveOwnerRecord8_BAF8>();
        fn_80243E90(self, 0);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
