/* The pointee layout is opaque; the native getter exposes its first byte. */
struct ResourceEmbeddedAddressView {
    char unknown00[0x10];
    unsigned char member10;
};
void* fn_801CC758(void* self)
{
    return &((struct ResourceEmbeddedAddressView*)self)->member10;
}
