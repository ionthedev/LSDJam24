#pragma once
#include "Components/Components.h"

class GameObject {
  public:
    static uint64_t Create(ECS& ecs) {
        uint64_t entityId = ecs.GetNewEntity();
        auto transform = ecs.GetComponent<TransformComponent>(entityId);
        return entityId;
    }

    static void Destroy(ECS& ecs, uint64_t entityId)
    {
        ecs.RemoveEntity(entityId);
    }
};
