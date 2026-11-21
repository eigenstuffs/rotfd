// Append a timeline sample in recording mode, or advance its playback cursor.
typedef unsigned long TimelineWord801C8480;
extern "C" {
extern char lbl_8028F698[];
extern const float lbl_8037A408;
void*fn_8028FAF4(void*,void*,TimelineWord801C8480,TimelineWord801C8480);
void*fn_8028FF24(void*,TimelineWord801C8480);
void fn_8028FD50(void*,void*,TimelineWord801C8480);
}
inline void*operator new(TimelineWord801C8480,void*p){return p;}
struct TimelineRecord801C8480 {
    float time;
    float sample[7];
    TimelineRecord801C8480(float stamp,float value):time(stamp){sample[0]=value;sample[1]=value;sample[2]=value;sample[3]=value;sample[4]=value;sample[5]=value;sample[6]=value;}
};
struct TimelineState801C8480 {
    char unknown00[0x1C];
    float time;
    char unknown20[4];
    unsigned char mode;
    char unknown25[3];
    int count,capacity;
    TimelineRecord801C8480*records;
    int current;
    void grow(int amount){
        int wanted=capacity+amount;
        if(wanted){
            if(records)records=(TimelineRecord801C8480*)fn_8028FAF4(lbl_8028F698,records,capacity*sizeof(TimelineRecord801C8480),wanted*sizeof(TimelineRecord801C8480));
            else records=(TimelineRecord801C8480*)fn_8028FF24(lbl_8028F698,wanted*sizeof(TimelineRecord801C8480));
        }else if(records){fn_8028FD50(lbl_8028F698,records,capacity*sizeof(TimelineRecord801C8480));records=0;}
        capacity+=amount;
    }
    TimelineRecord801C8480*append(){if(count+1>capacity)grow(64);return &records[count++];}
};
extern "C" void fn_801C8480(TimelineState801C8480*self){
    if(self->mode==2){
        float stamp=self->time;
        // Native code carries an uninitialized FPR into all seven sample fields.
        float sample;
        new(self->append())TimelineRecord801C8480(stamp,sample);
    }else if(self->mode==1){
        self->current++;
        if(self->current>=self->count){self->current=0;self->time=lbl_8037A408;}
    }
}
