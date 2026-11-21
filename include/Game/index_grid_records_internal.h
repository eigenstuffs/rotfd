#ifndef GAME_INDEX_GRID_RECORDS_INTERNAL_H
#define GAME_INDEX_GRID_RECORDS_INTERNAL_H
struct IndexGridRecord {int previous,next,chain,cell;void*context;};
struct IndexGridIntArray{int count,capacity;int*data;int&operator[](unsigned int i){return data[i];}};
struct IndexGridRecordArray{int count,capacity;IndexGridRecord*data;IndexGridRecord&operator[](unsigned int i){return data[i];}};
struct IndexGridView {
    char unknown0[0x18];int columns,unknown1C,freeHead,freeCount;
    IndexGridIntArray cellHeads;IndexGridRecordArray records;
};
struct IndexGridBounds {int x0,y0,x1,y1;};
#endif
