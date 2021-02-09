include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable GIT_PROGRESS output
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable update pull (certain repos require git credentials to pull updates)
FetchContent_Declare("project_lvgl"
    GIT_REPOSITORY "https://github.com/lvgl/lvgl.git"
    GIT_SHALLOW ON
    GIT_PROGRESS ON
    BUILD_COMMAND OFF
)

# FreeRTOS Pull / Configuration
# -------------------------------------------------------------------------------
FetchContent_Populate("project_lvgl")
file(GLOB_RECURSE "LVGL_SOURCES" "${project_lvgl_SOURCE_DIR}/src/*.c")
add_library("lvgl"
    ${LVGL_SOURCES}
)
target_include_directories("lvgl"
    PRIVATE
        "."
    PUBLIC
        "${project_lvgl_SOURCE_DIR}/src/"
)