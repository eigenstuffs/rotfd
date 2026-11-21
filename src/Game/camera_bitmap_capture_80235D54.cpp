// Camera capture initialization, scan, bitmap legend and completion.
// The five contiguous functions share their native scalar/literal storage.
// Partial object views cover only fields and virtual slots used here.
#include "Game/engine_bitmap_param_ctor.h"
typedef unsigned long CameraCaptureWord;
struct Handle_801F7F10 {union {CameraCaptureWord word;CameraCaptureWord value;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct CameraCaptureVec2 {float x,y;CameraCaptureVec2(){}CameraCaptureVec2(float a,float b):x(a),y(b){}void scale(float s){x*=s;y*=s;}};
struct CameraCaptureVec3 {float x,y,z;CameraCaptureVec3(){}CameraCaptureVec3(float a,float b,float c):x(a),y(b),z(c){}CameraCaptureVec3(const CameraCaptureVec3&v):x(v.x),y(v.y),z(v.z){}CameraCaptureVec3&operator=(const CameraCaptureVec3&v){x=v.x;y=v.y;z=v.z;return*this;}CameraCaptureVec3&operator+=(float v){x+=v;y+=v;z+=v;return*this;}CameraCaptureVec3&operator-=(const CameraCaptureVec3&v){x-=v.x;y-=v.y;z-=v.z;return*this;}};
struct CameraCaptureSphere {CameraCaptureVec3 point;float radius;};
struct CameraCaptureColor {float r,g,b,a;CameraCaptureColor(float x,float y,float z,float w):r(x),g(y),b(z),a(w){}};
struct CameraCaptureNodePrefix{char unknown00[8];};
struct CameraCaptureNode:CameraCaptureNodePrefix {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void finish();virtual void slot50();virtual void map(Bitmap_802EBEE0*,const CameraCaptureSphere*,const CameraCaptureVec2*);
 char unknown0C[0x10];Handle_801F7F10 parent;char unknown20[0x98];CameraCaptureVec3 direction;char unknownC4[0x58];float angle;char unknown120[4];CameraCaptureVec3 position;
};
struct CameraCaptureEntry{CameraCaptureNode*object;CameraCaptureWord u04,u08;signed char generation;char u0D[3];signed char getGeneration()const{return generation;}};struct CameraCaptureManager{int count,capacity;CameraCaptureEntry*entries;};
struct CameraCaptureSceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
struct CameraCaptureGlobals {char unknown00[0x110];void*logger;CameraCaptureSceneRecord*records;CameraCaptureManager*manager;};
extern "C"{extern CameraCaptureGlobals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,unsigned long);void fn_801F86C8(void*,const void*,int);CameraCaptureNode*fn_801F7EB8(const Handle_801F7F10*);}
struct CameraCaptureZero1:Handle_801F7F10{CameraCaptureZero1(){word=0;}~CameraCaptureZero1(){}};struct CameraCaptureZero2:CameraCaptureZero1{CameraCaptureZero2(){word=0;}~CameraCaptureZero2(){}};struct CameraCaptureZero3:CameraCaptureZero2{CameraCaptureZero3(){word=0;}~CameraCaptureZero3(){}};struct CameraCaptureZero4:CameraCaptureZero3{CameraCaptureZero4(){word=0;}~CameraCaptureZero4(){}};
struct ReverseSphereZero1 : Handle_801F7F10 { ReverseSphereZero1() { value = 0; } };
struct ReverseSphereZero2 : ReverseSphereZero1 { ReverseSphereZero2() { value = 0; } };
struct ReverseSphereZero3 : ReverseSphereZero2 { ReverseSphereZero3() { value = 0; } };
struct ReverseSphereZero4 : ReverseSphereZero3 { ReverseSphereZero4() { value = 0; } };
struct ReverseSphereCopy4 : ReverseSphereZero4 {
    ReverseSphereCopy4() { value = 0; }
    ReverseSphereCopy4(const Handle_801F7F10& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
    ReverseSphereCopy4(const ReverseSphereCopy4& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct Handle_80075D64:CameraCaptureZero4 {Handle_80075D64(){word=0;}~Handle_80075D64(){}Handle_80075D64&operator=(const Handle_80075D64&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}Handle_80075D64&operator=(const ReverseSphereCopy4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
inline CameraCaptureNode*resolve(const Handle_801F7F10&h){int i=h.bits.index;CameraCaptureManager*m=lbl_801E9D24.manager;int tag=m->entries[i].getGeneration();return tag==h.bits.generation?m->entries[i].object:0;}
struct CameraCaptureRecord{char storage[0x44];};extern "C"{void fn_8007B464(void*);void __construct_array(void*,void(*)(void*),void*,CameraCaptureWord,CameraCaptureWord);}
struct HandleOwner_8007B3C8{int selected;Handle_80075D64 handle;char unknown08[0x14];CameraCaptureRecord records[4];HandleOwner_8007B3C8(){__construct_array(records,fn_8007B464,0,sizeof(CameraCaptureRecord),4);selected=-1;handle=Handle_80075D64();}~HandleOwner_8007B3C8(){}};
struct CameraCaptureRay {CameraCaptureVec3 origin;float length;CameraCaptureVec3 direction;float unknown1C;CameraCaptureRay(const CameraCaptureVec3&o,float x,float y,float z,float l):origin(o),direction(x,y,z){length=l;}};
struct CameraCaptureResult {CameraCaptureVec3 point;char unknown0C[0x28-12];unsigned long long flags;void*object;void*other;void*extra;signed char hit;char unknown3D[3];CameraCaptureWord end;CameraCaptureResult(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct CameraCaptureQuery{signed char flag;char unknown01[0xF];CameraCaptureVec3 direction;float angle;char unknown20[0x20];};
struct CameraCaptureOwner:CameraCaptureNodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void finish();virtual void configure(int,float);
 char unknown0C[0x14];int index;char unknown24[4];Handle_801F7F10 resource;char unknown2C[0x31];signed char active;char unknown5E[2];Bitmap_802EBEE0*bitmap;CameraCaptureVec2 scan;CameraCaptureSphere bounds;Handle_80075D64 bound;int count;float elapsed,total;CameraCaptureVec3 position;float step,limit;int unknownA0,period,mode;
};
struct ReverseSphereSelf;
extern "C"{const Handle_801F7F10*fn_80235C08(const CameraCaptureOwner*);signed char fn_80269DE0(CameraCaptureNode*,const CameraCaptureVec3*,HandleOwner_8007B3C8*,int);signed char fn_80269230(void*,const CameraCaptureRay&,CameraCaptureResult*,unsigned long long,unsigned long long);int fn_80242C34(CameraCaptureNode*,CameraCaptureVec3*,const CameraCaptureVec3*,const HandleOwner_8007B3C8*,CameraCaptureQuery*);void fn_8023D648(CameraCaptureNode*);int fn_80238310(const Bitmap_802EBEE0*,const CameraCaptureVec2*,unsigned short*);void fn_802385C0(Bitmap_802EBEE0*,const CameraCaptureVec2*,const void*);void fn_802383D8(Bitmap_802EBEE0*,const CameraCaptureVec2*,const CameraCaptureVec2*,const void*);void fn_802386BC(Bitmap_802EBEE0*,CameraCaptureColor);ReverseSphereCopy4 fn_80269C94(ReverseSphereSelf*,CameraCaptureSphere*);double floor(double);extern const CameraCaptureVec2 game_vec2_zero;extern const char lbl_802AEA2C[],lbl_802AEA3C[];
}
inline void*operator new(unsigned long,void*p){return p;}

extern "C"{char*strcpy(char*,const char*);char*strcat(char*,const char*);void fn_801C9290(void*,void*);void fn_801FA014(void*,const char*,...);}

// Shared controls and defaults precede the capture/update pair.
extern "C" void fn_80235D54(CameraCaptureOwner*self,int slot,float value){if(!self->active){if(slot==0&&value>9.999999974752427e-7f)self->step=value;float zero=0.0f;if(slot==1&&value!=zero)self->unknownA0=(int)value;if(slot==2&&value!=zero)self->limit=value;}}
extern "C" void fn_80235DC0(CameraCaptureOwner*self){self->active=0;self->bitmap=0;self->bound=Handle_80075D64();self->mode=0;self->period=3;self->configure(0,1.0f);self->configure(1,250.0f);self->configure(2,60.0f);}
extern "C" void fn_80235EBC(CameraCaptureOwner*self,int mode){if(self->active)return;self->total=0.0f;self->active=1;self->mode=mode;if(self->mode!=1)self->period=0;}
// Save the finished bitmap and report elapsed hours, minutes and seconds.
extern "C" void fn_80235EF4(CameraCaptureOwner*self){
 if(self->bitmap && fn_801F7EB8(&self->resource)){
  char path[128];
  if(self->mode==1)strcpy(path,"C:\\CAMFRAME");
  else if(self->mode==2)strcpy(path,"C:\\CAMTEXT");
  else strcpy(path,"C:\\CAMPATCH");
  strcat(path,"_");
  strcat(path,reinterpret_cast<const char*>(resolve(self->resource))+0x10);
  strcat(path,".TGA");
  fn_801C9290(self->bitmap,path);
  delete self->bitmap;
int minutes=(int)(self->total/3600.0f);self->total-=3600.0f*(float)minutes;int seconds=(int)(self->total/60.0f);self->total-=60.0f*(float)seconds;
  fn_801FA014(lbl_801E9D24.logger,"MakeCamera Time %02d:%02d:%02d",minutes,seconds,(int)self->total);
 }
 self->active=0;
 self->bitmap=0;
 self->bound=Handle_80075D64();
}
// Advance collision sampling or initialize the bitmap and ten-color legend.
extern "C" void fn_80236120(CameraCaptureOwner*self,float dt){
 CameraCaptureColor colors[10]={
  CameraCaptureColor(0.0f,0.8980392217636108f,0.10588235408067703f,1.0f),
  CameraCaptureColor(0.0f,0.6980392336845398f,0.3019607961177826f,1.0f),
  CameraCaptureColor(0.01568627543747425f,0.5137255191802979f,0.5176470875740051f,1.0f),
  CameraCaptureColor(0.062745101749897f,0.3607843220233917f,0.7647058963775635f,1.0f),
  CameraCaptureColor(0.0f,0.062745101749897f,0.7490196228027344f,1.0f),
  CameraCaptureColor(1.0f,0.8156862854957581f,0.0f,1.0f),
  CameraCaptureColor(1.0f,0.6352941393852234f,0.0f,1.0f),
  CameraCaptureColor(1.0f,0.45098039507865906f,0.0f,1.0f),
  CameraCaptureColor(1.0f,0.2666666805744171f,0.0f,1.0f),
  CameraCaptureColor(0.8823529481887817f,0.0235294122248888f,0.0f,1.0f)
 };
 float scale=1.0f/self->step;
 if(fn_801F7EB8(&self->bound)){
  self->total+=dt;
  if(self->count==0){
   CameraCaptureResult collision;CameraCaptureQuery query;query.flag=0;
   for(;;){
    if(self->scan.x>2.0f*(self->bounds.radius-2.0f)){
     self->scan.x=0.0f;self->scan.y+=self->step;
     if(self->scan.y>2.0f*(self->bounds.radius-2.0f))break;
    }else self->scan.x+=self->step;
    self->position=CameraCaptureVec3(self->scan.x+((self->bounds.point.x-self->bounds.radius)-2.0f),self->bounds.point.y+self->bounds.radius,self->scan.y+((self->bounds.point.z-self->bounds.radius)-2.0f));
    HandleOwner_8007B3C8 hit;
    if(!fn_80269DE0(resolve(*fn_80235C08(self)),&self->position,&hit,-1))continue;
    CameraCaptureNode*world=resolve(*fn_80235C08(self));
    if(fn_80269230(world,CameraCaptureRay(self->position,0.0f,-1.0f,0.0f,10.0f*self->bounds.radius),&collision,2ULL,0ULL)){
     self->position.y=collision.point.y;
     if((signed char)fn_80242C34(resolve(hit.handle),&self->position,&self->position,&hit,&query))break;
    }
   }
   self->elapsed=0.0f;
   CameraCaptureNode*actor=resolve(lbl_801E9D24.records[self->index].handle);CameraCaptureNode*target=resolve(actor->parent);
   target->position=self->position;float angleBias=0.0872664600610733f;target->angle=query.angle+angleBias;actor->direction=query.direction;fn_8023D648(actor);
  }else{
   if(self->count>1)self->elapsed+=dt;
   if(self->count>self->period){
    self->count=0;self->position+=self->bounds.radius;self->position-=self->bounds.point;
    CameraCaptureVec2 point(self->position.x*scale,self->position.z*scale);unsigned short pixel;
    if((signed char)fn_80238310(self->bitmap,&point,&pixel)&&pixel==0xFFFF){
     int color=0;
     if(self->mode==0){}else if(self->mode==1)color=(int)(10.0f-(10.0f*(1.0f/(self->elapsed/3.0f)))/(2.0f*self->limit));
     if(color>=10)color=9;if(color<0)color=0;
     fn_802385C0(self->bitmap,&point,&colors[color]);
    }
    --self->count;
   }
  }
  ++self->count;
  if(self->scan.y<2.0f*(self->bounds.radius-2.0f))return;
 }else{
  self->bound=fn_80269C94(reinterpret_cast<ReverseSphereSelf*>(resolve(*fn_80235C08(self))),&self->bounds);
  if(fn_801F7EB8(&self->bound)){
   self->scan=game_vec2_zero;self->count=0;self->elapsed=0.0f;
   self->bounds.point.x=(float)floor(self->bounds.point.x);self->bounds.point.y=(float)floor(self->bounds.point.y);self->bounds.point.z=(float)floor(self->bounds.point.z);self->bounds.radius=(float)floor(self->bounds.radius);
   float size=self->bounds.radius*scale;int pixels;if(size>0.0f)pixels=(int)(0.9999989867210388f+size);else pixels=(int)size;
   void*memory=fn_801EFA1C(lbl_801EF5C8,sizeof(Bitmap_802EBEE0),lbl_802AEA2C,lbl_802AEA3C,0x9F,4);
   self->bitmap=new(memory)Bitmap_802EBEE0(2*pixels,2*pixels,7);
   if(self->bitmap){
    fn_802386BC(self->bitmap,CameraCaptureColor(1.0f,1.0f,1.0f,1.0f));
    if(fn_801F7EB8(&self->bound)){
     CameraCaptureNode*object=resolve(self->bound);CameraCaptureVec2 mapping(scale,scale);object->map(self->bitmap,&self->bounds,&mapping);
     float legendScale=(float)(2*pixels)/208.0f;
     CameraCaptureColor*color=colors;for(int i=0;i<10;i++,color++){
      CameraCaptureVec2 first(8.0f,20.0f*(float)i+8.0f);float boxSize=16.0f;CameraCaptureVec2 last(first.x+boxSize,first.y+boxSize);
      first.scale(legendScale);last.scale(legendScale);fn_802383D8(self->bitmap,&first,&last,color);
     }
    }
    return;
   }else{self->bound=Handle_80075D64();}
  }
 }
 self->finish();
}

// Retained native string identities also serve neighboring compiled consumers.
extern "C" const char lbl_802AEA2C[] =
    "Anonymous New"; // +0x0

// Camera and music resource strings formerly retained by two original spans.
#pragma force_active on

extern "C" const char lbl_802AEA3C[] = "CameraEngineZoneCapture_Z.cpp";

extern "C" const char lbl_802AEA60[] __attribute__((aligned(8))) = "Anonymous Alloc";

extern "C" const char lbl_802AEA70[] = "Bitmap_Z.cpp";

extern "C" const char lbl_802AEA80[] = "Anonymous New";

extern "C" const char lbl_802AEA90[] =
    "Material"; // +0x0

// 0x802AEAA0..0x802AEAF1 (music strings, MeshData) belong to the
// platform audio owner constructor's TU (__ct__27PlatformAudioOwner_8023BB18Fv).

#pragma force_active reset

typedef char CaptureVecSize[sizeof(CameraCaptureVec3)==12?1:-1];
typedef char CaptureSphereSize[sizeof(CameraCaptureSphere)==16?1:-1];
typedef char CaptureRaySize[sizeof(CameraCaptureRay)==32?1:-1];
typedef char CaptureResultSize[sizeof(CameraCaptureResult)==72?1:-1];
typedef char CaptureQuerySize[sizeof(CameraCaptureQuery)==64?1:-1];
typedef char CaptureOwnerSize[sizeof(CameraCaptureOwner)==172?1:-1];
