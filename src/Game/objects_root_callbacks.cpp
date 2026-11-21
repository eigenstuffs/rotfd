// Reconstructed upper callbacks and native Manipulator table ownership.
#include "manipulator_callbacks_internal.h"

// These original callbacks have no exception-table entries.
#pragma exceptions off

void Manipulator_Z::slot34() {}

void Manipulator_Z::slot3C() {
    accumulated = 0.0f;
    fn_80213A18(this);
}

void Manipulator_Z::slot2C(float delta) {
    accumulated += delta;
    slot38(delta);
}

Manipulator_Z::Manipulator_Z() {
    accumulated = 0.0f;
}

// Emit the out-of-line weak destructor with its original exception specification.
#pragma exceptions on
