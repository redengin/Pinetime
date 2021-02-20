cmake_minimum_required(VERSION 3.13)

project("demos")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -s USE_SDL=2")

# use the emscripten lvgl hardware drivers
# NOTE: browsers app's will only receive events based upon emscripten driver support
file(GLOB_RECURSE "LVGL_DRIVERS_SOURCE" "/opt/emscripten/lv_drivers/*.c")
add_library("lvgl-drivers" ${LVGL_DRIVERS_SOURCE})
target_link_libraries("lvgl-drivers"
    PRIVATE
        "lvgl"
)
# use the provided lvgl library headers
target_compile_definitions("lvgl-drivers"
    PRIVATE
        "-DLV_LVGL_H_INCLUDE_SIMPLE"
)
target_include_directories("lvgl-drivers"
    PRIVATE
        "/opt/emscripten/"
)

# TODO use the project version of LVGL
# add_subdirectory("../../lvgl" "lvgl")

# use the emscripten LVGL core
file(GLOB_RECURSE "LVGL_CORE_SOURCE" "/opt/emscripten/lvgl/*.c")
add_library("lvgl"
    "${LVGL_CORE_SOURCE}"
)
target_include_directories("lvgl"
    PUBLIC
        "/opt/emscripten/"
        "/opt/emscripten/lvgl/"
)
target_link_libraries("lvgl"
    PRIVATE
        "lvgl-drivers"
)

# add the demo's source
add_subdirectory("${LVGL_APP}" "${CHOSEN_DEMO}")

# build the demo
set(CMAKE_EXECUTABLE_SUFFIX ".html")
add_executable("demo_${CHOSEN_DEMO}"
    "/opt/emscripten/main.c"
)
target_compile_definitions("demo_${CHOSEN_DEMO}"
    PUBLIC
        "-DCHOSEN_DEMO=${CHOSEN_DEMO}"
)
target_include_directories("demo_${CHOSEN_DEMO}"
    PRIVATE
        "/opt/emscripten/"
)
target_link_libraries("demo_${CHOSEN_DEMO}"
    PUBLIC
        "lvgl"
        "${CHOSEN_DEMO}"
)
# add the entry point
set_target_properties("demo_${CHOSEN_DEMO}"
    PROPERTIES
        LINK_FLAGS "--shell-file /opt/emscripten/lvgl_shell.html")
