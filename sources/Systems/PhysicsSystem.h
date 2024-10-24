#pragma once
#include "ecs.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

class PhysicsSystem : public System
{
    public:
        SYSTEM_CONSTRUCTOR(PhysicsSystem);
        void Update() override;
};
