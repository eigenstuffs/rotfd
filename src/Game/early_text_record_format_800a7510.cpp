/* Text-record formatting; see docs/notes/game-early-text-record-format.md. */
#include "Game/early_text_record_format_views.h"
extern "C"void fn_800A7510(TextOwner*self,int index,void*output){const char*pool=lbl_8029EC80;TextRecord*record;for(int i=0;i<(record=&self->records[index])->count;++i)record->values[i]=resolveText(self->handle)->query(record->key.value,record->handles[i]);
if((record=&self->records[index])->key==TextName(pool+0x28)){record->text[0]=0;if(lbl_8037767C>0){self->getText(index)[0]=0;int found=-1;switch(lbl_8037767C){case 1:found=fn_800A78E4(self,TextName(pool+0x34));break;case 2:found=fn_800A78E4(self,TextName(pool+0x44));break;case 3:found=fn_800A78E4(self,TextName(pool+0x54));break;case 4:found=fn_800A78E4(self,TextName(pool+0x64));break;}if(found>-1)strcpy(self->getText(index),self->getRecord(found).getText());}}
else if((record=&self->records[index])->key==TextName(pool+0x18)){record->text[0]=0;if(self->savedText&&self->time>lbl_80378F78)strcpy(self->getText(index),self->savedText);}
if(self->records[index].key==TextName(pool+0x18))self->flag=1;else self->flag=0;
fn_801F44DC(output,self->getText(index),self->records[index].values);}
