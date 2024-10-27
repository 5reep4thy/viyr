cmake_minimum_required(VERSION 3.15)
project(viyr)
find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(${PROJECT_NAME} src/backend/main.cpp)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} boost::boost)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       "../src/backend/files/example.json"
                       "./files/example.json"
                   COMMENT "Copying example to build")