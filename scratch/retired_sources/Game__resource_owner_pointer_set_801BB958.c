/* Object association used by the fixed sphere record owner. */
struct SphereRecordObject;
struct SphereRecordOwnerView {
    char unknown00[0xB94];
    struct SphereRecordObject* object;
};
void fn_801BB958(void* self, void* object)
{
    ((struct SphereRecordOwnerView*)self)->object = object;
}
