struct Vec3_801E04DC {
    float x,y,z;
    void operator=(const Vec3_801E04DC&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
struct QueryResult_801E04DC {
    Vec3_801E04DC point;
    float distance;
    Vec3_801E04DC normal;
    char unknown1C[0x14];
};
struct Result_801E04DC {
    Vec3_801E04DC point;
    float distance;
    Vec3_801E04DC normal;
    char unknown1C[12];
    unsigned long long token;
    char unknown30[12];
    signed char valid;
};
extern "C" {
    signed char fn_801B99DC(void*,void*,QueryResult_801E04DC*);
    signed char fn_801B9D1C(void*,void*,QueryResult_801E04DC*);
}
extern "C" int fn_801E04DC(void*first,void*second,Result_801E04DC*output,void*fourth,unsigned long long token) {
    QueryResult_801E04DC hit;
    if(fn_801B99DC(first,second,&hit)) {
        if(!output->valid||hit.distance<output->distance) {
            output->valid=1;
            output->point=hit.point;
            output->normal=hit.normal;
            output->distance=hit.distance;
            output->token=token;
            return 1;
        }
    }
    return 0;
}
