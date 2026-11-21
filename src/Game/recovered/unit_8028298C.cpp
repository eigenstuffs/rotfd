#include "recovered/w3_7_render.h"
extern "C" const float lbl_8037B800,lbl_8037B804;
struct Scene{char unknown00[8];Handle*materials08;};
struct ModelB{char unknown00[0xA0];void*texcoordsA0;int partCountA4;char unknownA8[4];struct Part14{char unknown00[0xC];int material0C;char unknown10[4];}*partsAC;char unknownB0[0x50];int*order100;char unknown104[8];DisplayList*lists10C;};
inline float getScaleB(const Matrix*m){Row c=m->column(0);return c.length(lbl_8037B800);}
inline Texture*resolveTexture(const Handle&h){return (Texture*)resolve(h);}
inline signed char isTranslucent(Material*m){
 if(fn_801F7EB8(&m->texture74)&&resolveTexture(m->texture74)->format3F==2)return 1;
 if(m->alpha18<lbl_8037B804)return 1;
 if(m->flags68&8)return 1;
 return 0;}
inline Resource*lightV(Renderer*r,unsigned i){return r->lights[i];}
inline Resource*&lightR(Renderer*r,unsigned i){return r->lights[i];}
inline Resource**lightP(Renderer*r,unsigned i){return &r->lights[i];}
inline Vec3 xformB(const Matrix*m,const Vec3&p){
 float y=m->m[3][1]+(m->m[0][1]*p.x+m->m[1][1]*p.y+m->m[2][1]*p.z);
 float x=m->m[3][0]+(m->m[0][0]*p.x+m->m[1][0]*p.y+m->m[2][0]*p.z);
 float z=m->m[3][2]+(m->m[0][2]*p.x+m->m[1][2]*p.y+m->m[2][2]*p.z);
 return Vec3(x,y,z);}
inline short getParts(ModelB*m){return m->partCountA4;}
inline Context*getCtx(Renderer*r){return r->record0->context48;}
inline u16 baseFlags(){return 0x20;}
inline int getCount(Renderer*r){return r->lightCount;}
inline void*resolveIn(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];void*q;if(e->tag==h.tag)q=e->object;else q=0;return q;}
inline void*resolve3(const Handle_801F7F10&h){return resolveIn(*(const Handle*)&h);}
extern "C" void fn_8028298C(ModelB*model,Renderer*r,int unused,Scene*scene,void*colors){
    int n;short k;int i;int count;short last;short mat;Material*material;
    short parts=model->partCountA4;
    u16 flags=0x20;
    Context*ctx=r->record0->context48;
    count=r->lightCount;
    Matrix m;
    if(count!=0){
        r->lightCountAC4=count;
        r->activeAC8=0;
        m=*r->res10->getWorld();
        float scale=lbl_8037B804/getScaleB(r->res10->local124);
        for(i=0;i<count&&r->activeAC8<3;i++){
            Parent*p=(Parent*)resolve3(LightCopy((*(Resource**)((char*)r->lights+(unsigned)i*4))->parent1C));
            float s=scale*getScaleB(r->lights[(unsigned long)i]->local124);
            float range=s*p->range84;
            LightRec*rec=(LightRec*)((char*)r->lightRecs+(unsigned)i*0x24);
            rec->pos=xformB(&m,(*(Resource**)((char*)r->lights+(unsigned)i*4))->local124->translation());
            rec->color=p->color74;
            rec->rangeSq=range*range;
            rec->radius=s*p->radius88;
            fn_8027F994(ctx,r->activeAC8,rec,&r->m20,r->res10);
            r->activeAC8++;
        }
    }
    fn_80272F14(ctx,&r->m20);
    PPCSync();
    GXInvalidateVtxCache();
    GXSetArray(9,(void*)r->valueBDC,0xC);
    GXSetArray(10,(void*)r->valueBD8,0xC);
    GXSetArray(11,colors,4);
    GXSetArray(13,model->texcoordsA0,8);
    m=*r->resC->getWorld();
    m.m[0][2]=-m.m[0][2];
    m.m[1][2]=-m.m[1][2];
    m.m[2][2]=-m.m[2][2];
    m.m[3][2]=-m.m[3][2];
    fn_8027FC80(ctx,r->x14,&m,r->res10);
    if(r->activeAC8==1)flags|=0x400;
    else if(r->activeAC8==2)flags|=0x800;
    else if(r->activeAC8>2)flags|=0x1000;
    n=0;
    k=0;
    last=-1;
    while(n<parts){
        short idx=model->order100[n++];
        mat=(short)model->partsAC[idx].material0C;
        if(mat!=last){
            ctx->flags2D0=0;
            ctx->flags2D2=0xFFFF;
            material=(Material*)resolve(scene->materials08[mat]);
            fn_80272968(ctx,material,5);
            ctx->flags2D0|=flags;
            fn_8027353C(ctx);
            if(material->alpha18<lbl_8037B804||isTranslucent(material)){
                GXSetZMode(1,3,1);
                GXSetZCompLoc(0);
            }
            last=mat;
        }
        DisplayList*dl=&model->lists10C[k++];
        if(dl->data&&dl->capacity)GXCallDisplayList(dl->data,dl->size);
    }
    GXSetZCompLoc(1);
}
