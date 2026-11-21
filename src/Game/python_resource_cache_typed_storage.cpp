/* Original registration record, resource array and two 200-entry name caches.
 * Existing fn_80020C78 initializes all entries; fn_80020500/fn_800208A8 search them. */
struct GlobalDestructorRecord {GlobalDestructorRecord*next;void(*destructor)(void*);void*object;};
struct ResourceRecord {char name[64];unsigned long hash;void*value;};
struct ResourceArray {int count,capacity;ResourceRecord*data;};
struct ResourceCacheEntry {unsigned long hash;void*value;};
extern "C" {
 GlobalDestructorRecord lbl_802F3460;
 ResourceArray lbl_802F346C;
 ResourceCacheEntry lbl_802F3478[200];
 ResourceCacheEntry lbl_802F3AB8[200];
}
