#include "Game/engine_queue_followup.h"

extern "C" void fn_8023203C(EngineFollowupRecordList *self, EngineFollowupHandleList *handles,
                            float first, float second, float third) {
    EngineFollowupWork work[64];
    __construct_array(work, fn_801C6968, 0, sizeof(EngineFollowupWork), 64);
    int count = self->count;
    EngineFollowupRecord *records = self->data;
    for (int i = 0; i < count; i++, records++) {
        if (records->index < handles->count) {
            EngineFollowupTarget *target = engineFollowupResolve(handles->data[records->index]);
            if (target) {
                int out = 0;
                fn_801AED04(records, target, work, &out, first, second, third);
            }
        }
    }
}
