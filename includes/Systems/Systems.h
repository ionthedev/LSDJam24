#pragma once
#include "raylib.h"
#include "rcamera.h"
#include "Core/ecs.h"

class RenderingSystem : public System
{
    public:
        SYSTEM_CONSTRUCTOR(RenderingSystem);
        void Update() override;
};

class InputSystem : public System
{
    public:
        SYSTEM_CONSTRUCTOR(InputSystem);
        void Update() override;
};
