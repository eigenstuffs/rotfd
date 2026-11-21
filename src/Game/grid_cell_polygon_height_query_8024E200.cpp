/* fn_8024E200: grid-cell polygon height query.  Converts the query x/z into a
 * cell of the owner's uniform grid, walks the faces listed in that cell, runs
 * an even/odd crossing test on each face's outline (vertex position chosen per
 * edge by the face's flag bits) and returns the closest face above the point
 * (height - y > 1e-6), writing its index to *out.
 *
 * Owns its whole literal pool .sdata2 0x8037B470..0x8037B488
 * (1e11f, 0.999999f, 0.0f, 1e-6f, signed int->float bias); fn_8024E200 is
 * the only reference to these labels.  Flags as for
 * curve_bezier_sampling_8024DA4C.cpp (-O4,p, exceptions off).
 *
 * Matching notes (base: scratch/game_grid_coordinate_bounds_8024e200_20261011mi
 * outer_edge_locals.cpp, 97.0%):
 * - the inner loop reads face.indices through `*(U16**)&face.indices`, a
 *   different CSE expression from getIndex(0) before the loop, so the base is
 *   reloaded each iteration instead of strength-reduced into a pointer;
 * - int mask tested as `flags & (U16)mask`;
 * - `if (dz)` gives fcmpu dz,0 operand order;
 * - crossings declared at function scope (assigned 0 per face) puts it in r12
 *   and the cell count in r31 like the original. */
typedef unsigned short U16;
struct Point { float x,y,z; };
struct Output {int index;};
template<class T> struct Array { int count,capacity; T*items; T&operator[](int i){return items[i];} };
struct Record { int first,second; char unknown08[0xF0]; };
struct Face { int count,capacity; U16*indices; char unknown0C[0xC]; U16 flags; char unknown1A[2]; float height; U16 getIndex(int i)const{return indices[i];} const int&getCount()const{return count;} };
struct Cell { int count,capacity; U16*indices; };
struct Self {
 char unknown00[0x74]; Array<Point>positions; Array<Record>records; char unknown8C[0x14]; Array<Face>faces;
 float originX,originZ; char unknownB4[8]; float scaleX,scaleZ; int cellsX,cellsZ; Array<Cell>cells; Face&getFace(U16 i){return faces.items[i];}
};

inline U16 cellIndex(float x){return x<0.0f ? (int)(x-0.999999f) : (int)x;}
inline int inside(Self*self,U16 x,U16 z){int valid=0;if(x<self->cellsX&&z<self->cellsZ)valid=1;return valid;}
inline Cell&cellAt(Self*self,float x,float z){U16 ix=cellIndex(x);U16 iz=cellIndex(z);return self->cells[ix+iz*self->cellsX];}
extern "C" signed char fn_8024E200(Self*self,const Point*point,Output*out){
 float queryX=point->x,queryZ=point->z;float nearest=100000000000.0f;signed char hit=0;int crossings;
 float x=(float)self->cellsX*(self->scaleX*(queryX-self->originX));
 U16 ix=cellIndex(x);
 float z=(float)self->cellsZ*(self->scaleZ*(queryZ-self->originZ));
 U16 iz=cellIndex(z);
 if(!inside(self,ix,iz))return 0;
 Cell&cell=cellAt(self,x,z);int count=cell.count;
 for(int i=0;i<count;++i){
  U16 faceIndex=cell.indices[i];Face&face=self->getFace(faceIndex);int mask=1;int n=face.getCount();
  int index=face.getIndex(0);int positionIndex;
  if(face.flags&1)positionIndex=self->records[index].first;else positionIndex=self->records[index].second;
  float currentX,currentZ,lowerX,lowerZ;
  const Point&previous=self->positions[positionIndex];float previousX=previous.x,previousZ=previous.z;
  crossings=0;
  for(int j=0;j<n;++j){
   int index=(*(U16**)&face.indices)[j];
   if(face.flags&(U16)mask){const Point&v=self->positions[self->records[index].second];currentX=v.x;currentZ=v.z;}
   else {const Point&v=self->positions[self->records[index].first];currentX=v.x;currentZ=v.z;}

   if(previousZ>currentZ){lowerX=currentX;lowerZ=currentZ;}
   else {lowerX=previousX;lowerZ=previousZ;previousX=currentX;previousZ=currentZ;}
   if(lowerZ<queryZ&&previousZ>=queryZ){
    if(lowerX<queryX&&previousX<queryX)++crossings;
    if((lowerX<=queryX&&previousX>=queryX)||(previousX<=queryX&&lowerX>=queryX)){
     float dz=previousZ-lowerZ;
     if(dz){float edgeX=lowerX+((queryZ-lowerZ)*(previousX-lowerX))/dz;if(edgeX<queryX)++crossings;}
    }
   }
   previousX=currentX;previousZ=currentZ;mask=(U16)(mask<<1);
  }
  if(crossings&1){float delta=face.height-point->y;if(!hit||(delta>0.000001f&&delta<nearest)){if(delta>0.000001f&&delta<nearest)nearest=delta;out->index=faceIndex;hit=1;}}
 }
 return hit;
}
