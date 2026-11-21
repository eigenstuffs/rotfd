#include "menu_item_text_internal.h"
extern "C" int fn_80218874(MenuItemTextView*self,int index,char*output) {
    u32 arguments[8];
    MenuItem* item;
    for(int i=0;i<(item=&self->items[index])->parameterCount;i++) {
        arguments[i]=self->resolver.get()->slot70(
            item->keyword,item->parameters[i]);
    }
    return fn_801F44DC(output,item->name,arguments);
}
