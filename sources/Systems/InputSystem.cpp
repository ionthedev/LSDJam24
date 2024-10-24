#include "InputSystem.h"

#include "Components/InputComponent.h"
#include "Components/TransformComponent.h"
#include "raylib.h"
#include "raymath.h"
#include "Core/Log.h"
#include <iostream>

void InputSystem::Update()
{
    DoForEachComponent<InputComponent>([this](InputComponent& component)
        {
            float deltaSpeed = component.CurrentSpeed * GetFrameTime();

            TransformComponent* transform = ECSContainer.TryGetComponent<TransformComponent>(component.EntityId);
            if (!transform)
            {
                std::cout <<"FUCK"  << std::endl;
                return;
            }
            Vector3 moveDir = { 0 };

            if (IsKeyDown(KEY_W))
            {
                PH_TRACE("Move Forward");
                moveDir.z += deltaSpeed;
            }

            if (IsKeyDown(KEY_S))
            {
                PH_TRACE("Move Back");
                moveDir.z -= deltaSpeed;
            }

            if (IsKeyDown(KEY_A))
            {
                PH_TRACE("Move Left");
                moveDir.x += deltaSpeed;
            }

            if(IsKeyDown(KEY_D))
            {
                PH_TRACE("Move Right");
                moveDir.x -= deltaSpeed;
            }

            Matrix rotationMatrix = MatrixRotateXYZ(transform->EulerRotation);
            Vector3 rotatedMoveDir = Vector3Transform(moveDir, rotationMatrix);

            // Apply the rotated movement
            transform->Position = Vector3Add(transform->Position, rotatedMoveDir);
        });
}
