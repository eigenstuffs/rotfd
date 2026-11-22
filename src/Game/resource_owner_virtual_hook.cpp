namespace ResourceOwnerLayout_80027A08 {
struct Prefix { unsigned long unknown00[2]; };
struct Primary : Prefix { virtual ~Primary(); char unknown0C[0x30C]; };
struct Secondary { virtual ~Secondary(); virtual void hook_80028134(); char unknown04[0x28]; };
}
struct ResourceOwnerVirtualView_80027A08 : ResourceOwnerLayout_80027A08::Primary,
    ResourceOwnerLayout_80027A08::Secondary {
    virtual void hook_80028134();
    virtual ~ResourceOwnerVirtualView_80027A08();
    void** resources;
};
void ResourceOwnerVirtualView_80027A08::hook_80028134() {}
