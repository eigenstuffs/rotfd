#include "game_curve.h"

typedef struct {
    unsigned char header_00[4];
    unsigned char scalar_04[8];
    Curve_801AC7FC block_0c;
    Curve_801AC7FC block_1c;
    Curve_801AC7FC block_2c;
    Curve_801AC7FC block_3c;
} Object_801AC7FC;

typedef struct {
    unsigned char reserved_00[0xb4];
    float scalar_b4;
    float scalar_b8;
    unsigned char reserved_bc[0x60];
    float scalar_11c;
    float scalar_120;
} Target_801AC7FC;

typedef struct {
    Target_801AC7FC *target_00;
    unsigned char reserved_04[8];
    signed char tag_0c;
    unsigned char reserved_0d[3];
} Entry_801AC7FC;

typedef struct {
    unsigned char reserved_00[8];
    Entry_801AC7FC *entries_08;
} Descriptor_801AC7FC;

typedef struct {
    signed int tag : 8;
    signed int index : 24;
} Handle_801AC7FC;

extern struct {
    unsigned char reserved_00[0x118];
    Descriptor_801AC7FC *descriptor_118;
} lbl_801E9D24;
void fn_801B41F4(void *, Object_801AC7FC *, unsigned char **);
unsigned char *fn_801E9F40(void *, unsigned char *, int);
void fn_801B2354(void *, unsigned char **);
int fn_801B0AA0(Curve_801AC7FC *, float *, int, float);

void fn_801AC7FC(Object_801AC7FC *object, unsigned char **cursor)
{
    fn_801B41F4(lbl_801E9D24.descriptor_118, object, cursor);
    *cursor = fn_801E9F40(object->scalar_04, *cursor, 2);
    fn_801B2354(&object->block_0c, cursor);
    fn_801B2354(&object->block_1c, cursor);
    fn_801B2354(&object->block_2c, cursor);
    fn_801B2354(&object->block_3c, cursor);
}

void fn_801AC88C(Object_801AC7FC *object, Handle_801AC7FC *handle, float value)
{
    Entry_801AC7FC *entry =
        &lbl_801E9D24.descriptor_118->entries_08[handle->index];
    Target_801AC7FC *target;

    if (entry->tag_0c == handle->tag)
        target = entry->target_00;
    else
        target = 0;

    if (object->block_0c.count_04) {
        float result;
        fn_801B0AA0(&object->block_0c, &result, 1, value);
        target->scalar_120 = result;
    }
    if (object->block_1c.count_04) {
        float result;
        fn_801B0AA0(&object->block_1c, &result, 1, value);
        target->scalar_11c = result;
    }
    if (object->block_2c.count_04) {
        float result;
        fn_801B0AA0(&object->block_2c, &result, 1, value);
        target->scalar_b8 = result;
    }
    if (object->block_3c.count_04) {
        float result;
        fn_801B0AA0(&object->block_3c, &result, 1, value);
        target->scalar_b4 = result;
    }
}
