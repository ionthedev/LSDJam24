#pragma once
#include "ecs.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

class RenderingSystem : public System
{
    public:
        SYSTEM_CONSTRUCTOR(RenderingSystem);
        void Update() override;
};
