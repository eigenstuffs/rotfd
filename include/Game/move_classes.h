#ifndef GAME_MOVE_CLASSES_H
#define GAME_MOVE_CLASSES_H
/* Class hierarchy reconstructed from the original RTTI records and vtables.
 * Slot names are provisional: slotXX/scriptXX name the byte offset of the slot
 * in the vtable of the class that introduces it. */
struct Vec3;
struct BaseObject_Z {
    unsigned long unknown0; unsigned long identity;
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct Activable_Z : BaseObject_Z {
    unsigned long prev,next,field14; signed char field18; char pad19[3];
    virtual ~Activable_Z();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot18();
};
struct Manipulator_Z : Activable_Z {
    float accumulated;
    virtual ~Manipulator_Z();
    virtual void slot2C(float);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float) = 0;
    virtual void slot3C();
};
struct ObjectMove_Z : Manipulator_Z {
    virtual ~ObjectMove_Z();
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
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
    virtual float slot70();
    virtual void slot74();
    virtual void slot78(float);
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
    virtual void slotD8();
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
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    char pad_ObjectMove_Z[0x148];
};
struct ObjectThrow_Z : ObjectMove_Z {
    virtual ~ObjectThrow_Z();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12C();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot100();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot5C();
    virtual void slot64();
    virtual void slot84();
    virtual void slotF4();
    virtual void slotFC();
    char pad_ObjectThrow_Z[0x90];
};
struct LodMove_Z : ObjectThrow_Z {
    virtual ~LodMove_Z();
    virtual void slot13C();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15C();
    virtual void slot160(int, void*);
    virtual void slot164();
    virtual void slot168();
    virtual void slot16C();
    virtual void slot108();
    virtual void slot118();
    virtual void slot130();
    virtual void slot134();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot58();
    virtual void slot5C();
    virtual void slotB0();
    virtual void slotBC();
    virtual void slotC0();
    char pad_LodMove_Z[0x120];
};
struct VehiculeMove_Z : LodMove_Z {
    virtual ~VehiculeMove_Z();
    virtual void slot18();
    virtual void slot34();
};
struct CFSM {
    virtual ~CFSM();
    virtual void configureCallbacks();
    virtual void configure(int);
    virtual void reset();
    signed char enabled,changing;char unknown06[2];int current,previous,pending,unknown14;unsigned long long active,activeCount;int count;void**callbacks;
};
struct CHookMove : VehiculeMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CHookMove();
};
struct CCollectableMove : ObjectMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CCollectableMove();
};
struct CTreasureChestMove : ObjectMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual ~CTreasureChestMove();
};
struct CProjectileMove : LodMove_Z, CFSM {
    virtual void slot164(); // key function
    virtual void configureCallbacks();
    virtual void slot18C();
    virtual void slot18();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CProjectileMove();
};
struct CActorMove : LodMove_Z, CFSM {
    virtual void slot34(); // key function
    virtual void slot188();
    virtual void slot18C();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198(float);
    virtual void slot108();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot168();
    virtual void slot18();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot44();
    virtual void slot5C();
    virtual float slot70();
    virtual void slot74();
    virtual void slot78(float);
    virtual ~CActorMove();
};
struct CSpongeBobMove : CActorMove {
    virtual void configureCallbacks(); // key function
    virtual void slot110();
    virtual void slot12C();
    virtual void slot168();
    virtual void slot18();
    virtual void slot190();
    virtual void slot198(float);
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot44();
    virtual void slot5C();
    virtual ~CSpongeBobMove();
};
struct CNPCMove : CActorMove {
    virtual ~CNPCMove(); // key function
    virtual void configureCallbacks();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
};
struct CJellyfishMove : CNPCMove {
    virtual void slot198(float); // key function
    virtual void slot1A0(const float*);
    virtual void slot1A4();
    virtual void configureCallbacks();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot4C();
    virtual ~CJellyfishMove();
    void planarDirection_8009A6D4(Vec3* out);
};
struct CYellowJfishMove : CJellyfishMove {
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float); // key function
    virtual void slot18();
    virtual void slot1A4();
    virtual void slot34();
    virtual void slot38(float);
    virtual ~CYellowJfishMove();
};
struct CGreenJfishMove : CJellyfishMove {
    virtual void slot1A0(const float*); // key function
    virtual void slot18();
    virtual void slot198(float);
    virtual void slot1A4();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CGreenJfishMove();
};
struct CPinkJfishMove : CJellyfishMove {
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float); // key function
    virtual void slot18();
    virtual void slot1A4();
    virtual void slot34();
    virtual void slot38(float);
    virtual ~CPinkJfishMove();
};
struct CRedJfishMove : CJellyfishMove {
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float); // key function
    virtual void slot18();
    virtual void slot1A4();
    virtual void slot34();
    virtual void slot38(float);
    virtual ~CRedJfishMove();
};
struct CBlueJfishMove : CJellyfishMove {
    virtual void slot198(float); // key function
    virtual void slot18();
    virtual void slot1A4();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CBlueJfishMove();
};
struct CWildSnailMove : CActorMove {
    virtual void slot198(float); // key function
    virtual void configureCallbacks();
    virtual void slot1A0();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CWildSnailMove();
};
struct CScriptMove : CActorMove {
    virtual void slot60(); // key function
    virtual void configureCallbacks();
    virtual void slot1A0();
    virtual void slot1A4();
    virtual void slot18();
    virtual void slot198(float);
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot44();
    virtual void slot5C();
    virtual ~CScriptMove();
};
struct CSimpleMove : CScriptMove {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CSimpleMove();
};
struct CMediumMove : CScriptMove {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CMediumMove();
};
struct CComplexMove : CScriptMove {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CComplexMove();
};
struct CTileMove : ObjectMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CTileMove();
};
struct CWaterBallMove : ObjectThrow_Z, CFSM {
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float); // key function
    virtual void configureCallbacks();
    virtual void slot158();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot38(float);
    virtual ~CWaterBallMove();
};
struct CBombMove : CProjectileMove {
    virtual void slot38(float); // key function
    virtual ~CBombMove();
};
struct CDBombMove : CBombMove {
    virtual void slot38(float); // key function
    virtual ~CDBombMove();
};
struct CRBObjBaseMove : CActorMove {
    virtual ~CRBObjBaseMove();
    virtual void slot19C();
    virtual void slot164();
    virtual void slot18();
    virtual void slot18C();
    virtual void slot198(float);
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual void slot44();
};
struct CQSnailMove : CRBObjBaseMove {
    virtual void configureCallbacks(); // key function
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~CQSnailMove();
};
struct WaterHelmetMove : ObjectMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual void slot13C();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
    virtual ~WaterHelmetMove();
};
struct CSBPantsMove : LodMove_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual ~CSBPantsMove();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
};
struct CSBPants_BRKMove : ObjectThrow_Z, CFSM {
    virtual void configureCallbacks(); // key function
    virtual ~CSBPants_BRKMove();
    virtual void slot18();
    virtual void slot34();
    virtual void slot38(float);
    virtual void slot40(const Vec3*, const Vec3*, const Vec3*, int, float);
};
#endif
