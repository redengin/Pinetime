#!/bin/sh

docker run --rm -t \
    --user "$(id -u):$(id -g)" \
    --volume $(pwd):$(pwd) -w $(pwd) \
    pinetime-build
