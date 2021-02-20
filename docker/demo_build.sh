#!/bin/sh

if [ ! -f "$1/CMakeLists.txt" ]
then
    echo "ERROR: $0 <path to activity with lvlg app>"
    exit
fi
LVGL_APP_PATH=$(realpath $1)

# CONVENTION: expects the app hook to follow the path name
EXPECTED_HOOK="$(basename lv_$LVGL_APP_PATH)"
# provide CHOSEN_DEMO environment variable if app doesn't follow convention
CHOSEN_DEMO="${CHOSEN_DEMO:=${EXPECTED_HOOK}}"
echo CHOSEN_DEMO = $CHOSEN_DEMO

docker run --rm -t \
    --user "$(id -u):$(id -g)" \
    --volume $(pwd):$(pwd) -w $(pwd) \
    lvgl-emscripten \
        cmake \
        -DCMAKE_TOOLCHAIN_FILE="/opt/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" \
        -DLVGL_APP="$LVGL_APP_PATH" \
        -DCHOSEN_DEMO="$CHOSEN_DEMO" \
        -S "docker/lvgl-emscripten/" \
        -B "build/emscripten"

docker run --rm -t \
    --user "$(id -u):$(id -g)" \
    --volume $(pwd):$(pwd) -w $(pwd) \
    lvgl-emscripten \
        cmake --build build/emscripten -j
