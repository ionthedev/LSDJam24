cmake_minimum_required(VERSION 3.14) # Increased minimum version for FetchContent
project(LSDJAM CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    Jolt
    GIT_REPOSITORY https://github.com/jrouwe/JoltPhysics.git
    GIT_TAG master
    SOURCE_SUBDIR "Build"
)
FetchContent_MakeAvailable(Jolt)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

set(PCH_FILE "${CMAKE_CURRENT_LIST_DIR}/includes/PH_PCH.h")

# First collect all your sources and includes
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp")
file(GLOB_RECURSE PROJECT_INCLUDES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/includes/*.h")
get_filename_component(INCLUDES_DIR "${CMAKE_CURRENT_LIST_DIR}/includes" ABSOLUTE)

# Then create the target
add_executable(${PROJECT_NAME})

# Then set sources and includes
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDES_DIR}
    ${raylib_SOURCE_DIR}/src
    ${Jolt_SOURCE_DIR}/Jolt
    ${spdlog_SOURCE_DIR}/include
    ${glm_SOURCE_DIR}
)

# And finally link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE raylib spdlog Jolt glm)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH_FILE})

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
