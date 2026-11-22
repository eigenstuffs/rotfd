struct FlaggedResultRecord { unsigned char unknown00[12]; unsigned long flags; };
extern "C" int fn_80247E24(void*, void*, const FlaggedResultRecord* record) {
    if (record->flags & 1) return 0;
    return 0;
}
