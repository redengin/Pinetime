file(GLOB_RECURSE LVGL_DEMOS
    "/opt/emscripten/lv_examples/src/assets/*.c"
    "/opt/emscripten/lv_examples/src/lv_demo_benchmark/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_get_started/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_style/*.c"
    "/opt/emscripten/lv_examples/src/lv_ex_widgets/*.c"
)
add_library("lv_demo_benchmark"
    ${LVGL_DEMOS}
)
target_link_libraries("lv_demo_benchmark"
    PUBLIC
        "lvgl"
)