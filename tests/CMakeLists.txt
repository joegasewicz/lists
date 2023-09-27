cmake_minimum_required(VERSION 3.26)
project(tests C)

set(CMAKE_C_STANDARD 11)

add_library(
        lists STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../lists.c
)
set_target_properties(lists PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../cmake-build-debug/liblists.a)

add_executable(tests main.c)

target_link_libraries(tests PRIVATE lists)
target_link_libraries(tests PRIVATE cmocka)