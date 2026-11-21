// Viewport_Z.cpp storage and lifetime; names describe recovered ABI roles.
#include "viewport_storage_internal.h"
extern "C" void fn_801E2E04(Viewport_801E300C* self, const ViewportHandle2& h) {
    self->handle10 = h;
}
extern "C" void fn_801E2E70(const Viewport_801E300C* self, int* left, int* top, int* right, int* bottom) {
    *left = self->left;
    *top = self->top;
    *right = self->right;
    *bottom = self->bottom;
}
extern "C" void fn_801E2E94(Viewport_801E300C* self, int left, int top, int right, int bottom) {
    self->left = left;
    self->top = top;
    self->right = right;
    self->bottom = bottom;
}
ViewportRecord_801E2EA8::ViewportRecord_801E2EA8() {}
ViewportEntry_801E2F08::ViewportEntry_801E2F08() {}
Handle_8002F6B0::Handle_8002F6B0() { value = 0; }
Viewport_801E300C::~Viewport_801E300C() { delete[] records; }
Viewport_801E300C::Viewport_801E300C() : field48(0) { records = new ViewportRecord_801E2EA8[12]; }
