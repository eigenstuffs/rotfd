struct Vector_801DF498 {
    float x,y,z;
    Vector_801DF498() {
    }
    Vector_801DF498(const Vector_801DF498&v):x(v.x),y(v.y),z(v.z) {
    }
    Vector_801DF498&operator=(const Vector_801DF498&v) {
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;
    }
};
struct Vertex_801DF498 {
    float x,y,z,w;
};
struct Query_801DF498 {
    Vector_801DF498 position;
    float distance;
    Vector_801DF498 direction;
    float unknown1C;
    Query_801DF498(const Query_801DF498&q):position(q.position),distance(q.distance),direction(q.direction),unknown1C(q.unknown1C) {
    }
};
struct Result_801DF498 {
    Vector_801DF498 position;
    float distance;
    Vector_801DF498 normal;
    char unknown1C[20];
};
extern "C" signed char fn_801B5D50(Query_801DF498*,const Vertex_801DF498*,const Vertex_801DF498*,const Vertex_801DF498*,const Vertex_801DF498*,const Vertex_801DF498*,Result_801DF498*);
extern "C" signed char fn_801DF498(const Query_801DF498*input,const Vertex_801DF498*vertices,Result_801DF498*output,int n) {
    signed char found=0;
    const Vertex_801DF498*p00=vertices;
    const Vertex_801DF498*p10=vertices+n+1;
    const Vertex_801DF498*p01=vertices+1;
    const Vertex_801DF498*p11=p10+1;
    const Vertex_801DF498*normal=vertices+(n+1)*(n+1);
    Result_801DF498 hit;
    Query_801DF498 query(*input);
    for(int row=0; row<n; ++row) {
        for(int col=0; col<n; ++col) {
            if(fn_801B5D50(&query,p00,p10,p01,p11,normal,&hit)) {
                if(!found||hit.distance<output->distance) {
                    found=1;
                    query.distance=hit.distance;
                    output->normal=hit.normal;
                    output->position=hit.position;
                    output->distance=hit.distance;
                }
            }
            normal+=2;
            ++p00;
            ++p10;
            ++p01;
            ++p11;
        }
        ++p00;
        ++p10;
        ++p01;
        ++p11;
    }
    return found;
}
