#pragma once

#include "ecs.h"

#include "raylib.h"
#include "raymath.h"

#include <functional>
#include <stdint.h>

class TransformComponent : public Component
{
    public:
        DEFINE_COMPONENT(TransformComponent);
        Vector3 Position = {0, 0, 0};
        Quaternion Rotation = {1, 0, 0, 0};
        Vector3 EulerRotation = { 0, 0, 0};
        Vector3 Scale = {1, 1, 1};
};
