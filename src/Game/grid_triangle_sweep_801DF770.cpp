typedef unsigned long Word;
struct Vec3 {float x,y,z;Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Vec4 {float x,y,z,w;};
// Native edge-query writes extend through unknown2C; see the original-output-layout proof.
struct Result {Vec3 point;float distance;Vec3 normal;Word unknown1C;float unknown20,unknown24;Word unknown28,unknown2C;};
struct Hit {Vec3 point;float distance;Vec3 normal;void*object;unsigned long long token;Hit(){object=0;}};
inline void*operator new(unsigned long,void*p){return p;}
struct Hits {Hit records[256];int count;int append(){if(count>=256){new(&records[255])Hit;return 255;}new(&records[count++])Hit;return count-1;}};
typedef char ResultSize[(sizeof(Result)==48)?1:-1];
typedef char HitSize[(sizeof(Hit)==40)?1:-1];
struct Query;
extern "C" { extern const float lbl_8037A4E0;signed char fn_8027A180(Query*,const Vec4*,const Vec4*,const Vec4*,const Vec4*,Result*); }
static inline void store(Hits*out,const Result&result,unsigned long long token){Hit&hit=out->records[out->append()];hit.point=result.point;hit.normal=result.normal;hit.distance=result.distance;hit.token=token;}
extern "C" void fn_801DF770(Query*query,Vec4*vertices,Hits*out,int n,unsigned long long token){
 Vec4*a=vertices;Vec4*b=vertices+n+1;Vec4*c=vertices+1;Vec4*d=vertices+n+2;Vec4*planes=vertices+(n+1)*(n+1);
 for(int row=0;row<n;++row){
  for(int col=0;col<n;++col){
   Result result;
   if(planes[0].w!=lbl_8037A4E0 && fn_8027A180(query,a,b,c,planes,&result))store(out,result,token);
   if(planes[1].w!=lbl_8037A4E0 && fn_8027A180(query,c,b,d,planes+1,&result))store(out,result,token);
   planes+=2;++a;++b;++c;++d;
  }
  ++a;++b;++c;++d;
 }
}
