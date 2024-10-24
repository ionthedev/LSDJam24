#pragma once
#include "ecs.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

class InputSystem : public System
{
    public:
        SYSTEM_CONSTRUCTOR(InputSystem);
        void Update() override;
};
