cmake_minimum_required(VERSION 3.17)

# Target Toolchain Configuration
#-------------------------------------------------------------------------------
# NRF52 Toolchain settings
set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CPU_FLAGS "-mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16")
string(CONCAT COMMON_FLAGS
    "-MP -MD ${CPU_FLAGS} -mthumb -mabi=aapcs"
    " -Wall -Werror -Wreturn-type -Werror=return-type"
    " -ffunction-sections -fdata-sections -fno-strict-aliasing"
    " -fno-builtin --short-enums")
set(CMAKE_C_FLAGS "${COMMON_FLAGS} -std=c17")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_ASM_FLAGS "-MP -MD -std=c99 -x assembler-with-cpp")
string(CONCAT CMAKE_EXE_LINKER_FLAGS
    "-mthumb -mabi=aapcs ${CPU_FLAGS}"
    " -L ${NRF5_SDK_PATH}/modules/nrfx/mdk"
    " -L${CMAKE_SOURCE_DIR} -Tgcc_nrf52.ld"
    " -Wl,--gc-sections --specs=nano.specs -lc -lnosys -lm")
# note: we must override the default cmake linker flags so that CMAKE_C_FLAGS are not added implicitly
set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_COMPILER} <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_C_COMPILER} <LINK_FLAGS> <OBJECTS> -lstdc++ -o <TARGET> <LINK_LIBRARIES>")

project(pinetime
    VERSION 0.1.0
    LANGUAGES ASM C CXX
)
# create static binaries
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# turn on pedantic static-analysis (code smell)
string(APPEND CMAKE_C_FLAGS " -pedantic-errors")
string(APPEND CMAKE_CXX_FLAGS " -pedantic-errors")
# disable CMake searching magic
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Fetch NRFSDK
include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # enable verbose info
set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # disable re-pull
FetchContent_Declare("project_nrfsdk"
    URL "https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5SDK1702d674dde.zip"
    URL_HASH "MD5=a04e2f76e712689aa1dff13969696af3")
FetchContent_Populate("project_nrfsdk")
add_library("nrfsdk"
    "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/system_nrf52.c"
    "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/gcc_startup_nrf52.S")
target_compile_definitions("nrfsdk" PUBLIC "-DNRF52832_XXAA" "-DFREERTOS")
target_include_directories("nrfsdk"
    PUBLIC
        "${project_nrfsdk_SOURCE_DIR}/modules/nrfx/mdk/"
        "${project_nrfsdk_SOURCE_DIR}/components/toolchain/cmsis/include/"
        "${project_nrfsdk_SOURCE_DIR}/components/drivers_nrf/nrf_soc_nosd/"
        "${project_nrfsdk_SOURCE_DIR}/components/libraries/util/")

# Fetch and Configure FreeRTOS
add_subdirectory("freertos")

add_executable(pinetime
    "main.cpp"
)