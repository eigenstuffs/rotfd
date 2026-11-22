struct View {
    char unknown00[0x1DC];
    unsigned char field1DC;
};
extern "C" View* fn_8007D074();
extern "C" View* fn_8006D144(void* unused, unsigned int value) {
    View* result = fn_8007D074();
    result->field1DC = value;
    return result;
}
