#include "Game/index_grid_records_internal.h"
extern "C" int fn_802672CC(IndexGridView*,int,int,void*);
extern "C" int fn_80267248(IndexGridView*self,void*context,IndexGridBounds*bounds){
    int previous=-1;
    for(int y=bounds->y0;y<bounds->y1;++y){
        for(int x=bounds->x0;x<bounds->x1;++x){
            previous=fn_802672CC(self,x+y*self->columns,previous,context);
        }
    }
    return previous;
}
