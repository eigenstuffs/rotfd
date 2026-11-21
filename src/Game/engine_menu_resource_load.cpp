#include "Game/engine_menu_resource_load.h"

extern "C" signed char fn_8021CB30(MenuLoader* self, const void* key)
{
    MenuLoadHandle handle(lbl_801E9D24.manager->lookup(key));
    if (!fn_801F7EB8(&handle))
        return 0;

    void* stream = (char*)menuLoadResolve(handle) + 0xC;
    unsigned short value = 0;
    char token[128], name[128];
    fn_801F372C(stream, token);
    strcpy(name, lbl_8037B020);
    while (!fn_801F2E04(stream)) {
        if (!strcmp(token, lbl_8037B028)) {
            fn_801F3238(stream, &value);
            self->field44 = value;
        }
        if (!strcmp(token, lbl_8037B030))
            fn_801F2F54(stream, name);
        if (!strcmp(token, lbl_8037B038))
            fn_8021C7F4(self, stream);
        if (!strcmp(token, lbl_802AE90C)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037B008))
                self->field48 = 1;
        }
        fn_801F372C(stream, token);
    }

    MenuName groupName(name);
    int index = fn_8026BC50(lbl_801E9D24.groups, &groupName);
    const u32& group = lbl_801E9D24.groups->handles[index];
    fn_801F86C8(lbl_801E9D24.manager, &self->group, -1);
    self->group = group;
    fn_801F86C8(lbl_801E9D24.manager, &group, 1);
    self->mode = 2;
    self->finish(0);
    return 1;
}
