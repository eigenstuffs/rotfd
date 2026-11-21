struct SpatialHandle{signed int generation:8;signed int index:24;};struct SpatialPoint{float x,y,z;};struct SpatialSphere{float x,y,z,radius;SpatialSphere(){}SpatialSphere(const SpatialPoint&v,float r):x(v.x),y(v.y),z(v.z),radius(r){}SpatialSphere&operator=(const SpatialSphere&v){x=v.x;y=v.y;z=v.z;radius=v.radius;return *this;}};struct SpatialResource{char unknown00[0xC];SpatialSphere bounds;char unknown1C[0x50];unsigned short type,flags;};struct SpatialCell{char unknown00[0x10];};struct SpatialObject{char unknown00[0x20];SpatialHandle parent;char unknown24[0xA0];int firstIndex;char unknownC8[0x1C];int secondIndex;char unknownE8[8];SpatialCell firstCell,secondCell;char unknown110[0x10];unsigned long flags;void*matrix;};
struct SpatialStorage{char unknown00[8];};struct SpatialParent:SpatialStorage{
virtual void slot8();
virtual void slotC();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual const SpatialSphere*getBounds();
};struct SpatialEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct SpatialManager{char unknown00[8];SpatialEntry*entries;};extern "C"{extern struct{char unknown00[0x118];SpatialManager*manager;}lbl_801E9D24;extern const SpatialPoint game_vec4_zero;extern const float lbl_8037B330;SpatialSphere fn_80099A00(const void*,const SpatialSphere*);signed char fn_80266FF8(void*,int,const SpatialSphere*,SpatialCell*);void fn_8026736C(void*,int);int fn_80267248(void*,void*,SpatialCell*);}
inline char*resolveSpatial(const SpatialHandle&h){int index=h.index;SpatialManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void updateSpatialCell(void*grid,SpatialObject*self,SpatialSphere&sphere,int&index,SpatialCell&cell){if(fn_80266FF8(grid,index,&sphere,&cell)){if(index!=-1)fn_8026736C(grid,index);index=fn_80267248(grid,self,&cell);}}
inline SpatialSphere worldSpatialSphere(const void*matrix,const SpatialSphere&sphere){return fn_80099A00(matrix,&sphere);}
struct SpatialGrid{char unknown00[0x4044];};struct SpatialGrids{char unknown00[0x34];SpatialGrid primary,special,secondary;SpatialGrid&getPrimary(){return primary;}SpatialGrid&getSpecial(){return special;}SpatialGrid&getSecondary(){return secondary;}};
extern "C" void fn_8023F90C(SpatialObject*self,SpatialGrids*grid,const SpatialResource*resource){if(resource){SpatialSphere sphere(game_vec4_zero,lbl_8037B330);int type=resource->type;if(type==0x12)sphere=*(((SpatialParent*)resolveSpatial(self->parent))->getBounds());else sphere=fn_80099A00(self->matrix,&resource->bounds);if(type==0x10)updateSpatialCell(&grid->getSpecial(),self,sphere,self->firstIndex,self->firstCell);else{int flags=resource->flags;if(!(flags&0x10))updateSpatialCell(&grid->getPrimary(),self,sphere,self->firstIndex,self->firstCell);if(!(self->flags&0x8000)&&!(flags&0x20))updateSpatialCell(&grid->getSecondary(),self,sphere,self->secondIndex,self->secondCell);}}else{SpatialSphere sphere=worldSpatialSphere(self->matrix,SpatialSphere(game_vec4_zero,lbl_8037B330));updateSpatialCell(&grid->getSecondary(),self,sphere,self->secondIndex,self->secondCell);}}
