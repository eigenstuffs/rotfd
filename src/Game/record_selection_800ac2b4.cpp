typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Node{char unknown00[0x48];void*field48;float field4C;char unknown50[0x20];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x264];char actions[4];};
struct Primary{char unknown00[0x60];Handle resource;};struct Scene{char unknown00[0x15058];Primary*primary;};struct Related{char unknown00[0x1C];Handle*handle;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{Word unknown00,unknown04;Entry*entries;};struct Input{char unknown00[0x1C];int*current;const int& getCurrent()const{return *current;}};
extern "C" struct Global{char unknown00[0x110];void*log;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Related*related;char unknown140[0x24];Input*input;}lbl_801E9D24;
struct Record{int key;Word unknown04;int index,count,current;signed char first,second,special;char unknown17[0x41];};struct Owner{char unknown00[0x14];int count,capacity;Record*records;int current;char unknown24[0x128];float time;};
extern "C"{extern const float lbl_803790AC,lbl_803790B0;extern char lbl_803790B4[4],lbl_8029EFE4[];extern int lbl_803777BC;extern Word lbl_803777AC;Word fn_801F948C(void*,const char*);Word fn_801F7EB8(const Handle*);void fn_800A64E0(Node*,int);void fn_800B6C84(Input*,int,Word);void fn_801FA014(void*,const char*,...);signed char fn_8007D604(void*,int);void fn_8007D6A0(void*,int);void fn_80057294(Primary*);void fn_800AD3C8(Owner*);}
struct Name{Word word;Name(){}Name(const char*s){word=fn_801F948C(this,s);}};extern "C" void fn_800A6234(Node*,signed char,const Name&);
inline Node*resolve(const Handle&h){int i=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();return tag==h.bits.tag?m->entries[i].object:0;}
inline Node*sceneActor(){return resolve(lbl_801E9D24.scene->primary->resource);}
inline Node*actor(){const Handle&h=resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
inline Record*find(Owner*self,int key){for(int i=0;i<self->count;++i){Record*r=&self->records[i];if(key==r->key)return r;}return 0;}
typedef char CheckRecordSize[sizeof(Record)==88?1:-1];
extern "C"void fn_800AC2B4(Owner*self,int key){Name name;Record*r=find(self,key);self->time=lbl_803790AC;if(r){self->current=key;if(r->count>0)r->current=0;r->first=1;r->second=1;if(r->special||r->index>=0){
 fn_800A64E0(sceneActor(),0);Node*n=sceneActor();if(n->field48){n->field48=0;n->field4C=lbl_803790B0;}
 if(r->special){fn_800A64E0(sceneActor(),1);Node*target=sceneActor();name=Name(lbl_803790B4);fn_800A6234(target,1,name);}else if(r->index>=0){Node*target=sceneActor();name=Name(lbl_803790B4);fn_800A6234(target,1,name);}
 if(lbl_801E9D24.input->getCurrent()!=lbl_803777BC)fn_800B6C84(lbl_801E9D24.input,0,lbl_803777AC);else fn_801FA014(lbl_801E9D24.log,lbl_8029EFE4);
 Node*target=actor();if(!fn_8007D604(target->actions,0x28)&&!fn_8007D604(target->actions,0x29)&&!fn_8007D604(target->actions,0x2F))fn_8007D6A0(target->actions,6);
 }fn_80057294(lbl_801E9D24.scene->primary);fn_800AD3C8(self);}}
