cmake_minimum_required(VERSION 3.13)

project("demos")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -s USE_SDL=2")

file(GLOB_RECURSE LVGL_DRIVERS "/opt/emscripten/lv_drivers/*.c")
file(GLOB_RECURSE LVGL_CORE "/opt/emscripten/lvgl/*.c")

message("LVGL DRIVER ${LVGL_DRIVERS}")

add_library("lvgl"
    ${LVGL_DRIVERS}
    ${LVGL_CORE}
)
target_include_directories("lvgl"
    PUBLIC
        "/opt/emscripten/"
        "/opt/emscripten/lvgl/"
)
target_compile_definitions("lvgl"
    PUBLIC
        "-DCHOSEN_DEMO=extern void ${CHOSEN_DEMO}"
)
#FIXME use the Pinetime lv_conf.h

add_subdirectory("${LVGL_APP}" "project_${CHOSEN_DEMO}")

set(CMAKE_EXECUTABLE_SUFFIX ".html")
add_executable("demo_${CHOSEN_DEMO}"
    "/opt/emscripten/main.c"
)
target_link_libraries("demo_${CHOSEN_DEMO}"
    PUBLIC
        "lvgl"
)