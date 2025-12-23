
# 1 : project metadata
cmake_minimum_required(VERSION 4.0)
project(mothership LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# 2 : source files
file(GLOB_RECURSE PROJECT_SRC
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/main.cpp"
)

# 3 : define what you want (here : an executable)
add_executable(${PROJECT_NAME} ${PROJECT_SRC})

# 4 : add headers to target
target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${PROJECT_SOURCE_DIR}/headers"
)