include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable GIT_PROGRESS output
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable update pull (certain repos require git credentials to pull updates)
FetchContent_Declare("project_nimble"
    GIT_REPOSITORY "https://github.com/apache/mynewt-nimble.git"
    GIT_SHALLOW ON
    GIT_PROGRESS ON
    BUILD_COMMAND OFF
)

# Pull / Configuration
# -------------------------------------------------------------------------------
FetchContent_Populate("project_nimble")
file(GLOB_RECURSE "NIMBLE_SOURCES" "${project_nimble_SOURCE_DIR}/nimble/*.c")
add_library("nimble-kernel"
    ${NIMBLE_SOURCES}
)
target_include_directories("nimble-kernel"
    PUBLIC
        "${project_nimble_SOURCE_DIR}/nimble/include/"
        "${project_nimble_SOURCE_DIR}/nimble/controller/include/"
)
target_link_libraries("nimble-kernel"
    PRIVATE
        "nimble"
)
target_compile_definitions("nimble-kernel"
    PUBLIC
        "-DMYNEWT_VAL_OS_CPUTIME_FREQ=32768"
)
target_compile_options("nimble-kernel"
    PRIVATE
        "-Wno-pedantic" # IGNORE non-pedantic code
)

# Nimble NRF52 port
add_library("nimble"
    "${project_nimble_SOURCE_DIR}/porting/npl/freertos/src/nimble_port_freertos.c")
target_include_directories("nimble"
    PUBLIC
        "${project_nimble_SOURCE_DIR}/porting/nimble/include/"
        "${project_nimble_SOURCE_DIR}/porting/npl/freertos/include/"
        "${project_nimble_SOURCE_DIR}/nimble/drivers/nrf52/include/"
        # "."
#         "${project_nreertos_SOURCE_DIR}/portable/GCC/ARM_CM4F/")
)
target_link_libraries("nimble"
    PUBLIC
        "nimble-kernel"
        # "nrfsdk"
        # "freertos-kernel"
        "freertos"
)