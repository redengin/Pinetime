include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable verbose info
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable re-pull
FetchContent_Declare("project_nrfsdk"
    URL "https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5SDK1702d674dde.zip"
    URL_HASH "MD5=a04e2f76e712689aa1dff13969696af3")
FetchContent_Populate("project_nrfsdk")
add_library("nrfsdk"
    "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/system_nrf52.c"
    "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/gcc_startup_nrf52.S"
    "${project_nrfsdk_SOURCE_DIR}/integration/nrfx/legacy/nrf_drv_clock.c")
target_compile_definitions("nrfsdk"
    PUBLIC
        "-DNRF52832_XXAA -DBOARD_PCA10040" "-DFREERTOS"
        # Errata
        "-DNRF52_PAN_74 -DNRF52_PAN_64 -DNRF52_PAN_12 -DNRF52_PAN_58"
        "-DNRF52_PAN_54 -DNRF52_PAN_31 -DNRF52_PAN_51 -DNRF52_PAN_36"
        "-DNRF52_PAN_15 -DNRF52_PAN_20 -DNRF52_PAN_55")
target_include_directories("nrfsdk"
    PUBLIC
        "${project_nrfsdk_SOURCE_DIR}/config/nrf52832/config/"
        "${project_nrfsdk_SOURCE_DIR}/integration/nrfx/"
        "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/drivers/include/"
        "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/"
        "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/"
        "${project_nrfsdk_SOURCE_DIR}/components/toolchain/cmsis/include/"
        "${project_nrfsdk_SOURCE_DIR}/components/drivers_nrf/nrf_soc_nosd/"
        "${project_nrfsdk_SOURCE_DIR}/components/libraries/util/")
target_compile_options("nrfsdk"
    PRIVATE
        "-Wno-expansion-to-defined" # IGNORE use of GCC extensions
)
