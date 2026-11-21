// Populate retained records and their scale/property arrays from selected handles.
typedef unsigned long u32;struct PopulateSelector;struct Manager;struct PopulateContext{char unknown00[0x118];Manager*manager;char unknown11C[0x28];PopulateSelector*selector;};extern "C"{extern PopulateContext lbl_801E9D24;void fn_801F86C8(Manager*,const void*,short);}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct RecordValueConstructorHandle1 : Handle_801F7F10 {
    RecordValueConstructorHandle1() { value = 0; }
    ~RecordValueConstructorHandle1() {}
};
struct RecordValueConstructorHandle2 : RecordValueConstructorHandle1 {
    RecordValueConstructorHandle2() { value = 0; }
    ~RecordValueConstructorHandle2() {}
    RecordValueConstructorHandle2& operator=(const Handle_801F7F10& other) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
        return *this;
    }
};
struct RecordValueConstructorHandle3 : RecordValueConstructorHandle2 {
    RecordValueConstructorHandle3() { value = 0; }
    ~RecordValueConstructorHandle3() {}
};
struct RecordValueConstructorVector { float x, y, z; };
struct Record_80209EA0 {
    RecordValueConstructorVector position, velocity;
    float field18;
    char unknown1C[8];
    float field24, field28;
    char unknown2C[0xC];
    unsigned long long value38;
    RecordValueConstructorHandle2 handle40;
    RecordValueConstructorHandle3 handle44, handle48, handle4C;
    u32 field50;
    char unknown54[0x54];
    Record_80209EA0(const Handle_801F7F10&, unsigned long long);
    ~Record_80209EA0();
};
struct ManipulatorPrefix {unsigned long unknown00[2];};
struct Manipulator_Z:ManipulatorPrefix {
 Manipulator_Z();virtual ~Manipulator_Z();
 virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float)=0;virtual void slot3C();
 char unknown0C[0x20-0x0C];
};

extern "C" {extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);}
struct BitRecordWords {int count,capacity;unsigned long*words;
 void reserve(int n){if(n){if(words)words=(unsigned long*)fn_8028FAF4(lbl_8028F698,words,capacity*4,n*4);else words=(unsigned long*)fn_8028FF24(lbl_8028F698,n*4);}else if(words){fn_8028FD50(lbl_8028F698,words,capacity*4);words=0;}capacity=n;}
 void resize(int n){if(n>count){reserve(n);for(int i=count;i<n;++i){}count=n;}else if(n<count){for(int i=count-1;i>=n;--i){}reserve(n);count=n;}}
};
struct BitRecordOwner {int count,capacity;char*records;BitRecordWords storage;int size,initialized,used;
 void setSize(int n){size=n;if(n&&((n>>5)+1)>storage.count)storage.resize((size>>5)+1);}
 void setBit(int i){storage.words[i>>5]|=1UL<<(i&31);}
};
struct PopulateOwner:Manipulator_Z{
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9C();
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void slotC0();
virtual void slotC4();
virtual void slotC8();
virtual void slotCC();
virtual void slotD0();
virtual void slotD4();
virtual void finishRecord(int);
virtual void slotDC();
virtual void slotE0();
virtual void slotE4();
virtual void slotE8();
virtual void slotEC();
virtual void slotF0();
virtual void slotF4();
virtual void slotF8();
virtual void slotFC();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10C();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11C();
virtual void reserve(int);
char unknown20[0x160];BitRecordOwner records;u32 unknown1A4;Handle_801F7F10 related;char unknown1AC[0x14];float*scales;char unknown1C4[8];unsigned long*properties;float&getScale(int i){return scales[i];}unsigned long&getProperty(int i){return properties[i];}};
struct PopulateObject:Manipulator_Z{char unknown20[8];Handle_801F7F10*items;char unknown2C[0x140];Handle_801F7F10 related;};
struct BorrowedPopulateObject{PopulateObject*value;BorrowedPopulateObject(PopulateObject*p):value(p){}operator PopulateObject*()const{return value;}PopulateObject*operator->()const{return value;}};
struct PopulateEntry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct Manager{int count,capacity;PopulateEntry*entries;};struct PopulateSelector{char unknown00[0x94];int*selection;const int&operator[](int index)const{return selection[index];}};extern "C"{extern const char lbl_8037B1A0[6];int fn_8024A120(void*,const char*,int);int fn_802257EC(BitRecordOwner*,const Record_80209EA0*);float fn_8023BE00(void*,int);int fn_8024BCA4(void*,const Handle_801F7F10*);int fn_8024A800(void*,int);void fn_802279A0(void*);}
inline void*resolvePopulate(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}
struct PopulateHandle1:Handle_801F7F10{PopulateHandle1(){value=0;}};struct PopulateCopy1:PopulateHandle1{PopulateCopy1(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
inline void assignPopulate(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" void fn_8022F624(PopulateOwner* self, const Handle_801F7F10* input) {
    assignPopulate(self->related, *input);
    PopulateObject* related = static_cast<PopulateObject*>(resolvePopulate(self->related));
    BorrowedPopulateObject object(
        static_cast<PopulateObject*>(resolvePopulate(related->related)));
    int count = fn_8024A120(object, lbl_8037B1A0, 1);
    self->reserve(count);
    for (int i = 0; i < count; ++i) {
        PopulateCopy1 copy(object->items[(*lbl_801E9D24.selector)[i + 0x1C]]);
        int index;
        {
            Record_80209EA0 record(copy, 0ULL);
            index = fn_802257EC(&self->records, &record);
        }
        self->getScale(index) = fn_8023BE00(resolvePopulate(copy), 0);
        self->getProperty(index) = fn_8024A800(object, fn_8024BCA4(object, &copy));
        self->finishRecord(index);
    }
    fn_802279A0(self);
}

typedef char CheckRecord[sizeof(Record_80209EA0)==0xA8?1:-1];
typedef char CheckHandle[sizeof(Handle_801F7F10)==4?1:-1];

typedef char CheckRoot[sizeof(Manipulator_Z)==0x20?1:-1];
typedef char CheckOwner[sizeof(PopulateOwner)==0x1D0?1:-1];
typedef char CheckObject[sizeof(PopulateObject)==0x170?1:-1];
typedef char CheckManager[sizeof(Manager)==0xC?1:-1];
typedef char CheckBorrowedObject[sizeof(BorrowedPopulateObject)==4?1:-1];

typedef char CheckRecordPool[sizeof(BitRecordOwner)==0x24?1:-1];
