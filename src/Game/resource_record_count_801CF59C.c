/* The shared record array uses signed count and capacity fields. */
struct ResourceRecordCountView {
    char unknown00[0x8C];
    int count;
};
int fn_801CF59C(void* self)
{
    return ((struct ResourceRecordCountView*)self)->count;
}
