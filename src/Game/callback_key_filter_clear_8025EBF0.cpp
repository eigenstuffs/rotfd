// Observed prefixes of the callback list and its key arrays.
struct CallbackFilterKey {
    int key;
    unsigned int unknown04;
};
struct CallbackFilterNode {
    char unknown00[0x10];
    int count;
    unsigned int unknown14;
    CallbackFilterKey* keys;
    CallbackFilterNode* next;
    char unknown20[8];
    unsigned short flags;
    unsigned short state;
    int getCount() const { return count; }
};
struct CallbackFilterOwner {
    char unknown00[0x10];
    CallbackFilterNode* first;
};
struct CallbackFilterArray {
    int count;
    unsigned int unknown04;
    int* keys;
    int getCount() const { return count; }
};
extern "C" void fn_8025EBF0(CallbackFilterOwner* self, CallbackFilterArray* filter) {
    int filterCount = filter->getCount();
    CallbackFilterNode* node = self->first;
    if (filterCount == 0) {
        while (node) {
            node->flags &= ~7;
            node->state = 0;
            node = node->next;
        }
    } else {
        while (node) {
            int count = node->getCount();
            signed char clear = 1;
            for (int i = 0; i < count; ++i) {
                for (int j = 0; j < filterCount; ++j) {
                    if (filter->keys[j] == node->keys[i].key) {
                        clear = 0;
                        break;
                    }
                }
            }
            if (clear) {
                node->flags &= ~7;
                node->state = 0;
            }
            node = node->next;
        }
    }
}
