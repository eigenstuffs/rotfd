#ifndef GAME_ENGINE_RENDERER_RECTANGLE_CONTROLS_H
#define GAME_ENGINE_RENDERER_RECTANGLE_CONTROLS_H

namespace RendererRectangleControls {
typedef unsigned char u8;
typedef unsigned short u16;
struct Vec2 { float x, y; };
struct Color { float r, g, b, a; };
struct Owner {
    char pad[0x2D0];
    u16 flags2D0, flags2D2;
    char pad2D4[0x4C];
    float projection[16], screen[16];
};
}

extern "C" {
void fn_8027F178(RendererRectangleControls::Owner* self,
    const RendererRectangleControls::Vec2* start,
    const RendererRectangleControls::Vec2* end,
    const RendererRectangleControls::Color* top,
    const RendererRectangleControls::Color* bottom, float depth);
void fn_8027F460(RendererRectangleControls::Owner* self,
    const RendererRectangleControls::Vec2* start,
    const RendererRectangleControls::Vec2* end,
    const RendererRectangleControls::Vec2* uvStart,
    const RendererRectangleControls::Vec2* uvEnd,
    const RendererRectangleControls::Color* color, float depth);
void fn_8027F710(RendererRectangleControls::Owner* self,
    const RendererRectangleControls::Vec2* start,
    const RendererRectangleControls::Vec2* end,
    const RendererRectangleControls::Color* color, float depth);
}

#endif
