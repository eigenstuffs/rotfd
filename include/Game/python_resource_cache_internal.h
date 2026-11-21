#ifndef GAME_PYTHON_RESOURCE_CACHE_INTERNAL_H
#define GAME_PYTHON_RESOURCE_CACHE_INTERNAL_H
/* Native script resource records and the two 200-entry name caches.
 * The initializer and module lifecycle share these exact object layouts. */
typedef unsigned long Word;
struct EventPyObject;
struct Name {Word value;Name():value(0){}Name(const char*);};
struct ResourceRecord {char name[64];Name hash;EventPyObject*value;const Name&key()const{return hash;}EventPyObject*object()const{return value;}};
inline void*operator new(unsigned long,void*p){return p;}
struct ResourceArray {
 int count,capacity;ResourceRecord*data;
 ResourceRecord&at(const int&i){return data[i];}
 void remove(const int&i);
 void resizeStorage(int n);
 void append(const ResourceRecord&record);
 void release();
 void reset();
};
struct GlobalDestructorRecord {GlobalDestructorRecord*next;void*destructor;void*object;};
struct ResourceCacheEntry {Word hash;void*value;};
extern "C" {
 extern GlobalDestructorRecord lbl_802F3460;
 extern ResourceArray lbl_802F346C;
 extern ResourceCacheEntry lbl_802F3478[200],lbl_802F3AB8[200];
}
struct StartupSingleton;
extern "C" StartupSingleton*fn_8001F38C(void*);
#endif
