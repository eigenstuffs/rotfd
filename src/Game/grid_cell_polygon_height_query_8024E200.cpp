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
