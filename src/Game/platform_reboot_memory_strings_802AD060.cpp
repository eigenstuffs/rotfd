// Platform reboot diagnostics and memory-status command strings.
// Existing GLOBAL NUL-separated pools retain every native identity and extent.
// Native class, event, resource and diagnostic strings.
// Pointer tables and boundary alignment retain their separate owners.
extern "C" const char lbl_802AD060[] = "InGameObjectsGC_Z.h";
extern "C" const char lbl_802AD074[] = "WarpGC_Z.h";
extern "C" const char lbl_802AD080[] = "ParticlesGC_Z.h";
extern "C" const char lbl_802AD090[] = "Particles_Z.h";
extern "C" const char lbl_802AD0A0[] = "SurfaceGC_Z.h";
extern "C" const char lbl_802AD0B0[] = "RotShapeGC_Z.h";
extern "C" const char lbl_802AD0C0[] = "MeshGC_Z.h";
extern "C" const char lbl_802AD0CC[] = "LodGC_Z.h";
extern "C" const char lbl_802AD0D8[] = "SkelGC_Z.h";
extern "C" const char lbl_802AD0E4[] = "SkinGC_Z.h";
extern "C" const char lbl_802AD0F0[] = "MaterialGC_Z.h";
extern "C" const char lbl_802AD100[] = "Too much parameters";

extern "C" const char lbl_802AD114[88] =
    "Nb Frames ???\0\0\0" // +0x0
    "Got reset data as DEADBEEF!\0" // +0x10
    "Reset data as %x, length = %d\0\0\0" // +0x2C
    "/USER.TSC\0\0"; // +0x4C

extern "C" const char lbl_802AD16C[61] =
    "Got no reboot data!****************************************8"; // +0x0

extern "C" const char lbl_802AD1AC[548] =
    "Got reboot data, sizewanted = %d, actual size = %d****************************************\0\0" // +0x0
    "Got RESET data!****************************************\n\0\0\0\0" // +0x5C
    "Got DEADBEEF RESET data!****************************************\n\0\0\0" // +0x98
    "No Comment\0\0" // +0xDC
    "SetFrame\0\0\0\0" // +0xE8
    "PrintMemStatus\0\0" // +0xF4
    "PrintSoundStats\0" // +0x104
    "PrintMemStatus Command\0\0" // +0x114
    ">              start       end         size         usage\n\0\0" // +0x12C
    ">     ELF      0x%08x  0x%08x  %08d ko\n\0" // +0x168
    ">     STACK    0x%08x  0x%08x  %08d ko\n\0" // +0x190
    ">     DBSTACK  0x%08x  0x%08x  %08d ko\n\0" // +0x1B8
    ">     HEAP     0x%08x  0x%08x  %08d ko  %.2f mo\n\0\0\0\0" // +0x1E0
    "Memory Status\0\0"; // +0x214
