add_library("lv_benchmark"
    "lv_demo_benchmark.c"
)
target_link_libraries("lv_benchmark"
    PUBLIC
        "lvgl"
)