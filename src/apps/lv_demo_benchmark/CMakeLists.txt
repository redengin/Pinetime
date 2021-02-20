file(GLOB_RECURSE LVGL_DEMOS "/opt/emscripten/lv_examples/src/*.c")
add_library("lv_demo_benchmark"
    ${LVGL_DEMOS}
)
target_link_libraries("lv_demo_benchmark"
    PUBLIC
        "lvgl"
)