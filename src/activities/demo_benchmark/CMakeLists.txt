# apply convention - activity name must match lvgl hook for demo_build.sh
get_filename_component(ACTIVITY_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable GIT_PROGRESS output
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable update pull (certain repos require git credentials to pull updates)
FetchContent_Declare("project_lvgl-emscripten"
    GIT_REPOSITORY "https://github.com/littlevgl/emscripten.git"
    GIT_SHALLOW ON
    GIT_PROGRESS ON
    BUILD_COMMAND OFF
)

# Pull / Configuration
# -------------------------------------------------------------------------------
FetchContent_Populate("project_lvgl-emscripten")
file(GLOB_RECURSE "LVGL_SOURCES" "${project_lvgl-emscripten_SOURCE_DIR}/src/*.c")

file(GLOB_RECURSE LVGL_DEMOS
    "${project_lvgl-emscripten_SOURCE_DIR}/lv_examples/assets/*.c"
    "${project_lvgl-emscripten_SOURCE_DIR}/lv_examples/src/lv_demo_benchmark/*.c"
    "${project_lvgl-emscripten_SOURCE_DIR}/lv_examples/src/lv_ex_get_started/*.c"
    "${project_lvgl-emscripten_SOURCE_DIR}/lv_examples/src/lv_ex_style/*.c"
    "${project_lvgl-emscripten_SOURCE_DIR}/lv_examples/src/lv_ex_widgets/*.c"
)
add_library("${ACTIVITY_NAME}"
    ${LVGL_DEMOS}
)
target_link_libraries("${ACTIVITY_NAME}"
    PUBLIC
        "lvgl"
)
# WORKAROUND for bad upstream source
target_compile_options("demo_benchmark"
    PRIVATE
        "-Wno-pedantic"
)