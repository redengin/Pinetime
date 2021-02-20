cmake_minimum_required(VERSION 3.13)

project("demos")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -s USE_SDL=2")

file(GLOB_RECURSE LVGL_DRIVERS "/opt/emscripten/lv_drivers/*.c")
file(GLOB_RECURSE LVGL_CORE "/opt/emscripten/lvgl/*.c")

add_library("lvgl"
    ${LVGL_DRIVERS}
    ${LVGL_CORE}
)
target_include_directories("lvgl"
    PUBLIC
        # "${CMAKE_CURRENT_SOURCE_DIR}/../../lvgl"
        "/opt/emscripten/"
        "/opt/emscripten/lvgl/"
)
target_compile_definitions("lvgl"
    PUBLIC
        "-DCHOSEN_DEMO=${CHOSEN_DEMO}"
)

add_subdirectory("${LVGL_APP}" "${CHOSEN_DEMO}")

set(CMAKE_EXECUTABLE_SUFFIX ".html")
add_executable("demo_${CHOSEN_DEMO}"
    "/opt/emscripten/main.c"
)
target_link_libraries("demo_${CHOSEN_DEMO}"
    PUBLIC
        "lvgl"
        "${CHOSEN_DEMO}"
)
set_target_properties("demo_${CHOSEN_DEMO}"
    PROPERTIES
        LINK_FLAGS "--shell-file /opt/emscripten/lvgl_shell.html")
