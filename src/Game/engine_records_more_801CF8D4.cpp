#include "Game/render_buffer_resource.h"
struct PoolRecord_801CF8D4 {unsigned int handle;unsigned short owner,pad,next,tail;};
struct Pool_801CF8D4 {int count;char pad[4];PoolRecord_801CF8D4 *records;PoolRecord_801CF8D4 &slot(int i){return records[i+1];}};
struct OtherPool_801CF8D4 {char pad[0xc];PoolRecord_801CF8D4 *records;PoolRecord_801CF8D4 &slot(int i){return records[i+1];}};
extern "C" {extern struct {char pad[0x12c];OtherPool_801CF8D4 *other;Pool_801CF8D4 *pool;} lbl_801E9D24;}
inline Resource_802E9E20::~Resource_802E9E20(){}
inline SpatialBase_802EC118::~SpatialBase_802EC118(){}
SpatialRecord_802EA440::~SpatialRecord_802EA440(){unsigned int index=poolIndex;if(index!=0xffff){Pool_801CF8D4*pool=lbl_801E9D24.pool;if(pool)pool->slot(index).owner=0xffff;}}
