// Normalize a resource path and find its retained Handle by the resulting key.
typedef unsigned int u32;
struct PathLookupResult_801B3BE4{signed int generation:8;signed int index:24;};
struct PathLookupKey {u32 value;PathLookupKey(){}PathLookupKey(u32 v):value(v){}PathLookupKey(const PathLookupKey&v):value(v.value){}bool operator==(const PathLookupKey&other)const{return value==other.value;}};
struct PathLookupHandleIndex{int value;PathLookupHandleIndex(int v):value(v){}operator int()const{return value;}};
struct PathLookupHandleEntry{void*object;u32 key,unknown8;signed char generation;char unknownD[3];};
struct PathLookupOwner_801B3BE4{
 int count,capacity;PathLookupHandleEntry*entries;char unknownC[0xAC];int selectedCount,selectedCapacity;PathLookupResult_801B3BE4*selected;
 PathLookupKey key(const PathLookupResult_801B3BE4&handle)const{
  const PathLookupHandleIndex index(handle.index);signed char generation=handle.generation;int valid=0;
  if(index<count&&generation==entries[index].generation)valid=1;
  if(valid)return PathLookupKey(entries[index].key);else return PathLookupKey(0);
 }
};
extern "C" {
 char*strcpy(char*,const char*);int strlen(const char*);char*strstr(const char*,const char*);char*strchr(const char*,int);
 extern char lbl_801E9D24[];void fn_80207974(const char*,char*);u32 fn_801F948C(PathLookupKey*,const char*);void fn_801F7CB4(PathLookupResult_801B3BE4*,const PathLookupResult_801B3BE4*);
}
extern "C" void fn_801B3BE4(PathLookupResult_801B3BE4*output,PathLookupOwner_801B3BE4*manager,const char*path){
 char buffer[128];strcpy(buffer,path);const char*prefix=lbl_801E9D24+4;
 if(strlen(prefix)&&strstr(buffer,prefix))fn_80207974(path,buffer);
 else{char*p=strchr(buffer,0x5c);while(p){*p='>';p=strchr(p,0x5c);}}
 PathLookupKey key;key.value=fn_801F948C(&key,buffer);
 for(int i=0;i<manager->selectedCount;++i){
  if(manager->key(manager->selected[i])==key){fn_801F7CB4(output,&manager->selected[i]);return;}
 }
 output->index=0;output->generation=0;
}
