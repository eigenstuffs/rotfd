#include "Game/scene_message_record_controls.h"

extern "C" const char*fn_800C1B0C(SceneMessageRecords*self,const unsigned long*key){for(int i=0;i<self->count;++i){SceneMessageRecord*entry=&self->entries[i];if(entry->key==*key){const char*text=entry->text;if(text)return text;break;}}return self->fallback;}
