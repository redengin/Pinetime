Docker images
================================================================================
Docker puts things in there place so that you don't have to install packages and
then later have to decide what to remove from your host system.


<a id="build">Build</a> (Pinetime Exectuable)
================================================================================
To create the Docker build image
```sh
docker build -t pinetime-build docker/pinetime-build
```

<a id="demo">Demo</a> (Web Application)
================================================================================
To create the Docker demo image
```sh
docker build -t lvgl-emscripten docker/lvgl-emscripten
```


