/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-collision-results.md. */
struct Vec3_801E09E8 {
    float x,y,z;
    void operator=(const Vec3_801E09E8&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
struct QueryResult_801E09E8 {
    Vec3_801E09E8 point;
    float distance;
    Vec3_801E09E8 normal;
    char unknown1C[0x14];
};
struct Result_801E09E8 {
    Vec3_801E09E8 point;
    float distance;
    Vec3_801E09E8 normal;
    char unknown1C[12];
    unsigned long long token;
    char unknown30[12];
    signed char valid;
};
extern "C" {
    signed char fn_801B99DC(void*,void*,QueryResult_801E09E8*);
    signed char fn_801B9D1C(void*,void*,QueryResult_801E09E8*);
}
extern "C" int fn_801E09E8(void*first,void*second,Result_801E09E8*output,void*fourth,unsigned long long token) {
    QueryResult_801E09E8 hit;
    if(fn_801B9D1C(first,second,&hit)) {
        if(!output->valid||hit.distance<output->distance) {
            output->valid=1;
            output->distance=hit.distance;
            output->point=hit.point;
            output->normal=hit.normal;
            output->token=token;
            return 1;
        }
    }
    return 1;
}
