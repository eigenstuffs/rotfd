/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-grid-queries.md. */
struct Vector_801DF604 {
    float x,y,z;
    Vector_801DF604() {
    }
    Vector_801DF604(const Vector_801DF604&v):x(v.x),y(v.y),z(v.z) {
    }
    Vector_801DF604&operator=(const Vector_801DF604&v) {
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;
    }
};
struct Vertex_801DF604 {
    float x,y,z,w;
};
struct Query_801DF604 {
    Vector_801DF604 position;
    float distance;
    Vector_801DF604 direction;
    float unknown1C;
    Query_801DF604(const Query_801DF604&q):position(q.position),distance(q.distance),direction(q.direction),unknown1C(q.unknown1C) {
    }
};
struct Result_801DF604 {
    Vector_801DF604 position;
    float distance;
    Vector_801DF604 normal;
    char unknown1C[20];
};
extern "C" signed char fn_80279558(Query_801DF604*,const Vertex_801DF604*,const Vertex_801DF604*,const Vertex_801DF604*,const Vertex_801DF604*,const Vertex_801DF604*,Result_801DF604*);
extern "C" signed char fn_801DF604(const Query_801DF604*input,const Vertex_801DF604*vertices,Result_801DF604*output,int n) {
    signed char found=0;
    const Vertex_801DF604*p00=vertices;
    const Vertex_801DF604*p10=vertices+n+1;
    const Vertex_801DF604*p01=vertices+1;
    const Vertex_801DF604*p11=p10+1;
    const Vertex_801DF604*normal=vertices+(n+1)*(n+1);
    Result_801DF604 hit;
    Query_801DF604 query(*input);
    for(int row=0; row<n; ++row) {
        for(int col=0; col<n; ++col) {
            if(fn_80279558(&query,p00,p10,p01,p11,normal,&hit)) {
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
