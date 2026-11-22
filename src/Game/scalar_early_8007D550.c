struct State {const void *vtable;unsigned char enabled,mode;char pad6[2];unsigned int words[10];};

extern const char lbl_802B8448[];

void fn_8007D550(struct State *object) {object->vtable=lbl_802B8448;object->enabled=0;object->mode=0;object->words[0]=0;object->words[1]=~0U;object->words[2]=0;object->words[5]=0;object->words[4]=0;object->words[7]=0;object->words[6]=0;object->words[8]=0;object->words[9]=0;}
