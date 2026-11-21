/* Texture-palette descriptor getter. See docs/notes/TPL.md for attribution. */
typedef unsigned long u32;

typedef struct TPLHeader TPLHeader;
typedef struct TPLClutHeader TPLClutHeader;

typedef struct TPLDescriptor {
    TPLHeader* textureHeader;
    TPLClutHeader* CLUTHeader;
} TPLDescriptor;

typedef struct TPLPalette {
    u32 versionNumber;
    u32 numDescriptors;
    TPLDescriptor* descriptorArray;
} TPLPalette;

TPLDescriptor* TPLGet(TPLPalette* pal, u32 id)
{
    return &pal->descriptorArray[id];
}
