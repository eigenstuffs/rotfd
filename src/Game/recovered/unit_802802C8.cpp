typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3 operator*(float s)const{float c=z*s;float b=y*s;float a=x*s;return Vec3(a,b,c);}Vec3 scaled(float s)const{float a=x*s;float b=y*s;return Vec3(a,b,s=z*s);}Vec3&operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;return *this;}};
struct Matrix{float m[4][4];};
inline Vec3 operator*(const Matrix&m,const Vec3&p){
 float y=m.m[3][1]+(m.m[0][1]*p.x+m.m[1][1]*p.y+m.m[2][1]*p.z);
 float z=m.m[3][2]+(m.m[0][2]*p.x+m.m[1][2]*p.y+m.m[2][2]*p.z);
 float x=m.m[3][0]+(m.m[0][0]*p.x+m.m[1][0]*p.y+m.m[2][0]*p.z);
 return Vec3(x,y,z);}
struct RawHandle{union{Word word;struct{int tag:8,index:24;}bits;};};
struct Geometry;struct Object;
struct GeometryEntry{Geometry*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char generation()const{return tag;}};
struct ObjectEntry{Object*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char generation()const{return tag;}};
struct GeometryManager{Word unknown00[2];GeometryEntry*entries;};
struct ObjectManager{Word unknown00[2];ObjectEntry*entries;};
struct Pool{Matrix*pages[6];unsigned char active;};
struct Related{int unknown00[2];RawHandle*handles;int unknown0C[2];};
struct RelatedOwner{char unknown00[0xB8];Related*related;};
extern "C" struct Global{char unknown00[0x118];union{GeometryManager*geometry;ObjectManager*object;};char unknown11C[0x18];Pool*pool;char unknown138[12];RelatedOwner*relatedOwner;}lbl_801E9D24;
extern "C"{
void fn_801F230C(Matrix*,Matrix*);void fn_801F1080(Matrix*,const Matrix*,Matrix*);
}
inline Geometry*resolveGeometry(const RawHandle&h){int index=h.bits.index;GeometryManager*m=lbl_801E9D24.geometry;int tag=m->entries[index].generation();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Object*resolveObject(const RawHandle&h){int index=h.bits.index;ObjectManager*m=lbl_801E9D24.object;int tag=m->entries[index].generation();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Matrix product(Matrix&a,const Matrix&b){Matrix m;fn_801F1080(&a,&b,&m);return m;}
struct Object{char unknown00[0x120];Word flags;Matrix*matrix,*inverse;short matrixIndex,inverseIndex;Matrix*getInverse(){if(flags&0x20){inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+inverseIndex;fn_801F230C(matrix,inverse);flags&=~0x20;}return inverse;}};
struct Geometry{char unknown00[0x7C];Vec3*positions;};
struct Scene{char unknown00[0x28];RawHandle*objects;char unknown2C[0x10];int relatedIndex;};
struct Weight{int index;float weight;};
struct GroupRecord{short slot;char unknown02[2];int count;Word unknown08;Weight*data;Word flag;Word unknown14,word18;};
struct Group{int object,count,capacity;GroupRecord*items;int find(int slot){for(int i=0;i<count;++i)if(items[i].slot==slot)return i;return -1;}};
struct Split{int unknown00[2];int*counts;int unknown0C[3];};
struct Owner;struct Group;inline Group*groupAt(Owner*self,int i);struct Owner{char unknown00[0x74];int groupCount,groupCapacity;Group*groups;Split*split(int i){return &splits[i];}Split&splitRef(int i){return splits[i];}Split*splitC(const int&i){return &splits[i];}Split*splitS(short i){return &splits[i];}Split*splitU(unsigned i){return &splits[i];}Split*split2(int i){int k=i;return &splits[k];}Group*group(int i){return &groups[i];}Group&groupRef(int i){return groups[i];}int count,capacity;RawHandle*handles;char unknown8C[0x14];Split*splits;};
struct Context{char unknown00[0xBDC];Vec3*positions;};

inline Group*groupAt(Owner*self,int i){return &self->groups[i];}
extern "C" void fn_802802C8(Owner*self,Context*ctx,Scene*scene,int slot){
    Vec3*out=ctx->positions;
    Geometry*geometry=resolveGeometry(self->handles[slot]);
    Related*related=lbl_801E9D24.relatedOwner->related+scene->relatedIndex;
    int count=self->groupCount;
    for(int i=0;i<count;i++){
        Group*g=self->group(i);
        int found=g->find(slot);
        if(found>=0){
            Split*split=self->splitU(i);
            Object*local=resolveObject(scene->objects[g->object]);
            Object*parent=resolveObject(related->handles[g->object]);
            Matrix m;
            m=product(*local->matrix,*parent->getInverse());
            int n=split->counts[found];
            int j=0;
            GroupRecord*r=&g->items[found];
            Weight*w=r->data;
            int total=r->count;
            for(;j<n;j++,w++){
                out[w->index]=(m*geometry->positions[w->index])*w->weight;
            }
            total=g->items[found].count;
            for(;j<total;j++,w++){
                Vec3 t=(m*geometry->positions[w->index]).scaled(w->weight);Vec3&o=out[w->index];o+=t;
            }
        }
    }
}
