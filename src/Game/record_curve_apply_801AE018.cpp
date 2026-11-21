/* Record curve stream/application reconstruction; see docs/notes/game-record-curve-stream-family.md. */
typedef unsigned long RecordCurve_801AE018_Word;
struct RecordCurve_801AE018_Stream{void*position;};
struct RecordCurve_801AE018_Curve{int unknown00,count;void*items;int unknown0C;};
struct RecordCurve_801AE018_Globals{char unknown00[0x118];void*manager;};
extern "C"{extern RecordCurve_801AE018_Globals lbl_801E9D24;void fn_801B41F4(void*,void*,RecordCurve_801AE018_Stream*);void*fn_801E9F40(void*,const void*,int);void fn_801B2354(RecordCurve_801AE018_Curve*,RecordCurve_801AE018_Stream*);void fn_801B217C(RecordCurve_801AE018_Curve*,RecordCurve_801AE018_Stream*);void fn_801B1DC4(RecordCurve_801AE018_Curve*,RecordCurve_801AE018_Stream*);void fn_801F6BFC(void*,RecordCurve_801AE018_Stream*);}
struct RecordCurve_801AE018_Owner{RecordCurve_801AE018_Word handle;unsigned short id;char unknown06[6];RecordCurve_801AE018_Curve first,second,third,fourth,fifth,position,scale,eighth;};
struct RecordCurve_801AE018_Vector{float x,y,z;RecordCurve_801AE018_Vector&operator=(const RecordCurve_801AE018_Vector&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct RecordCurve_801AE018_NodeStorage{RecordCurve_801AE018_Word unknown00[2];};
struct RecordCurve_801AE018_Node:RecordCurve_801AE018_NodeStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();RecordCurve_801AE018_Vector position;float angle;RecordCurve_801AE018_Vector scale;char unknown28[0x28];float opacity,first,second,third,fourth;};
extern "C"{short fn_801B0AA0(RecordCurve_801AE018_Curve*,float*,short,float);short fn_801AFFE4(RecordCurve_801AE018_Curve*,RecordCurve_801AE018_Vector*,short,float);}
extern "C"void fn_801AE018(RecordCurve_801AE018_Owner*self,short*indices,RecordCurve_801AE018_Node*node,float time){float scalar;RecordCurve_801AE018_Vector vector;
 if(self->first.count)indices[0]=fn_801B0AA0(&self->first,&node->first,indices[0],time);
 if(self->second.count)indices[1]=fn_801B0AA0(&self->second,&node->second,indices[1],time);
 if(self->fifth.count){indices[4]=fn_801B0AA0(&self->fifth,&scalar,indices[4],time);node->opacity=scalar;}
 if(self->third.count)indices[2]=fn_801B0AA0(&self->third,&node->third,indices[2],time);
 if(self->fourth.count)indices[3]=fn_801B0AA0(&self->fourth,&node->fourth,indices[3],time);
 if(self->position.count){indices[5]=fn_801AFFE4(&self->position,&vector,indices[5],time);node->position=vector;}
 if(self->scale.count){indices[6]=fn_801AFFE4(&self->scale,&vector,indices[6],time);node->scale=vector;}
 if(self->eighth.count){indices[7]=fn_801B0AA0(&self->eighth,&scalar,indices[7],time);node->angle=scalar;}
 node->slot24();
}
