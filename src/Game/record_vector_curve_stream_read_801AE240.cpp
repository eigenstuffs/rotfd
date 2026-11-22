typedef unsigned long RecordCurve_801AE240_Word;
struct RecordCurve_801AE240_Stream{void*position;};
struct RecordCurve_801AE240_Curve{int unknown00,count;void*items;int unknown0C;};
struct RecordCurve_801AE240_Globals{char unknown00[0x118];void*manager;};
extern "C"{extern RecordCurve_801AE240_Globals lbl_801E9D24;void fn_801B41F4(void*,void*,RecordCurve_801AE240_Stream*);void*fn_801E9F40(void*,const void*,int);void fn_801B2354(RecordCurve_801AE240_Curve*,RecordCurve_801AE240_Stream*);void fn_801B217C(RecordCurve_801AE240_Curve*,RecordCurve_801AE240_Stream*);void fn_801B1DC4(RecordCurve_801AE240_Curve*,RecordCurve_801AE240_Stream*);void fn_801F6BFC(void*,RecordCurve_801AE240_Stream*);}
struct RecordCurve_801AE240_Owner{RecordCurve_801AE240_Word handle;unsigned short id;char unknown06[6];RecordCurve_801AE240_Curve first,second,third,fourth;};
extern "C"void fn_801AE240(RecordCurve_801AE240_Owner*self,RecordCurve_801AE240_Stream*stream){fn_801B41F4(lbl_801E9D24.manager,self,stream);stream->position=fn_801E9F40(&self->id,stream->position,2);fn_801B217C(&self->first,stream);fn_801B1DC4(&self->second,stream);fn_801B217C(&self->third,stream);fn_801F6BFC(&self->fourth,stream);}
