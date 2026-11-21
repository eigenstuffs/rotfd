/* Camera target forward yaw (fn_80077BDC): resolves the camera's target
   handle (+0x24), asks it (virtual slot 0x9C) for its node handle, resolves
   that node and rotates the axis (0, 0, lbl_803789E4) by the node's 3x3
   rotation rows at +0x30, writes the result to *out and returns the scaled
   atan2 (fn_80285124) of its z/x components, or 0 when both are zero.
   Sibling of fn_80077D28, which uses the axis factor lbl_803789A8.

   Every zero and the axis factor are the original translation unit's pooled
   literals, now the shared labels lbl_8037899C and lbl_803789E4. The original
   literal was loaded once per use and the back end merged the loads, numbering
   the shared register after the later use; plain label reads are merged by the
   front end into one early temporary, which rotates the f6/f7/f8 assignment.
   Reading the y component's m[0][1] zero and m[2][1] factor through a pointer
   keeps those loads distinct, as with the literals. */
struct Vec3 {
    float x, y, z;
};

struct QueryHandle {
    union {
        unsigned long value;
        struct {
            signed int tag : 8;
            signed int index : 24;
        } bits;
    };
};

struct QueryPrefix {
    char unknown00[8];
};

struct QueryNode : QueryPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual const QueryHandle* getNodeHandle(int);
    char unknown0C[0x24];
    float matrix[3][3];
};

struct QueryEntry {
    QueryNode* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct QueryManager {
    int count, capacity;
    QueryEntry* entries;
};

struct QueryContext {
    char unknown00[0x118];
    QueryManager* manager;
};

extern "C" QueryContext lbl_801E9D24;

inline QueryNode* resolveQuery(const QueryHandle& h)
{
    QueryEntry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag)
        return entry->object;
    return 0;
}

struct QueryCamera {
    char unknown00[0x24];
    QueryHandle target;
};

extern "C" {
float fn_80285124(float, float);
extern const float lbl_8037899C, lbl_803789E4, lbl_803789EC;
}

extern "C" float fn_80077BDC(QueryCamera* self, Vec3* out)
{
    QueryNode* node = resolveQuery(*resolveQuery(self->target)->getNodeHandle(0));
    float x = node->matrix[0][0] * lbl_8037899C + node->matrix[1][0] * lbl_8037899C +
              node->matrix[2][0] * lbl_803789E4;
    float y = node->matrix[0][1] * *(const float*)&lbl_8037899C + node->matrix[1][1] * lbl_8037899C +
              node->matrix[2][1] * *(const float*)&lbl_803789E4;
    float z = node->matrix[0][2] * lbl_8037899C + node->matrix[1][2] * lbl_8037899C +
              node->matrix[2][2] * lbl_803789E4;
    out->x = x;
    out->y = y;
    out->z = z;
    float angle = lbl_8037899C;
    if (lbl_8037899C != out->z || lbl_8037899C != out->x)
        angle = lbl_803789EC * fn_80285124(out->z, out->x);
    return angle;
}
