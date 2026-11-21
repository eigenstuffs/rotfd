/* Audio stream DVD-read completion callback (fn_80288BD4) and the streaming
   worker thread loop (fn_80288D00). Compiled as C: the callback passes the
   int-typed (result == -10) flag. */
typedef unsigned long u32;
typedef unsigned short u16;
typedef struct AXVPBView AXVPBView;
typedef struct StreamRequest StreamRequest;
typedef struct StreamRecord StreamRecord;
typedef struct StreamVoice StreamVoice;
typedef struct StreamMutex StreamMutex;
typedef struct StreamRegistry StreamRegistry;
typedef struct StreamState StreamState;
typedef struct StreamOwner StreamOwner;
typedef struct StreamGlobal StreamGlobal;
struct AXVPBView {
    char unknown000[0x146];
    u16 state;
    char unknown148[0x66];
    u16 endAddressHi, endAddressLo, currentAddressHi, currentAddressLo;
};
struct StreamRequest {
    u32 code, index, size, offset, marker;
    StreamRequest*next;
};
struct StreamRecord {
    u32 size;
    char file[0x3C];
    u32 begin, current, total, remaining, end, flags;
    int type;
};
struct StreamVoice {
    AXVPBView*voice[2];
    u32 buffer;
    void*unknown0C;
    u32 unknown10;
    u32 half, nextHalf;
    char unknown1C[0x18];
    u32 played, queued;
};
struct StreamMutex { void*head,*tail,*thread; long count; void*next,*prev; };
struct StreamRegistry {
    char path[0x100];
    int kind;
    unsigned char loop;
    char pad105[3];
    int cookie;
    StreamRegistry*next;
};
struct StreamState {
    StreamRecord records[6];
    StreamVoice voices[6];
    char unknown390[0x2C0];
    void*queue[2];
    char unknown658[0x1C];
    StreamRequest requests[38];
    u32 writeIndex, immediateIndex;
    StreamRequest*head;
    StreamRequest*tail;
    u32 count;
    StreamRequest*pending;
    StreamRequest*pendingTail;
    u32 pendingCount;
    int state;
    char unknownA28[0x4044];
    float musicLevel, effectsLevel;
};
struct StreamOwner {
    char unknown00[0x420];
    StreamState state;
};
struct StreamGlobal {
    char unknown00[0x110];
    void*logger;
    char unknown114[0x44];
    StreamOwner*audio;
};
extern StreamGlobal lbl_801E9D24;
extern char lbl_801EF5C8[];
extern char lbl_802AF594[];
extern StreamMutex lbl_8035E958;
extern StreamRegistry*lbl_803780D0;
int OSEnableInterrupts();
void OSRestoreInterrupts(int);
void OSSleepThread(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void VIWaitForRetrace();
void fn_801FA014(void*, const char*, ...);
void fn_801EF610(void*, void*);
void fn_80289ADC(StreamState*, StreamRegistry*, int, unsigned char, int);
void fn_80288210(StreamState*, int);
void fn_80287E48(StreamState*, int);
void fn_80288630(StreamState*, StreamRequest*, StreamRecord*, int);
void fn_8028A4F0(StreamState*, int);
int fn_8028F29C(StreamState*);
void MIXSetInput(AXVPBView*, int);
void MIXInitChannel(AXVPBView*, u32, int, int, int, int, int, u32);
void AXSetVoiceLoop(AXVPBView*, u32);
void AXSetVoiceState(AXVPBView*, u32);
void AXSetVoiceType(AXVPBView*, u32);

void fn_80288BD4(int result, void*arg){
    StreamState*q=&lbl_801E9D24.audio->state;
    int interrupts=OSEnableInterrupts();
    StreamRequest*r;
    StreamRecord*s;
    int immediate;
    if (result==-10) r=q->pending;
    else if (q->pending&&q->records[q->pending->index].type==2) r=q->pending;
    else r=q->head;
    s=&q->records[r->index];
    q->state=0x1104;
    immediate=result==-10;
    s->flags&=~0x100U;
    if (s->type==1) fn_80288210(q, immediate);
    else if (s->type!=3) fn_80287E48(q, immediate);
    if (result!=-10){
        if (q->count<2){
            q->head=0;
            q->tail=0;
            q->count=0;
        }
        else{
            q->head=q->head->next;
            q->count--;
        }
    }
    OSRestoreInterrupts(interrupts);
}

static inline void abortPending(StreamState*q){
    int interrupts=OSEnableInterrupts();
    StreamRequest*r=q->pending;
    StreamRecord*s=&q->records[r->index];
    q->state=0x1104;
    s->flags&=~0x100U;
    if (s->type==1) fn_80288210(q, 1);
    else if (s->type!=3) fn_80287E48(q, 1);
    OSRestoreInterrupts(interrupts);
}

static inline void submitPending(StreamState*self, u32 code, u32 index, u32 size, u32 offset, u32 marker){
    StreamRequest*r=&self->requests[self->immediateIndex+32];
    r->code=code;
    r->offset=offset;
    r->index=index;
    r->size=size;
    r->marker=marker;
    r->next=0;
    self->immediateIndex++;
    if (self->immediateIndex>=6) self->immediateIndex=0;
    if (self->pendingCount==0){
        self->pending=r;
        self->pendingTail=r;
    }
    else{
        self->pendingTail->next=r;
        self->pendingTail=r;
    }
    self->pendingCount++;
    if (r->marker!=~0U) abortPending(&lbl_801E9D24.audio->state);
}

static inline void submit(StreamState*self, u32 code, u32 index, u32 size, u32 offset, u32 marker){
    StreamRequest*r=&self->requests[self->writeIndex];
    r->code=code;
    r->offset=offset;
    r->index=index;
    r->size=size;
    r->next=0;
    r->marker=marker;
    self->writeIndex++;
    if (self->writeIndex>=32) self->writeIndex=0;
    if (self->count==0){
        self->head=r;
        self->tail=r;
    }
    else{
        self->tail->next=r;
        self->tail=r;
    }
    self->count++;
    if (r->marker!=~0U) abortPending(&lbl_801E9D24.audio->state);
}

static inline void processRegistry(StreamState*self){
    StreamRegistry*node;
    OSLockMutex(&lbl_8035E958);
    node=lbl_803780D0;
    lbl_803780D0=0;
    OSUnlockMutex(&lbl_8035E958);
    while (node){
        fn_801FA014(lbl_801E9D24.logger, lbl_802AF594, node);
        fn_80289ADC(self, node, node->kind, node->loop, node->cookie);
        fn_801EF610(lbl_801EF5C8, node);
        node=node->next;
    }
}

void fn_80288D00(void*arg){
    StreamState*self=(StreamState*)arg;
    for (;;){
        u32 i;
        OSSleepThread(self->queue);
        processRegistry(self);
        VIWaitForRetrace();
        for (i=0; i<5; i++){
            StreamRecord*rec=&self->records[i];
            StreamVoice*voice=&self->voices[i];
            if (!(rec->flags&2)) continue;
            if (rec->flags&0x40) continue;
            if (rec->flags&0x100) continue;
            if (rec->flags&0x80) continue;
            if (rec->flags&4){
                u32 loop=rec->flags&0x80000000;
                int skip;
                if (loop) skip=0;
                else if (rec->type==1) skip=0x60;
                else if (rec->type==2) skip=0x40;
                else skip=0;
                if (loop) submitPending(self, 0x1102, i, rec->size+skip, rec->begin, 1);
                else submitPending(self, 0x1102, i, rec->size+skip, rec->begin, ~0U);
                if (!rec->flags&0x80000000) rec->flags|=0x100;
            }
            else if (rec->flags&8){
                if (rec->type==1){
                    MIXSetInput(voice->voice[0], (int)self->effectsLevel);
                    AXSetVoiceLoop(voice->voice[0], 0);
                    AXSetVoiceState(voice->voice[0], 1);
                }
                else if (rec->type==2){
                    MIXInitChannel(self->voices[4].voice[0], 0, 0, -904, -904, 0, 0x7F, 0);
                    MIXInitChannel(self->voices[4].voice[1], 0, 0, -904, -904, 0x7F, 0x7F, 0);
                    AXSetVoiceState(self->voices[4].voice[0], 1);
                    AXSetVoiceState(self->voices[4].voice[1], 1);
                    MIXSetInput(self->voices[4].voice[0], (int)self->musicLevel);
                    MIXSetInput(self->voices[4].voice[1], (int)self->musicLevel);
                }
                rec->flags|=0x10;
                rec->flags&=~0x20U;
                rec->flags&=~8U;
            }
            else if ((rec->flags&0x1000)||(rec->flags&0x400)){
                AXVPBView*p=voice->voice[0];
                u32 end=(p->endAddressHi<<16)|p->endAddressLo;
                u32 cur=(p->currentAddressHi<<16)|p->currentAddressLo;
                if (!p->state||end<=cur+0x20) fn_8028A4F0(self, i);
            }
            else if (rec->type==1){
                AXVPBView*p=voice->voice[0];
                u32 end=(p->endAddressHi<<16)|p->endAddressLo;
                u32 cur=(p->currentAddressHi<<16)|p->currentAddressLo;
                if (!p->state||end<=cur+0x20) fn_8028A4F0(self, i);
                if (voice->queued!=voice->played){
                    if (rec->flags&0x80000000) submit(self, 0x1102, i, rec->size>>1, rec->current, 1);
                    else submit(self, 0x1102, i, rec->size>>1, rec->current, ~0U);
                    if (rec->flags&0x200){
                        rec->flags&=~0x200U;
                        rec->flags|=0x400;
                        AXSetVoiceType(voice->voice[0], 0);
                        AXSetVoiceLoop(voice->voice[0], 0);
                    }
                    rec->flags|=0x100;
                    voice->played=voice->queued;
                }
            }
            else if (rec->type==2){
                AXVPBView*p=self->voices[4].voice[0];
                if (((p->currentAddressHi<<16)|p->currentAddressLo)>(self->voices[4].buffer>>1)+(rec->size>>3)) self->voices[4].nextHalf=1;
                else self->voices[4].nextHalf=0;
                if (self->voices[4].nextHalf!=self->voices[4].half){
                    submit(self, 0x1102, 4, rec->size>>1, rec->current, ~0U);
                    if (rec->flags&0x200){
                        rec->flags&=~0x200U;
                        rec->flags|=0x400;
                        AXSetVoiceType(voice->voice[0], 0);
                        AXSetVoiceLoop(voice->voice[0], 0);
                    }
                    rec->flags|=0x100;
                    self->voices[4].half=self->voices[4].nextHalf;
                }
            }
        }
        fn_8028F29C(self);
        if (self->state==0x1100&&self->count!=0) continue;
        if (self->pendingCount!=0){
            while (self->pendingCount!=0){
                fn_80288630(self, self->pending, &self->records[self->pending->index], 1);
                if (self->pendingCount<2){
                    self->pending=0;
                    self->pendingTail=0;
                    self->pendingCount=0;
                }
                else{
                    self->pending=self->pending->next;
                    self->pendingCount--;
                }
            }
        }
        else if (self->count!=0){
            fn_80288630(self, self->head, &self->records[self->head->index], 0);
        }
    }
}
