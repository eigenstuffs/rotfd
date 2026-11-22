struct IndexManager {char pad[8];void *entries;};extern struct {char pad[0x130];struct IndexManager *manager;} lbl_801E9D24;

void fn_801CDB3C(void *object) {unsigned short index=*(unsigned short *)((char *)object+0x20);if(index!=65535) ((unsigned short *)lbl_801E9D24.manager->entries)[(index+1)*6+2]=65535;*(unsigned short *)((char *)object+0x20)=65535;}
