cmake_minimum_required(VERSION 3.0.0)
project(gjleveldata VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(gjleveldata GJGameLevel.cpp base64.cpp)
add_executable(gjleveldatatest test.cpp)

target_link_libraries(gjleveldatatest gjleveldata)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
