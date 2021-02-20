#!/bin/sh

DEMOS_PATH="$(pwd)/build/emscripten/"
echo $DEMOS_PATH
HTTP_PORT="${HTTP_PORT:=8080}"
docker run --rm -t \
    --user "$(id -u):$(id -g)" \
    --volume "$DEMOS_PATH":"$DEMOS_PATH":ro --workdir "$DEMOS_PATH" \
    -p "$HTTP_PORT":8080 \
    lvgl-emscripten \
        python3 -m http.server 8080
