#include "Game/engine_record_clear.h"

static inline void clearRow(struct EngineRecordClearOwner* self, struct EngineRecordClearRow* row)
{
    int j;
    for (j = 0; j < row->count; j++)
        engineRecordClearResolve(&self->targets[row->items[j]])->flags120 &= ~0x1000;
}

void fn_8024A6B4(struct EngineRecordClearOwner* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        struct EngineRecordClearNode* node = engineRecordClearResolve(&self->items[i]);
        if (node) {
            node->flags0C &= ~2;
            clearRow(self, &self->rows[i]);
        }
    }
    fn_8024A120(self, lbl_8037B438, 0);
    fn_8024C5D4(self);
}
