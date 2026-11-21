/* Resource indices use the existing unsigned-short invalid value 0xFFFF. */
struct ResourceIndexView {
    char unknown00[0x20];
    unsigned short index;
};
void fn_801CDB34(void* self, unsigned short index)
{
    ((struct ResourceIndexView*)self)->index = index;
}
