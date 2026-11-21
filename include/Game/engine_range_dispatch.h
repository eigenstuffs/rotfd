#ifndef GAME_ENGINE_RANGE_DISPATCH_H
#define GAME_ENGINE_RANGE_DISPATCH_H

typedef struct RangeDispatchRange {short first,last,count;}RangeDispatchRange;
typedef struct RangeDispatchRecord {int value,state;RangeDispatchRange first,second;float stamp;}RangeDispatchRecord;
typedef struct RangeDispatchArray24 {int count,capacity;RangeDispatchRecord*items;}RangeDispatchArray24;
typedef struct RangeDispatchOwner {char unknown00[8];RangeDispatchRange range;short unknown0E;float stamp,threshold;char unknown18[4];RangeDispatchArray24 records;int unknown28,unknown2C;int unknown30;}RangeDispatchOwner;
typedef struct RangeDispatchHandle {signed int generation:8;signed int index:24;}RangeDispatchHandle;
typedef struct RangeDispatchNode {char unknown00[0x1C];RangeDispatchHandle first,second;char unknown24[0x48];unsigned short type;char unknown6E[0x46];unsigned int flagsB4;char unknownB8[0x68];unsigned int flags120;}RangeDispatchNode;
typedef struct RangeDispatchEntry {RangeDispatchNode*object;int unknown04,unknown08;signed char generation;char unknown0D[3];}RangeDispatchEntry;
typedef struct RangeDispatchManager {char unknown00[8];RangeDispatchEntry*entries;}RangeDispatchManager;
typedef struct RangeDispatchContext {char unknown00[0x118];RangeDispatchManager*manager;}RangeDispatchContext;
#ifdef __cplusplus
extern "C" {
#endif
extern RangeDispatchContext lbl_801E9D24;
typedef struct RangeDispatchCallback {char unknown00[0x20];RangeDispatchHandle handle;signed char active,state;char unknown26[2];RangeDispatchHandle target;float value2C,value30;}RangeDispatchCallback;
void fn_8020E394(RangeDispatchCallback*);
RangeDispatchRecord*fn_8020E46C(RangeDispatchOwner*,const int*,signed char*);
void fn_8020EB54(RangeDispatchCallback*,const RangeDispatchHandle*);
extern void fn_8020EE70(RangeDispatchCallback*);
extern void fn_8020EDB0(RangeDispatchCallback*);
extern signed char fn_8020E558(RangeDispatchOwner*,RangeDispatchRecord*,short);
extern void fn_8020E938(RangeDispatchOwner*,RangeDispatchRecord*,int);
extern void fn_801F86C8(RangeDispatchManager*,const RangeDispatchHandle*,int);
extern void slot34__13Manipulator_ZFv(RangeDispatchCallback*);
extern void fn_802525F0(RangeDispatchNode*);
extern const float lbl_8037AAB4;
#ifdef __cplusplus
}
#endif

#endif
