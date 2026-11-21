struct RecordGateStorage { unsigned long unknown00, unknown04; };
struct RecordGateSource : RecordGateStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void* record();
};
struct RecordGateFlags { char unknown00[0x120]; unsigned long flags; };
extern "C" int fn_8026C094(void*, void*, void*, void*, void*);
extern "C" int fn_80248590(RecordGateSource* self, RecordGateFlags* flags,
                             void* target, void* record)
{
    if (!(flags->flags & 0x80000))
        return 0;
    if (target)
        return fn_8026C094(target, (char*)record + 0x20, self->record(),
                          (char*)record + 0x1C, (char*)record + 0xA0);
    else
        return 0;
}
