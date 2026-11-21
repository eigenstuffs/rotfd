/* Partial observed state: resetting the word at+78 reports success. */
struct ResetState { unsigned char unknown00[0x78]; unsigned int state; };
int fn_801BC98C(struct ResetState* self) { self->state=0; return 1; }
