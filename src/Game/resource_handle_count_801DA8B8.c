/* The handle array's signed count occupies the observed 0xBC field. */
struct ResourceHandleCountView {
    char unknown00[0xBC];
    int count;
};
int fn_801DA8B8(void* self)
{
    return ((struct ResourceHandleCountView*)self)->count;
}
