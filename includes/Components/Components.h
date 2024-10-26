#pragma once
#include "raylib.h"
#include "rcamera.h"
#include "Core/ecs.h"


class InputComponent : public Component
{
    public:
        DEFINE_COMPONENT(InputComponent);
        float CurrentSpeed = 100.0f;
        float WalkSpeed = 100.0f;
        float SprintSpeed = 200.0f;
        float TurnSpeed = 180.0f;
};
class TransformComponent : public Component
{
    public:
        DEFINE_COMPONENT(TransformComponent);
        Vector3 Position = {0, 0, 0};
        Quaternion Rotation = {1, 0, 0, 0};
        Vector3 EulerRotation = { 0, 0, 0};
        Vector3 Scale = {1, 1, 1};
};
class CameraComponent : public Component
{
    public:
        DEFINE_COMPONENT(CameraComponent);
        Camera3D Camera;
        float FOV;
        int Projection = CAMERA_FIRST_PERSON;
        TransformComponent Transform;
        Vector3 Target;
};
