#ifndef GAME_ENGINE_TEXT_DISPLAY_DISPATCH_H
#define GAME_ENGINE_TEXT_DISPLAY_DISPATCH_H

// Partial renderer views; unobserved fields retain their original offsets.
namespace TextDisplayDispatch {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3 {
    float x, y, z;
    inline Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    inline Vec3 operator+(const Vec3& v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
};
struct Color { float r, g, b, a; };
struct ByteColor { u8 r, g, b, a; };
struct Mesh {
    void* positions;
    void* normals;
    void* colors;
    void* texcoords;
};
struct Buffer {
    void* data;
    u32 capacity, size;
};
struct Material {
    char pad[0xC];
    Color color;
};
struct Light {
    char pad[0x84];
    Vec3 ambient;
    char pad90[12];
    Vec3 diffuse;
};
struct Record {
    u16 flags, next;
    Buffer* display;
    Mesh* mesh;
    Material* material;
    float matrix[12];
    float texmatrix[16];
    Light* light;
    u32 mode;
    Color color;
    void* positions;
    void* normals;
    void* colors;
    void* texcoords;
};
struct Owner {
    char pad[0x2D0];
    u16 flags2D0, flags2D2;
    char pad2D4[0xD8];
    char* records;
    u32 pending;

    inline Record* at(u16 i) { return (Record*)(records + i * 0xA8); }
    inline Mesh* mesh(u16 i) { return *(Mesh**)(records + i * 0xA8 + 8); }
    inline Material* material(u16 i)
    {
        return *(Material**)(records + i * 0xA8 + 0xC);
    }
    inline Light* light(u16 i)
    {
        return *(Light**)(records + i * 0xA8 + 0x80);
    }
    inline void* array(u16 i, int offset)
    {
        return *(void**)(records + i * 0xA8 + offset);
    }
    inline float* transform(u16 i)
    {
        return (float*)(records + i * 0xA8 + 0x10);
    }
    inline Color* color(u16 i)
    {
        return (Color*)(records + i * 0xA8 + 0x88);
    }
};
}

extern "C" void fn_8027DC70(TextDisplayDispatch::Owner* self);

#endif
