#pragma once

#include "ecs.h"

#include "raylib.h"
#include "raymath.h"

#include <functional>
#include <stdint.h>

class InputComponent : public Component
{
    public:
        DEFINE_COMPONENT(InputComponent);
        float CurrentSpeed = 100.0f;
        float WalkSpeed = 100.0f;
        float SprintSpeed = 200.0f;
        float TurnSpeed = 180.0f;
};
