# apply convention - activity name must match lvgl hook for demo_build.sh
get_filename_component(ACTIVITY_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

file(GLOB_RECURSE LVGL_DEMOS
    "/opt/emscripten/lv_examples/src/assets/*.c"
    "/opt/emscripten/lv_examples/src/lv_demo_benchmark/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_get_started/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_style/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_widgets/*.c"
)
add_library("${ACTIVITY_NAME}"
    ${LVGL_DEMOS}
)
target_link_libraries("${ACTIVITY_NAME}"
    PUBLIC
        "lvgl"
)