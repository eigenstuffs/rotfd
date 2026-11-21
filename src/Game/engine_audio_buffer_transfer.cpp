#include "Game/engine_audio_buffer_transfer.h"
#include "Game/platform_disc_read.h"
typedef unsigned long AudioTransferWord;
struct AudioTransferRequest {
    AudioTransferWord code, index, size, offset, marker;
    AudioTransferRequest*next;
};
struct AudioTransferStream {
    AudioTransferWord size;
    char file[0x3C];
    AudioTransferWord begin, current, total, remaining, end, flags;
    int type;
};
struct AudioTransferVoice {
    AudioTransferWord unknown00, buffer;
    char unknown08[0x34];
};
struct AudioTransferQueue {
    AudioTransferStream streams[6];
    AudioTransferVoice voices[4];
    char unknown318[8];
    AudioTransferWord mainBuffer;
    char unknown324[0x6E8];
    AudioTransferRequest*head;
    AudioTransferRequest*tail;
    AudioTransferWord count;
    AudioTransferRequest*pending;
    AudioTransferWord unknownA1C, unknownA20, state;
    char unknownA28[0x40AC];
    char*buffer;
};
struct AudioTransferOwner{
    char unknown00[0x420];
    AudioTransferQueue queue;
};
struct AudioTransferGlobal{
    char unknown00[0x158];
    AudioTransferOwner*audio;
    char unknown15C[0x30];
    void*media;
};
extern "C" {
    extern AudioTransferGlobal lbl_801E9D24;
    extern char lbl_801EF5C8[], lbl_802AF56C[], lbl_802AF57C[], lbl_8035E9CC[];
    extern signed char lbl_803780D8;
    void fn_8028531C(void*);
    void*fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
    void fn_801EF610(void*, void*);
    void*memcpy(void*, const void*, unsigned long);
    void*memset(void*, int, unsigned long);
    int OSEnableInterrupts();
    void OSRestoreInterrupts(int);
    void fn_80288210(AudioTransferQueue*, signed char);
    void fn_80287E48(AudioTransferQueue*, signed char);
    void fn_80288BD4(int, void*);
}
static inline AudioTransferStream*getStream(AudioTransferQueue*q, int index){
    return (AudioTransferStream*)((char*)q+index*0x5C);
}
static inline AudioTransferRequest*getPending(AudioTransferQueue*q){
    if (q->pending){
        if (q->streams[q->pending->index].type==2)return q->pending;
    }
    return q->head;
}
static inline void abortCurrent(AudioTransferQueue*q, signed char immediate){
    int interrupts=OSEnableInterrupts();
    AudioTransferRequest*r=q->pending;
    AudioTransferStream*s=getStream(q, r->index);
    q->state=0x1104;
    s->flags&=~0x100U;
    if (s->type==1)fn_80288210(q, immediate);
    else if (s->type!=3)fn_80287E48(q, immediate);
    OSRestoreInterrupts(interrupts);
}
static inline void popCurrent(AudioTransferQueue*q){
    int interrupts=OSEnableInterrupts();
    AudioTransferRequest*r=getPending(q);
    AudioTransferStream*s=getStream(q, r->index);
    q->state=0x1104;
    s->flags&=~0x100U;
    if (s->type==1)fn_80288210(q, 0);
    else if (s->type!=3)fn_80287E48(q, 0);
    if (q->count<2){
        q->head=0;
        q->tail=0;
        q->count=0;
    }
    else{
        q->head=q->head->next;
        q->count--;
    }
    OSRestoreInterrupts(interrupts);
}
extern "C" void fn_80288630(AudioTransferQueue*self, AudioTransferRequest*request, AudioTransferStream*stream, signed char immediate){
    if (request||stream){
        if ((stream->flags&2)&&request->code==0x1102){
            fn_8028531C(lbl_801E9D24.media);
            AudioTransferWord remaining=stream->remaining;
            AudioTransferWord size=request->size;
            if (remaining<size){
                AudioTransferWord aligned=(remaining+31)&~31U;
                size-=remaining;
                fn_8028EEEC(self, stream->file, self->buffer, aligned, request->offset);
                if (!(stream->flags&0x1000)){
                    if (stream->flags&0x800){
                        if (request->marker==~0U){
                            char*temp=(char*)fn_801EFA1C(lbl_801EF5C8, size, lbl_802AF56C, lbl_802AF57C, 0x4E3, 32);
                            if (stream->flags&0x80000000)fn_8028EEEC(self, stream->file, temp, (size+31)&~31U, stream->begin);
                            else fn_8028EEEC(self, stream->file, temp, (size+31)&~31U, stream->begin+0x60);
                            memcpy(self->buffer+stream->remaining, temp, size);
                            fn_801EF610(lbl_801EF5C8, temp);
                        }
                    }
                    else{
                        memset(self->buffer+stream->remaining, 0, 0x8400-stream->remaining);
                        if (stream->type&1){
                            AudioTransferVoice*v=&self->voices[request->index];
                            if (stream->flags&0x10)stream->end=v->buffer+stream->remaining;
                            else if (stream->flags&0x20)stream->end=(v->buffer+(stream->size>>1))+stream->remaining;
                        }
                        else if (stream->type&2){
                            if (stream->flags&0x10)stream->end=self->mainBuffer+stream->remaining;
                            else if (stream->flags&0x20)stream->end=(self->mainBuffer+(stream->size>>1))+stream->remaining;
                        }
                    }
                }
                self->state=0x1100;
                if (immediate)abortCurrent(&lbl_801E9D24.audio->queue, 1);
                else popCurrent(&lbl_801E9D24.audio->queue);
                stream->current=aligned+stream->begin;
                stream->remaining=stream->total-(stream->current-stream->begin);
                if (!(stream->flags&0x800))stream->flags|=0x200;
            }
            else{
                AudioTransferWord offset=request->offset;
                self->state=0x1100;
                if (request->marker==~0U){
                    if (immediate){
                        if (!lbl_803780D8){
                            fn_8028EEEC(self, stream->file, self->buffer, size, offset);
                            memcpy(lbl_8035E9CC, self->buffer, size);
                            lbl_803780D8=1;
                        }
                        else memcpy(self->buffer, lbl_8035E9CC, size);
                        if ((stream->type&2)&&offset==0)memset(self->buffer, 0, 0x200);
                        abortCurrent(&lbl_801E9D24.audio->queue, 1);
                    }
                    else DVDReadAsyncPrio(stream->file, self->buffer, size, offset, fn_80288BD4, 2);
                }
                else abortCurrent(&lbl_801E9D24.audio->queue, 1);
                stream->current=request->offset+request->size;
                stream->remaining=stream->total-(stream->current-stream->begin);
            }
        }
    }
}
typedef char AudioTransferRequestSize[(sizeof(AudioTransferRequest) == 24) ? 1 : -1];
typedef char AudioTransferStreamSize[(sizeof(AudioTransferStream) == 92) ? 1 : -1];
typedef char AudioTransferVoiceSize[(sizeof(AudioTransferVoice) == 60) ? 1 : -1];
typedef char AudioTransferQueueSize[(sizeof(AudioTransferQueue) == 0x4AD8) ? 1 : -1];
