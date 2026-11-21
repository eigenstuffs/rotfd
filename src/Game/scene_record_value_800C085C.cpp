/* Set one scene record's value while retaining the original global array. */
struct Record {
    unsigned long unknown00[2];
    unsigned long value08;
    char unknown0C[0x18];
    void set(unsigned long value) { value08 = value; }
};
extern "C" Record lbl_80317F98[4];
inline Record* records() { return lbl_80317F98; }

extern "C" void fn_800C085C(int index, unsigned long value)
{
    records()[index].set(value);
}
