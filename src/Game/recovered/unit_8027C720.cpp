#include "recovered/w3_7_render.h"
// fn_8027C720: per-part lit model draw (sibling of fn_8028298C). Matching notes:
//  - declaration order at the top fixes the callee-saved colouring (idx first, then count, res, ctx, lod, mode,
//    material, bestIdx, start, i); each loop has its own counter (a, k, i, b2, c) so no web is renamed to a temp.
//  - material is assigned in both arms of an explicit if/else (a ?: temp would replace the named variable).
//  - radius scaling lives in the function-level local rr (rr*=1.75); loop A reads the constant through a
//    non-const cast so that the hoist is done by the backend (the original used a literal 1.75).
//  - eye pointer comes from an inline with a local (frontend temp -> spill slot order).
#define REACHK(rec,b,K) (rr=rec->radius,rr*=K,sub2(rec,b,rr))
#define REACH(rec,b) REACHK(rec,b,lbl_8037B7A0)
inline bool sub2(const LightRec*l,const Bounds*b,float r){float limit=r+b->radius;return (l->pos-b->center).lengthSquared()<limit*limit;}
inline Texture*resolveTexture(const Handle&h){return (Texture*)resolve(h);}
inline signed char isTranslucent(Material*m){
 if(fn_801F7EB8(&m->texture74)&&resolveTexture(m->texture74)->format3F==2)return 1;
 if(m->alpha18<lbl_8037B79C)return 1;
 if(m->flags68&8)return 1;
 return 0;}
inline Vec3*eyeOf(Owner8*o){Vec3*p;p=&o->eye74;return p;}
struct CacheX:CacheBase{virtual u16 allocate(Handle*,u16);
 void touch(int n){n=n;CacheNode&q=nodes[n];nodes[q.prev].next=q.next;nodes[nodes[n].next].prev=nodes[n].prev;nodes[n].next=nodes[0].next;nodes[n].prev=0;nodes[nodes[0].next].prev=n;nodes[0].next=n;}
 VertexBuffer*buffer(int slot){return &buffers[slot*stride];}
 VertexBuffer*acquire(int slot){touch(slot+1);return buffer(slot);}};
#define CX ((CacheX*)r->cacheBE0)
inline Vec3 xformF(const Matrix*m,const Vec3&p){float pz=p.z;float py=p.y;float px=p.x;
 float y=m->m[3][1]+(m->m[0][1]*px+m->m[1][1]*py+m->m[2][1]*pz);
 float x=m->m[3][0]+(m->m[0][0]*px+m->m[1][0]*py+m->m[2][0]*pz);
 float z=m->m[3][2]+(m->m[0][2]*px+m->m[1][2]*py+m->m[2][2]*pz);
 return Vec3(x,y,z);}
inline Vec3 xformC(const Matrix*m,const Vec3&p){
 float y=m->m[3][1]+(m->m[0][1]*p.x+m->m[1][1]*p.y+m->m[2][1]*p.z);
 float x=m->m[3][0]+(m->m[0][0]*p.x+m->m[1][0]*p.y+m->m[2][0]*p.z);
 float z=m->m[3][2]+(m->m[0][2]*p.x+m->m[1][2]*p.y+m->m[2][2]*p.z);
 return Vec3(x,y,z);}
inline void*resolveIn(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];void*q;if(e->tag==h.tag)q=e->object;else q=0;return q;}
inline void*resolve3(const Handle_801F7F10&h){return resolveIn(*(const Handle*)&h);}
extern "C" void fn_8027C720(Model*model,Renderer*r,Source*source,BoundsArray*bounds,StateArray*states){
    int idx;int count;Resource*res;Context*ctx;u8 lod;u16 mode;Material*material;int bestIdx;int start;int i;int a;int b2;int c;int k;VertexBuffer*vb;float scale;float s;float best;float rr;Matrix*world;int j;int parts;signed char fog;
    res=r->res10;
    world=res->getWorld();
    lod=r->lodBCC;
    ctx=r->record0->context48;
    Vec3*eye=eyeOf(r->owner8);
    if(lod>model->maxLod114)model->maxLod114=lod;
    if(model->flags6E&4)model->v5C();
    count=r->lightCount;
    r->lightCountAC4=count;
    scale=lbl_8037B79C/getScale(res->local124);
    for(a=0;a<count;a++){
        s=scale*getScale(r->lights[(unsigned long)a]->local124);
        Parent*p=(Parent*)resolve3(LightCopy((*(Resource**)((char*)r->lights+(unsigned)a*4))->parent1C));
        LightRec*rec=(LightRec*)((char*)r->lightRecs+(unsigned)a*0x24);
        rec->pos=xformC(world,(*(Resource**)((char*)r->lights+(unsigned)a*4))->local124->translation());
        rec->color=p->color74;
        float range=s*p->range84;
        rec->rangeSq=range*range;
        rec->radius=s*p->radius88;
    }
    r->x14=resolve(res->handle24);
    fn_80272F14(ctx,&r->m20);
    r->m60.m[0][2]=-r->m60.m[0][2];
    r->m60.m[1][2]=-r->m60.m[1][2];
    r->m60.m[2][2]=-r->m60.m[2][2];
    r->m60.m[3][2]=-r->m60.m[3][2];
    fn_8027FC80(ctx,r->x14,&r->m60,r->res10);
    if(r->fog18&&r->fog18->enabled80){
        fn_80272708(ctx,&r->fog18->color74);
        fog=1;
    }else fog=0;
    Vec3 local=xformF(world,r->resC->local124->translation());
    parts=model->partCountA4;
    for(j=0;j<parts;j++){
        idx=model->indices110[j];
        Bounds*b=&bounds->data[idx];
        int visible=0;
        if((r->flags1C&3)&&!fn_801E2370(r->record0,b,eye,&r->m20,&visible)&&!(model->flags6E&4))continue;
        if(fn_801F0980(model->partsAC[idx].cone(),&local)&&!(model->flags6E&4))continue;
        {Mesh*mesh=resolveMesh(model->partsAC[idx].mesh88);int index=mesh->materialB8.index;MaterialManager*m=(MaterialManager*)lbl_801E9D24.manager;int tag=m->entries[index].tag;if(tag==mesh->materialB8.tag)material=m->entries[index].object;else material=0;}
        if(material->flags68&1)continue;
        if(material->flags68&8)mode=4;
        else if(isTranslucent(material))mode=1;
        else mode=0;
        r->activeAC8=c=0;
        if(count>3){
            float dist[20];
            int near=0;
            for(k=0;k<count;k++){
#define RK ((LightRec*)((char*)r->lightRecs+(unsigned)k*0x24))
                if(REACHK(RK,b,*(double*)&lbl_8037B7A0)){
                    near++;
                    dist[k]=(RK->pos-b->center).lengthSquared();
                }else dist[k]=*(const volatile float*)&lbl_8037B7A8;
            }
            if(near>3){
                for(k=0;k<count;k++){
                    if(lbl_8037B7A8!=dist[k]){
                        best=dist[k];
                        bestIdx=k;
                        start=k+1;
                        break;
                    }
                }
                for(i=0;i<3;i++){
                    for(k=start;k<count;k++){
                        if(best>dist[k]){best=dist[k];bestIdx=k;}
                    }
                    fn_8027F994(ctx,r->activeAC8,(LightRec*)((char*)r->lightRecs+(unsigned)bestIdx*0x24),&r->m20,res);
                    dist[bestIdx]=lbl_8037B7A8;
                    best=lbl_8037B7A8;
                    r->activeAC8++;
                }
            }else{
                for(b2=0;b2<count;b2++){
                    LightRec*rec=(LightRec*)((char*)r->lightRecs+(unsigned)b2*0x24);
                    if(REACH(rec,b)){
                        fn_8027F994(ctx,r->activeAC8,rec,&r->m20,res);
                        r->activeAC8++;
                    }
                }
            }
        }else{
            unsigned off=0;
            for(;c<count&&r->activeAC8<3;c++,off+=0x24){
                LightRec*rec=(LightRec*)((char*)r->lightRecs+off);
                if(REACH(rec,b)){
                    fn_8027F994(ctx,r->activeAC8,rec,&r->m20,res);
                    r->activeAC8++;
                }
            }
        }
        State*st=&states->data[idx];
        u16 l=st->getLod();
        if(l==0xFFFF||r->lodBCC>l){
            st->slot=0xFFFF;
            states->data[idx].lod=lod;
        }else{
            r->lodBCC=(u16)l;
            lod=l;
        }
        u16 cur=states->data[idx].slot;
        if(cur==0xFFFF){
            u16 slot=CX->allocate(&r->handleBE4,idx);
            vb=CX->acquire(slot);
            fn_80270564(model,r,&model->partsAC[idx],vb,material);
            fn_802820B4(r,vb);
            states->data[idx].slot=slot;
            int n=lod+1;
            fn_800F22F4(vb->positions,n*(n*12));
            fn_800F22F4(vb->normals,n*(n*12));
            fn_800F22F4(vb->colors,n*(n*4));
            fn_800F22F4(vb->texcoords,n*(n*8));
        }else if(fog){
            VertexBuffer*v=CX->acquire(cur);
            int n=lod+1;
            vb=v;
            fn_800F2320(v->positions,n*(n*12));
            fn_800F2320(v->colors,n*(n*4));
            fn_802820B4(r,v);
            fn_800F22F4(v->colors,n*(n*4));
        }else{
            vb=CX->acquire(cur);
        }
        u16 flags=0x10;
        if(fog)flags|=0x8000;
        switch(r->activeAC8){
        case 1:flags|=0x400;break;
        case 2:flags|=0x800;break;
        case 3:flags|=0x1000;break;
        }
        if(mode&&!(model->flags6E&4)){
            DrawRecord*rec=&ctx->records3AC[ctx->count3B0];
            rec->next=ctx->count3B0+1;
            ctx->count3B0++;
            rec->flags=flags;
            rec->material=material;
            rec->mtx[0][0]=r->m20.m[0][0];rec->mtx[0][1]=r->m20.m[1][0];rec->mtx[0][2]=r->m20.m[2][0];rec->mtx[0][3]=r->m20.m[3][0];
            rec->mtx[1][0]=r->m20.m[0][1];rec->mtx[1][1]=r->m20.m[1][1];rec->mtx[1][2]=r->m20.m[2][1];rec->mtx[1][3]=r->m20.m[3][1];
            rec->mtx[2][0]=r->m20.m[0][2];rec->mtx[2][1]=r->m20.m[1][2];rec->mtx[2][2]=r->m20.m[2][2];rec->mtx[2][3]=r->m20.m[3][2];
            rec->mtx[2][0]=-rec->mtx[2][0];
            rec->mtx[2][1]=-rec->mtx[2][1];
            rec->mtx[2][2]=-rec->mtx[2][2];
            rec->mtx[2][3]=-rec->mtx[2][3];
            rec->matrix=r->m60;
            rec->x80=r->x14;
            rec->x84=r->res10;
            if(r->fog18)rec->fog=r->fog18->color74;
            rec->buffer=vb;
            rec->depth94=r->offsetA0.z+r->distanceAC;
            rec->list=&ctx->lists3B4[lod-1];
        }else{
            ctx->flags2D0=0;
            ctx->flags2D2=0xFFFF;
            fn_80272968(ctx,material,5);
            ctx->flags2D0|=flags;
            fn_8027353C(ctx);
            if(mode){
                GXSetZMode(1,3,1);
                GXSetZCompLoc(0);
            }
            PPCSync();
            GXInvalidateVtxCache();
            GXSetArray(9,vb->positions,0xC);
            GXSetArray(10,vb->normals,0xC);
            GXSetArray(11,vb->colors,4);
            GXSetArray(13,vb->texcoords,8);
            DisplayList*dl=&ctx->lists3B4[lod-1];
            if(dl->data&&dl->capacity)GXCallDisplayList(dl->data,dl->size);
        }
        if(model->flags6E&4)GXDrawDone();
    }
    GXSetZCompLoc(1);
    r->m60.m[0][2]=-r->m60.m[0][2];
    r->m60.m[1][2]=-r->m60.m[1][2];
    r->m60.m[2][2]=-r->m60.m[2][2];
    r->m60.m[3][2]=-r->m60.m[3][2];
}
