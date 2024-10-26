// GameObject.cpp
#include "Core/GameObject.h"
#include "Core/ecs.h"
#include "Components/Components.h"

uint64_t GameObject::Create(ECS& ecs) {
    uint64_t entityId = ecs.GetNewEntity();
    TransformComponent* transform = ecs.GetComponent<TransformComponent>(entityId);
    return entityId;
}

void GameObject::Destroy(ECS& ecs, uint64_t entityId) {
    ecs.RemoveEntity(entityId);
}
