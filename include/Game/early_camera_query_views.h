#ifndef GAME_EARLY_CAMERA_QUERY_VIEWS_H
#define GAME_EARLY_CAMERA_QUERY_VIEWS_H

struct QueryVector{float x,y,z;QueryVector(){} QueryVector(float a,float b,float c):x(a),y(b),z(c){} QueryVector operator+(const QueryVector&o)const{return QueryVector(x+o.x,y+o.y,z+o.z);} QueryVector operator-(const QueryVector&o)const{return QueryVector(x-o.x,y-o.y,z-o.z);} QueryVector&operator=(const QueryVector&o){x=o.x;y=o.y;z=o.z;return *this;}};
struct QueryHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct QueryPrefix{char unknown00[8];};
struct QueryNode:QueryPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const QueryHandle* slot37(int);
char unknown0C[0x24];float matrix[3][3];char unknown54[0x2C4];char stateData;};
struct QueryEntry{QueryNode*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct QueryManager{int count,capacity;QueryEntry*entries;};
struct QueryContext{char unknown00[0x118];QueryManager*manager;};
extern "C" QueryContext lbl_801E9D24;
inline QueryNode*resolveQuery(const QueryHandle&h){QueryEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct QueryCamera{char unknown00[0x24];QueryHandle target;char unknown28[0xB4];float height;char unknownE0[0x14];QueryVector current;};
extern "C"{signed char fn_8007D604(void*,int);void fn_80076D98(QueryCamera*,QueryVector*);float fn_80285124(float,float);extern const float lbl_8037899C,lbl_803789A8,lbl_803789E4,lbl_803789EC;}

#endif
