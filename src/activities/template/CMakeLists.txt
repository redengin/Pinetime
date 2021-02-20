# apply convention - activity name must match lvgl hook for demo_build.sh
get_filename_component(ACTIVITY_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

add_library("${ACTIVITY_NAME}"
# add your source files here
)

target_link_libraries("${ACTIVITY_NAME}"
    PUBLIC
        "lvgl"
)