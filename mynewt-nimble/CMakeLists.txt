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
add_library("nimble"
    ${NIMBLE_SOURCES}
)
target_include_directories("nimble"
    PUBLIC
        "${project_nimble_SOURCE_DIR}/nimble/include/"
        "${project_nimble_SOURCE_DIR}/nimble/controller/include/"
        "${project_nimble_SOURCE_DIR}/porting/nimble/include/"
)
target_link_libraries("nimble"
    PUBLIC
        "freertos"
        "freertos-port"
        "nimble-config"
        "nimble-port"
)
target_compile_definitions("nimble"
    PUBLIC
        "-DMYNEWT_VAL_OS_CPUTIME_FREQ=32768"
)
target_compile_options("nimble"
    PRIVATE
        "-Wno-pedantic" # IGNORE non-pedantic code
)

# Nimble config
add_library(nimble-config INTERFACE)
target_include_directories("nimble-config" INTERFACE ".")

# Nimble NRF52/FreeRTOS port
add_library("nimble-port"
    "${project_nimble_SOURCE_DIR}/nimble/drivers/nrf52/src/ble_hw.c"
    "${project_nimble_SOURCE_DIR}/nimble/drivers/nrf52/src/ble_phy.c"
    # "${project_nimble_SOURCE_DIR}/porting/npl/freertos/src/nimble_port_freertos.c"
)
target_include_directories("nimble-port"
    PUBLIC
        "${project_nimble_SOURCE_DIR}/porting/npl/freertos/include/"
        "${project_nimble_SOURCE_DIR}/nimble/drivers/nrf52/include/"
)
target_link_libraries("nimble-port"
    PRIVATE
        "freertos"
        "nimble"
)
target_compile_options("nimble-port"
    PRIVATE
        "-Wno-pedantic" # IGNORE non-pedantic code
)
