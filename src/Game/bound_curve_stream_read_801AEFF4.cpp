/* Bound curve owner stream/application reconstruction; see docs/notes/game-bound-curve-owner-apply.md. */
typedef unsigned long BoundCurve_801AEFF4_Word;
struct BoundCurve_801AEFF4_Stream{void*position;};
struct BoundCurve_801AEFF4_Curve{int unknown00,count;void*items;int unknown0C;};
struct BoundCurve_801AEFF4_Globals{char unknown00[0x118];void*manager;};
extern "C"{extern BoundCurve_801AEFF4_Globals lbl_801E9D24;void fn_801B41F4(void*,void*,BoundCurve_801AEFF4_Stream*);void*fn_801E9F40(void*,const void*,int);void fn_801B2354(BoundCurve_801AEFF4_Curve*,BoundCurve_801AEFF4_Stream*);void fn_801B217C(BoundCurve_801AEFF4_Curve*,BoundCurve_801AEFF4_Stream*);void fn_801B1DC4(BoundCurve_801AEFF4_Curve*,BoundCurve_801AEFF4_Stream*);void fn_801F6BFC(void*,BoundCurve_801AEFF4_Stream*);}
struct BoundCurve_801AEFF4_Owner{BoundCurve_801AEFF4_Word handle;unsigned short id;char unknown06[6];BoundCurve_801AEFF4_Curve first,second,third;};
extern "C"void fn_801AEFF4(BoundCurve_801AEFF4_Owner*self,BoundCurve_801AEFF4_Stream*stream){fn_801B41F4(lbl_801E9D24.manager,self,stream);stream->position=fn_801E9F40(&self->id,stream->position,2);fn_801B217C(&self->first,stream);fn_801B2354(&self->second,stream);fn_801B2354(&self->third,stream);}
