cmake_minimum_required(VERSION 3.0.0)

project(Platformer VERSION 0.1.0)

file(GLOB_RECURSE TARGET_SRC    "./src/*.cpp"
                                "./src/*.c" )

add_executable(Platformer ${TARGET_SRC})

set_target_properties(Platformer PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(Platformer PRIVATE Threads::Threads
                            glfw
                            OpenGL::GL
                            )

target_include_directories(Platformer PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/src"
                            "${PROJECT_SOURCE_DIR}/src/Extern"
                            )

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
