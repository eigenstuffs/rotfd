/* Vector3 grid storage constructor (fn_8020BE78; real identity __ct__23Vector3Storage_8020BE78Fv).
 * The 12-byte grid header is built by two nested inline base constructors (word 0 by the
 * innermost base, words 1-2 by the grid base, which also clears the item pointer); then the
 * storage constructor allocates its 16 x 1024 grid with fn_8020BECC (vector3_storage_setup.c).
 * Matching notes: the bases need user-declared destructors (never defined or referenced here)
 * so the inline constructors keep their `this` copies (mr r5,r31; mr r6,r5) as in the original. */
extern "C" void fn_8020BECC(void*self,int rows,int width);
struct Vector3GridHeader_8020BE78{int rows;Vector3GridHeader_8020BE78(){rows=0;}~Vector3GridHeader_8020BE78();};
struct Vector3Grid_8020BE78:Vector3GridHeader_8020BE78{int columns,count,width;void*items;
 Vector3Grid_8020BE78(){columns=0;count=0;items=0;}~Vector3Grid_8020BE78();};
struct Vector3Storage_8020BE78:Vector3Grid_8020BE78{Vector3Storage_8020BE78();};
Vector3Storage_8020BE78::Vector3Storage_8020BE78(){fn_8020BECC(this,16,1024);}
