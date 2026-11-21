struct FlagMemberPrefix {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x20];

    signed char hasFlags(unsigned long long mask) const
    {
        return (flags & mask) ? 1 : 0;
    }
};

struct FlagMemberFirst {
    char unknown00[0x30];
};

struct FlagMemberSecond {
    char unknown00[0x30];
};

struct FlagMemberOwner : FlagMemberPrefix, FlagMemberFirst, FlagMemberSecond {};

extern "C" void* fn_8005EE10(FlagMemberOwner* self)
{
    if (self->hasFlags(0x10000000ULL))
        return static_cast<FlagMemberSecond*>(self);

    if (self->flags & 0x10000000000ULL)
        return static_cast<FlagMemberSecond*>(self);

    if (self->flags & 0x20000000000ULL)
        return static_cast<FlagMemberSecond*>(self);

    if (self->flags & 0x8000000000ULL)
        return static_cast<FlagMemberFirst*>(self);

    return 0;
}
