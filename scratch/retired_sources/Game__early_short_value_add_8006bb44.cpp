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
extern "C" signed char fn_8006BB44(ValueQuery* self, short value)
{ int current=self->getValue(); current+=value; self->setValue(current); return 1; }
