/* Original engine records and resource lifetime routines.
 * See docs/notes/game-engine-records-more.md. */
extern struct {char pad[0x118];void *manager;} lbl_801E9D24;extern void fn_801B3E54(void *,void *);
void fn_801CA30C(void *object) {fn_801B3E54(lbl_801E9D24.manager,(char *)object+0xc);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x10);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x14);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x18);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x1c);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x24);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x28);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x2c);}
