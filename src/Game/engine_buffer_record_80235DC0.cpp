struct BufferRecordScalarHandle {unsigned int value;};
struct BufferRecordScalarStorage {unsigned int a,b;};
struct BufferRecordScalarOwner:BufferRecordScalarStorage {virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50(int,float);
    char pad0C[0x51];char locked;char pad5E[2];int flags60;char pad64[0x18];BufferRecordScalarHandle target;char pad80[0x24];int mode,state;};
extern "C" {extern struct {char pad[0x118];void*manager;}lbl_801E9D24;void __ct__15Handle_801F7F10Fv(BufferRecordScalarHandle*);void __dt__15Handle_801F7F10Fv(BufferRecordScalarHandle*,int);void fn_801F86C8(void*,const BufferRecordScalarHandle*,short);extern const float lbl_8037B210,lbl_8037B214,lbl_8037B218;}
static inline void clear(BufferRecordScalarHandle*h){__ct__15Handle_801F7F10Fv(h);h->value=0;h->value=0;h->value=0;h->value=0;h->value=0;}
extern "C" void fn_80235DC0(BufferRecordScalarOwner* self)
{
    self->locked = 0;
    self->flags60 = 0;
    BufferRecordScalarHandle empty;
    clear(&empty);
    fn_801F86C8(lbl_801E9D24.manager, &self->target, -1);
    self->target.value = empty.value;
    fn_801F86C8(lbl_801E9D24.manager, &empty, 1);
    __dt__15Handle_801F7F10Fv(&empty, 0);
    self->state = 0;
    self->mode = 3;
    self->s50(0, lbl_8037B210);
    self->s50(1, lbl_8037B214);
    self->s50(2, lbl_8037B218);
}
