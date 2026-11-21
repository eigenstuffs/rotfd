/* Include the fixed header and a full alignment step, even when aligned. */
struct AllocationOwner_802781AC {
    char unknown00[8];
    unsigned int bytes08;
    char unknown0C[0x3AC];
    unsigned int alignment;
    char unknown3BC[0x58];
    unsigned int bytes414;
    char unknown418[4];
    unsigned int bytes41C;
};
extern "C" int fn_802781AC(const AllocationOwner_802781AC* self,
    unsigned int* result)
{
    unsigned int size = 0x44 + self->bytes08 + self->bytes414 + self->bytes41C;
    *result = size + (self->alignment - (size & (self->alignment - 1)));
    return 0;
}
