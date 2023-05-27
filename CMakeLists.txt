cmake_minimum_required(VERSION 3.25.0)
project(Markov_Midi VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_options(${PROJECT_NAME} PRIVATE 	-D__WINDOWS_MM__)
target_link_libraries(${PROJECT_NAME} Winmm)
install(TARGETS ${PROJECT_NAME})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
