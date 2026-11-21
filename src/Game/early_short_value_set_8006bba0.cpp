struct ValuePrefix { int unknown00; };
struct ValueQuery : ValuePrefix {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual int getValue();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void setValue(int);
};
extern "C" signed char fn_8006BBA0(ValueQuery* self, short value)
{
    self->setValue(value);
    return 1;
}
