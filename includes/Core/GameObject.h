#pragma once
#include "CoreFwd.h"
#include <cstdint>

class GameObject {
  public:
    static uint64_t Create(ECS& ecs);

    static void Destroy(ECS& ecs, uint64_t entityId);
};
