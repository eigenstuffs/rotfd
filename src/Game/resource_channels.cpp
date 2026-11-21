/* Resource channel decoding and state application reconstructed from GSQE78. */
typedef unsigned long u32;
struct ChannelKey {short id;float value,inTangent,outTangent;};
struct ChannelCurve {u32 prefix;int size,capacity;ChannelKey*data;ChannelKey&operator[](int i){return data[i];}};
struct Channel {u32 reference;short id,unknown6;u32 unknown8;ChannelCurve curve;};
struct GameGlobals {char unknown[0x118];void*context;};
extern "C" {
extern GameGlobals lbl_801E9D24;
void fn_801B41F4(void*,u32*,void**);
void*fn_801E9F40(void*,void*,int);
void fn_801B2354(ChannelCurve*,void**);
int fn_801B0AA0(ChannelCurve*,float*,int,float);
void fn_8024A1AC(void*,Channel*,char);
void fn_8024A430(void*,Channel*,char);
void fn_801F77A4(Channel*o,void**stream){
 fn_801B41F4(lbl_801E9D24.context,&o->reference,stream);
 *stream=fn_801E9F40(&o->id,*stream,2);
 fn_801B2354(&o->curve,stream);
}
void fn_801F7810(Channel*o,void*context){
 if(o->curve.size){
  if(o->curve[o->curve.size-1].value)fn_8024A1AC(context,o,0);
  else fn_8024A430(context,o,0);
 }
}
void fn_801F7880(Channel*o,short*index,void*context,float time){
 float value;
 if(o->curve.size){
  *index=fn_801B0AA0(&o->curve,&value,*index,time);
  if(value)fn_8024A1AC(context,o,0);
  else fn_8024A430(context,o,0);
 }
}
}
