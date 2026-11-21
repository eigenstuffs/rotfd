/* Four groups of eight handle slots. Constructor ABI view; the original
 * virtual table and its methods remain separately owned. Factory registration
 * identifies SequenceMixAnim_Z.h, allocation size 0x188. */
typedef unsigned long Word;
struct Handle_801F7F10 {
 union { Word word; struct { signed int generation:8,index:24; } bits; };
 Handle_801F7F10();
 Handle_801F7F10(int index,signed char generation){bits.index=index;bits.generation=generation;}
 ~Handle_801F7F10();
};
struct RootPrefix { Word unknown00,identity; };
struct QueueArray_802EBD60:RootPrefix {
 QueueArray_802EBD60(); virtual ~QueueArray_802EBD60();
 virtual void slot0C(Word);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();
 virtual void slot20(int,int);virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();
 char unknown0C[0x54];
};
extern "C" void fn_801F7914(Handle_801F7F10*,const Handle_801F7F10&);
struct QueueGroups_802EBDA0:QueueArray_802EBD60 {
 Handle_801F7F10 slots[4][8];
 char unknownE0[0x80];
 int current[4],counts[4];
 signed char firstFlags[4],secondFlags[4];
 QueueGroups_802EBDA0();
 virtual ~QueueGroups_802EBDA0();
};
QueueGroups_802EBDA0::QueueGroups_802EBDA0(){
 for(int group=0;group<4;++group){
  counts[group]=0;
  firstFlags[group]=0;
  secondFlags[group]=0;
  for(int slot=0;slot<8;++slot)fn_801F7914(&slots[group][slot],Handle_801F7F10(0,0));
  current[group]=0;
 }
}
typedef char QueueGroupSizeCheck[sizeof(QueueGroups_802EBDA0)==0x188 ? 1 : -1];
