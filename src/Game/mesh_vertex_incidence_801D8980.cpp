/* Mesh vertex incidence collection reconstruction; see docs/notes/game-mesh-vertex-incidence.md. */
typedef unsigned long MeshVertexIncidenceWord;
extern "C"{
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,MeshVertexIncidenceWord,MeshVertexIncidenceWord);
 void*fn_8028FF24(void*,MeshVertexIncidenceWord);
 void fn_8028FD50(void*,void*,MeshVertexIncidenceWord);
}
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct MeshVertexIncidenceArray{
 int count,capacity;T*items;MeshVertexIncidenceArray():count(0),capacity(0),items(0){}
 ~MeshVertexIncidenceArray(){if(items){for(int i=0;i<count;++i)items[i].~T();if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}items=0;}}
 T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};

struct MeshVertexIncidenceVector{float x,y,z;};
struct MeshVertexIncidenceFace{char unknown00[0x58];unsigned short edges[4];MeshVertexIncidenceWord flags;char unknown64[0x2C];int edge(int i)const{return edges[i];}};
struct MeshVertexIncidenceEdge{unsigned short first,second;char unknown04[4];};
struct MeshVertexIncidenceOwner{char unknown00[0x74];MeshVertexIncidenceArray<MeshVertexIncidenceVector>vertices;char unknown80[0x24];MeshVertexIncidenceArray<MeshVertexIncidenceFace>faces;MeshVertexIncidenceArray<MeshVertexIncidenceEdge>edges;};
extern "C"void fn_801D8980(MeshVertexIncidenceOwner*self,MeshVertexIncidenceVector*out){
 MeshVertexIncidenceArray<int>counts;
 counts.resize(self->vertices.count);int i;
 for(i=0;i<counts.count;++i)counts[i]=0;
 for(i=0;i<self->faces.count;++i){
  int sides=4;if(self->faces[i].flags&1)sides=3;
  for(int j=0;j<sides;++j){
   ++counts[self->edges[self->faces[i].edge(j)].first];
   ++counts[self->edges[self->faces[i].edge(j)].second];
  }
 }
 int output=0;
 for(i=0;i<counts.count;++i)if(counts[i]==2)out[output++]=self->vertices[i];
}

typedef char MeshVertexIncidenceFaceSize[sizeof(MeshVertexIncidenceFace)==0x90?1:-1];
typedef char MeshVertexIncidenceEdgeSize[sizeof(MeshVertexIncidenceEdge)==8?1:-1];
