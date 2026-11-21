#include "Game/platform_native_interface_tables.h"
extern "C" {
void fn_8023BAF8(void *);
char fn_801F5E14(RegistryBase *);
OwnerLifecycleFixed * fn_8020B7DC(OwnerLifecycleFixed *, int);
int fn_8023BAF0(void);
void fn_8020C5B8(void);
void fn_8023ADA4(void);
void fn_8023ADA8(void);
void fn_8003FBC0(void);
void fn_8023ADAC(void);
void fn_80031288(void);
void fn_8003303C(void);
float fn_80030A00(void);
void fn_80033038(void);
float fn_800309F8(void);
void fn_8023AF04(void);
void fn_8003FBC4(void);
void fn_8003D0CC(void);
void fn_8003CF2C(void);
int fn_8005728C(void);
int fn_8023B03C(PlatformAudioUpdateOwner *, const OwnerHandle &, unsigned long, const OwnerHandle &, const OwnerHandle &);
int fn_8023AF08(PlatformAudioUpdateOwner *, const OwnerHandle &, const OwnerHandle &, float);
int fn_8023ADB0(void);
void fn_801C9CC4(void *);
void fn_8003128C(void);
void fn_80031650(void);
AudioOwnerOperationsTable lbl_802EC030 = { 0, 0, fn_8023BAF8, fn_801F5E14, fn_8020B7DC, fn_8023BAF0, fn_8020C5B8, fn_8023ADA4, fn_8023ADA8, fn_8003FBC0, fn_8023ADAC, fn_80031288, fn_8003303C, fn_80030A00, fn_80033038, fn_800309F8, fn_8023AF04, fn_8003FBC4, fn_8003D0CC, fn_8003CF2C, fn_8005728C, fn_8023B03C, fn_8023AF08, fn_8023ADB0, fn_801C9CC4, fn_8003128C, fn_80031650 };
}
typedef char CheckTableSize[sizeof(AudioOwnerOperationsTable) == 108 ? 1 : -1];
