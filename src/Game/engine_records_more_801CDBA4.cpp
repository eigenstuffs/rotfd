/* Original engine records and ownership loops.
 * See docs/notes/game-engine-records-more.md. */
struct Record_801CDBA4 {char pad[12];unsigned int resource;char tail[4];};struct Array_801CDBA4 {int count,capacity;Record_801CDBA4 *data;Record_801CDBA4 &operator[](int i){return data[i];}};struct View_801CDBA4 {char pad[0xa4];Array_801CDBA4 array;};extern "C" {
extern struct {char pad[0x118];void *handles;char gap[0x28];void *resources;} lbl_801E9D24;extern void fn_801B3FC8(void *,unsigned int,unsigned int *);extern unsigned int fn_801F4AC8(void *,unsigned int *);
void fn_801CDBA4(View_801CDBA4 *object) {if(*(unsigned short *)((char *)object+0x6e)&4){int i;for(i=0;i<object->array.count;++i){unsigned int key=0;fn_801B3FC8(lbl_801E9D24.handles,object->array[i].resource,&key);object->array[i].resource=fn_801F4AC8(lbl_801E9D24.resources,&key);}}}
}