struct NeighborGridNode {
    char unknown00[0x92];
    short index;
    char unknown94[4];
    signed char active;

    int getIndex() const { return index; }
};

struct NeighborGridRecord {
    short index;
    char unknown02[2];
    NeighborGridNode* node;
    char unknown08[12];
};

struct NeighborGrid {
    char unknown00[0x60];
    short width;
    char unknown62[4];
    short count;
    short neighbor;
    char unknown6A[10];
    NeighborGridRecord records[1];
};

extern "C" int fn_80072468(NeighborGrid* object, const NeighborGridNode* node)
{
    int index, left, right, up, down;

    if (node->active)
        return 0;

    object->neighbor = -1;
    index = node->getIndex();

    left = index - 1;
    if (left >= 0 && index % object->width != 0 && object->records[left].node->active) {
        object->neighbor = left;
        return 1;
    }

    right = index + 1;
    if (right % object->width != 0 && object->records[right].node->active) {
        object->neighbor = right;
        return 1;
    }

    up = index - object->width;
    if (up >= 0 && object->records[up].node->active) {
        object->neighbor = up;
        return 1;
    }

    down = index + object->width;
    if (down < object->count && object->records[down].node->active) {
        object->neighbor = down;
        return 1;
    }

    return 0;
}
