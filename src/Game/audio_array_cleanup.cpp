/* Audio record array cleanup; see docs/notes/game-audio-array-cleanup.md. */
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Record{char unknown00[0x2C];Record();static void operator delete[](void*p){fn_801EF610(lbl_801EF5C8,p);}};
struct Voice{char unknown00[0x30];Voice();static void operator delete[](void*p){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner{char unknown00[0xD4];Record*recordsD4;Record*recordsD8;char unknownDC[8];Voice*voicesE4;Voice*voicesE8;};
extern "C" void fn_80287BEC(Owner*self){if(self->voicesE4)delete[] self->voicesE4;if(self->voicesE8)delete[] self->voicesE8;if(self->recordsD4)delete[] self->recordsD4;if(self->recordsD8)delete[] self->recordsD8;self->voicesE8=0;self->voicesE4=0;self->recordsD8=0;self->recordsD4=0;}
