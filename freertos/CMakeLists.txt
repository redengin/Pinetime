include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable GIT_PROGRESS output
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable update pull (certain repos require git credentials to pull updates)
FetchContent_Declare("project_freertos"
    GIT_REPOSITORY "https://github.com/FreeRTOS/FreeRTOS-Kernel.git"
    GIT_TAG "main"
    GIT_SHALLOW ON
    GIT_PROGRESS ON
    BUILD_COMMAND OFF
)

# FreeRTOS Pull / Configuration
# -------------------------------------------------------------------------------
FetchContent_Populate("project_freertos")
add_library("freertos-kernel"
    "${project_freertos_SOURCE_DIR}/croutine.c"
    "${project_freertos_SOURCE_DIR}/event_groups.c"
    "${project_freertos_SOURCE_DIR}/portable/MemMang/heap_4.c"
    "${project_freertos_SOURCE_DIR}/list.c"
    "${project_freertos_SOURCE_DIR}/queue.c"
    "${project_freertos_SOURCE_DIR}/stream_buffer.c"
    "${project_freertos_SOURCE_DIR}/tasks.c"
    "${project_freertos_SOURCE_DIR}/timers.c")
target_include_directories("freertos-kernel"
    PUBLIC "${project_freertos_SOURCE_DIR}/include/")
target_link_libraries("freertos-kernel"
    PRIVATE
        "nrfsdk"
        "freertos")

# FreeRTOS NRF52 port
add_library("freertos"
    "${project_freertos_SOURCE_DIR}/portable/GCC/ARM_CM4F/port.c")
target_include_directories("freertos"
    PUBLIC
        "."
        "${project_freertos_SOURCE_DIR}/include/"
        "${project_freertos_SOURCE_DIR}/portable/GCC/ARM_CM4F/")
target_link_libraries("freertos"
    PUBLIC
        "freertos-kernel"
    PRIVATE
        "nrfsdk")