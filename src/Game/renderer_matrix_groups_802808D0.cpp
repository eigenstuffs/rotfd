// Partial text split: fn_802808D0 and fn_80280EC4 (renderer matrix groups).
// fn_802802C8 before them (98.1%: saved-register colouring in the weight
// transform) remains original code; best full draft:
// scratch/claude_match/auto_03_802802C8_text/all3_best.cpp.
typedef unsigned long Word;
struct Matrix{Word words[16];};
struct Matrix34{Word words[12];};
struct Handle_801F7F10 {union{Word word;struct{int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct RawHandle{union{Word word;struct{int tag:8,index:24;}bits;};};
struct Geometry;struct Material;struct Object;
struct GeometryEntry{Geometry*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char generation()const{return tag;}};
struct MaterialEntry{Material*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char generation()const{return tag;}};
struct ObjectEntry{Object*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char generation()const{return tag;}};
struct GeometryManager{Word unknown00[2];GeometryEntry*entries;};
struct MaterialManager{Word unknown00[2];MaterialEntry*entries;};
struct ObjectManager{Word unknown00[2];ObjectEntry*entries;};
struct Pool{Matrix*pages[6];unsigned char active;};
struct Related{int unknown00[2];RawHandle*handles;int unknown0C[2];};
struct RelatedOwner{char unknown00[0xB8];Related*related;};
extern "C" struct Global{char unknown00[0x118];union{GeometryManager*geometry;MaterialManager*material;ObjectManager*object;};char unknown11C[0x18];Pool*pool;char unknown138[12];RelatedOwner*relatedOwner;}lbl_801E9D24;
extern "C"{
void fn_801F86C8(void*,const void*,short);void fn_801F230C(Matrix*,Matrix*);void fn_801F1080(Matrix*,const Matrix*,Matrix*);void fn_800F22F4(void*,int);void GXDrawDone();extern char lbl_80341360[],lbl_8034D360[],lbl_80359360[];
void fn_800F2320(void*,int);void fn_80280158(void*,int);void fn_801F0EFC(Matrix*,Matrix34*);void fn_8027FF4C(Matrix34*,void*,void*,void*,int,Word,void*,void*,Word);void fn_802800A8(Matrix34*,void*,void*,void*,int);
}
struct Zero1:Handle_801F7F10{Zero1(){word=0;}};struct Zero2:Zero1{Zero2(){word=0;}};struct Zero3:Zero2{Zero3(){word=0;}};
struct Zero4:Zero3{Zero4(){word=0;}};struct CopyHandle:Zero4{CopyHandle(const RawHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.geometry,&h,1);}};
inline Geometry*resolveGeometry(const RawHandle&h){int index=h.bits.index;GeometryManager*m=lbl_801E9D24.geometry;int tag=m->entries[index].generation();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Material*resolveMaterial(const RawHandle&h){int index=h.bits.index;MaterialManager*m=lbl_801E9D24.material;int tag=m->entries[index].generation();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Object*resolveObject(const RawHandle&h){int index=h.bits.index;ObjectManager*m=lbl_801E9D24.object;int tag=m->entries[index].generation();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Matrix product(Matrix&a,const Matrix&b){Matrix m;fn_801F1080(&a,&b,&m);return m;}
struct Object{char unknown00[0x120];Word flags;Matrix*matrix,*inverse;short matrixIndex,inverseIndex;void setMatrix(const Matrix&m){matrix=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+matrixIndex;*matrix=m;flags|=0x20;}Matrix*getInverse(){if(flags&0x20){inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+inverseIndex;fn_801F230C(matrix,inverse);flags&=~0x20;}return inverse;}};
struct Context;struct Scene;
struct Prefix{Word unknown00[2];};
struct Geometry:Prefix{
virtual void slot008();virtual void slot00C();virtual void slot010();virtual void slot014();virtual void slot018();virtual void slot01C();virtual void slot020();virtual void slot024();virtual void slot028();virtual void slot02C();virtual void slot030();virtual void slot034();virtual void slot038();virtual void slot03C();virtual void slot040();virtual void slot044();virtual void slot048();virtual void slot04C();virtual void slot050();virtual int count();virtual void draw(Context*,Material*,void*,void*);virtual void slot05C();virtual void drawMatrix(Context*,Material*,void*);
char unknown0C[0x60];unsigned short kind;char unknown6E[6];int vertices;Word unknown78;void*positions;char unknown80[0x14];void*normals;char unknown98[0x2C];void*otherNormals;
};
struct Material:Prefix{virtual void slot008();Word flags;};
struct Scene:Prefix{virtual void slot008();virtual void slot00C();virtual void slot010();virtual void slot014();virtual void slot018();virtual void slot01C();virtual void slot020();virtual void slot024();virtual void slot028();virtual void slot02C();virtual void slot030();virtual void apply(Context*);char unknown0C[0x1C];RawHandle*objects;char unknown2C[4];char other30[0xC];int relatedIndex;char unknown40[0x2C];RawHandle*materials;};
struct GroupRecord{short slot;char unknown02[2];int count;Word unknown08;void*data;Word flag;Word unknown14,word18;};
struct Group{int object,count,capacity;GroupRecord*items;int find(int slot){for(int i=0;i<count;++i)if(items[i].slot==slot)return i;return -1;}};
struct OwnerPair{int first,second;};
struct Owner{char unknown00[0x74];int groupCount,groupCapacity;Group*groups;int count,capacity;RawHandle*handles;int pairCount,pairCapacity;OwnerPair*pairs;};
struct Context{void*renderer;Word unknown04[2];Object*parent,*object;void*unknown14;Geometry*geometry;Word unknown1C;Matrix matrix;char unknown60[0xB78];void*normals;void*positions;void setMatrix(const Matrix&m){matrix=m;}};
extern "C"void fn_80272708(void*,void*);

extern "C" void fn_802808D0(Owner*self,Context*ctx,Scene*scene,int slot){
    Group*g;
    int off=0;
    void*positions;
    Object*parent;
    Object*local;
    Matrix copied;
    int n;
    Related*related;
    int i;
    GroupRecord*r;
    int found;
    void*sourceNormals;
    int count;
    int vertices;
    void*normals;
    void*sourcePositions;
    Matrix34 result;
    Geometry*geometry;
    positions=ctx->positions;
    normals=ctx->normals;
    geometry=resolveGeometry(self->handles[slot]);
    vertices=geometry->vertices;
    sourcePositions=geometry->positions;
    related=lbl_801E9D24.relatedOwner->related+scene->relatedIndex;
    fn_800F2320(sourcePositions,vertices*12);
    fn_80280158(positions,vertices);
    sourceNormals=0;
    switch(geometry->kind){case 6:sourceNormals=geometry->normals;break;case 1:sourceNormals=geometry->otherNormals;break;}
    if(sourceNormals){
        n=geometry->count();
        fn_800F2320(sourceNormals,n*12);
        fn_80280158(normals,n);
        count=self->groupCount;
        for(i=0,off=0;i<count;off+=16,i++){
            g=(Group*)((char*)self->groups+off);
            found=g->find(slot);
            if(found>=0){
                local=resolveObject(scene->objects[g->object]);
                parent=resolveObject(related->handles[g->object]);
                copied=product(*local->matrix,*parent->getInverse());
                fn_801F0EFC(&copied,&result);
                r=&g->items[found];
                fn_8027FF4C(&result,r->data,sourcePositions,positions,r->count,r->word18,sourceNormals,normals,r->flag);
            }
        }
    }else{
        count=self->groupCount;
        for(i=0,off=0;i<count;off+=16,i++){
            found=((Group*)((char*)self->groups+off))->find(slot);
            if(found>=0){
                Group*g2=(Group*)((char*)self->groups+off);
                local=resolveObject(scene->objects[g2->object]);
                parent=resolveObject(related->handles[g2->object]);
                copied=product(*local->matrix,*parent->getInverse());
                fn_801F0EFC(&copied,&result);
                r=&g2->items[found];
                fn_802800A8(&result,r->data,sourcePositions,positions,r->count);
            }
        }
    }
}

extern "C" void fn_80280EC4(Owner*self,Context*ctx,Scene*scene){
    void*renderer;
    int i;
    Geometry*g;
    Material*m;
    Matrix saved;
    Object*savedObject;
    Group*group;
    Geometry*g2;
    Matrix savedMatrix;
    renderer=*(void**)((char*)ctx->renderer+0x48);
    if(ctx->geometry)fn_80272708(renderer,(char*)ctx->geometry+0x74);
    ctx->positions=lbl_80341360;
    ctx->normals=lbl_8034D360;
    for(i=0;i<self->count;++i){
        g=resolveGeometry(self->handles[i]);
        m=resolveMaterial(scene->materials[i]);
        if(m&&(m->flags&1))continue;
        fn_802808D0(self,ctx,scene,i);
        fn_800F22F4(lbl_80341360,0xC000);
        fn_800F22F4(lbl_8034D360,0xC000);
        fn_800F22F4(lbl_80359360,0x4000);
        g->draw(ctx,m,scene->other30,lbl_80359360);
        GXDrawDone();
    }
    scene->apply(ctx);
    saved=ctx->matrix;
    savedObject=ctx->object;
    for(i=0;i<self->pairCount;++i){
        group=&self->groups[self->pairs[i].second];
        g2=resolveGeometry((const RawHandle&)CopyHandle(self->handles[self->pairs[i].first]));
        ctx->object=resolveObject(scene->objects[group->object]);
        savedMatrix=*ctx->object->matrix;
        ctx->object->setMatrix(product(*savedObject->matrix,*ctx->object->matrix));
        Matrix*om=ctx->object->matrix;
        ctx->setMatrix(product(*ctx->parent->getInverse(),*om));
        g2->drawMatrix(ctx,resolveMaterial(scene->materials[self->pairs[i].first]),scene->other30);
        ctx->object->setMatrix(savedMatrix);
    }
    ctx->matrix=saved;
    ctx->object=savedObject;
}
