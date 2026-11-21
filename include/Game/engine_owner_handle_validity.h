#ifndef GAME_ENGINE_OWNER_HANDLE_VALIDITY_H
#define GAME_ENGINE_OWNER_HANDLE_VALIDITY_H
struct OwnerValidityHandle {unsigned long value;};
extern "C" {
unsigned long fn_801F7EB8(const OwnerValidityHandle*);
signed char fn_8023C2AC(const OwnerValidityHandle*);
}
#endif
