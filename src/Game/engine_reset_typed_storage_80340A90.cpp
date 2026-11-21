/* Storage following main's translation-unit BSS; types are established by the
 * original __register_global_object records and scalar startup. */
struct GlobalDestructorRecord {
 GlobalDestructorRecord* next;
 void (*destructor)(void*);
 void* object;
};
extern "C" {
 unsigned char lbl_80340A90[0x20];
 GlobalDestructorRecord lbl_80340AB0;
}
