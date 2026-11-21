/* Record curve stream/application reconstruction; see docs/notes/game-record-curve-stream-family.md. */
typedef unsigned long RecordCurve_801ADF58_Word;
struct RecordCurve_801ADF58_Stream{void*position;};
struct RecordCurve_801ADF58_Curve{int unknown00,count;void*items;int unknown0C;};
struct RecordCurve_801ADF58_Globals{char unknown00[0x118];void*manager;};
extern "C"{extern RecordCurve_801ADF58_Globals lbl_801E9D24;void fn_801B41F4(void*,void*,RecordCurve_801ADF58_Stream*);void*fn_801E9F40(void*,const void*,int);void fn_801B2354(RecordCurve_801ADF58_Curve*,RecordCurve_801ADF58_Stream*);void fn_801B217C(RecordCurve_801ADF58_Curve*,RecordCurve_801ADF58_Stream*);void fn_801B1DC4(RecordCurve_801ADF58_Curve*,RecordCurve_801ADF58_Stream*);void fn_801F6BFC(void*,RecordCurve_801ADF58_Stream*);}
struct RecordCurve_801ADF58_Owner{RecordCurve_801ADF58_Word handle;unsigned short id;char unknown06[6];RecordCurve_801ADF58_Curve first,second,third,fourth,fifth,position,scale,eighth;};
extern "C"void fn_801ADF58(RecordCurve_801ADF58_Owner*self,RecordCurve_801ADF58_Stream*stream){fn_801B41F4(lbl_801E9D24.manager,self,stream);stream->position=fn_801E9F40(&self->id,stream->position,2);fn_801B2354(&self->first,stream);fn_801B2354(&self->second,stream);fn_801B2354(&self->third,stream);fn_801B2354(&self->fourth,stream);fn_801B2354(&self->fifth,stream);fn_801B217C(&self->position,stream);fn_801B217C(&self->scale,stream);fn_801B2354(&self->eighth,stream);}
