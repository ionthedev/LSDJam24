

#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"

#include "Core/CoreFwd.h"
#include "Components/Components.h"
#include "Systems/Systems.h"
#include "Core/ecs.h"
#include "Core/Log.h"
#include "Core/GameObject.h"

#include <spdlog/spdlog.h>
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


#include <functional>
#include <iostream>
#include <stdint.h>
#include <cstdint>
