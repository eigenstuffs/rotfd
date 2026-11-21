/* Random record grid reset; see docs/notes/game-early-random-record-grid.md. */
#include "Game/early_random_record_grid_views.h"
extern "C" void fn_800A85AC(RandomGrid*self){
 self->flag1978=0;self->flag1979=0;self->value=lbl_80378FD4;self->index=0;
 assign(self->handle34,Handle_80020834());
 float y=lbl_80378FD8,w=lbl_80378FDC;int index=0;
 for(int row=0;row<20;row++){
  for(int column=0;column<20;column++){
   self->records[index].x=lbl_80378FE0*fn_801F1200();
   self->records[index].x-=lbl_80378FE4*fn_801F1200();
   self->records[index].y=y;self->records[index].y-=lbl_80378FE4*fn_801F1200();
   self->records[index].z=lbl_80378FEC*fn_801F1200()+lbl_80378FE8;
   self->records[index].w=w*fn_801F1200();index++;
  }
  y-=lbl_80378FE4;w+=lbl_80378FF0;
 }
 assign(self->handle1980,fn_802631B0(lbl_801E9D24.scope,GridName(lbl_8029EDF0)));
 fn_80239A7C(resolveGrid(self->handle1980));fn_802397E0(resolveGrid(self->handle1980));
}
