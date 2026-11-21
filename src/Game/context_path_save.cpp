struct PathContextView { char unknown00[0x868]; const char* name; };
extern "C" {
extern const char lbl_8037B5D0[5], lbl_802AEF74[];
extern struct { char unknown00[0x110]; PathContextView* context; char unknown114[0x38]; void* paths; } lbl_801E9D24;
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
void fn_80262AFC(void*, const char*);
}
extern "C" void fn_80262428()
{
    char path[128];
    strcpy(path, lbl_8037B5D0);
    strcat(path, lbl_801E9D24.context->name);
    strcat(path, lbl_802AEF74);
    fn_80262AFC(lbl_801E9D24.paths, path);
}
