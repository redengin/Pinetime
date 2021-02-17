#!/bin/sh

if [ ! -f "$1/CMakeLists.txt" ]
then
    echo "ERROR: $0 <path to lvgl app>"
    exit
fi
LVGL_APP_PATH=$(realpath $1)

# CONVENTION: expects the app hook to follow the path name
EXPECTED_HOOK="$(basename $LVGL_APP_PATH)"
# provide CHOSEN_DEMO environment variable if app doesn't follow convention
CHOSEN_DEMO="${CHOSEN_DEMO:=${EXPECTED_HOOK}}"
echo CHOSEN_DEMO = $CHOSEN_DEMO

DEMOS_PATH="$(pwd)/build/emscripten/"
echo $DEMOS_PATH
HTTP_PORT="${HTTP_PORT:=8080}"
docker run --rm -it \
    --user "$(id -u):$(id -g)" \
    --volume "$DEMOS_PATH":"$DEMOS_PATH":ro --workdir "$DEMOS_PATH" \
    -p "$HTTP_PORT":8080 \
    lvgl-emscripten \
        python3 -m http.server 8080
