Docker images
================================================================================
Docker puts things in there place so that you don't have to install packages and
then later have to decide what to remove from your host system.

Usage
================================================================================
To create a loadable binary
--------------------------------------------------------------------------------
Once you've created a local [Docker image](#build)
```sh
./docker/build.sh
```

To demo an application
--------------------------------------------------------------------------------
Once you've created a local [Docker image](#demo)
* Build it
    ```sh
    ./docker/demo_build.sh
    ```
* Launch the webserver
    ```sh
    ./docker/demo_server.sh
    ```
* Connect to the webserver
    * http://localhost

<a id="build">Build</a> (Pinetime Exectuable)
================================================================================
To create the Docker build image
```sh
docker build -t pinetime-build docker/pinetime-build
```

<a id="demo">Demo</a>
================================================================================
To create the Docker build image
```sh
docker build -t lvgl-emscripten docker/lvgl-emscripten
```


