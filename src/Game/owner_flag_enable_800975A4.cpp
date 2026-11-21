/* Enable the nested object's 0x20000 flag. */
struct Nested {
    char unknown00[0x38];
    unsigned long long flags;
};
struct Owner {
    char unknown00[0xC];
    Nested* nested;
};
extern "C" void fn_800975A4(Owner* self)
{
    self->nested->flags |= 0x20000;
}
