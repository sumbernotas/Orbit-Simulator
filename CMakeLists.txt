cmake_minimum_required(VERSION 3.10)
project(OrbitSim)

set(CMAKE_CXX_STANDARD 20)

# Use vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/Users/sumrx/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "VCPKG toolchain file")

# Dependencies
find_package(Eigen3 REQUIRED)
find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(Bullet CONFIG REQUIRED)

add_executable(OrbitSim src/main.cpp)

# Link libraries
target_link_libraries(OrbitSim PRIVATE Eigen3::Eigen glm::glm glfw OpenGL::GL assimp::assimp BulletDynamics)