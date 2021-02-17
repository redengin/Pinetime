What is a **Watch** (what makes a wearable useful)
================================================================================
* **Available** - presents the information and control when you need it.
    * minimize the need for charging
* **Simple** - accessing information is intuitive

Take a test-drive
--------------------------------------------------------------------------------
TBD <!-- host an LVGL web simulation of this repository -->

Usage
================================================================================
<details>
Docker is used to decouple the host environment from the development
environment. If you wish to not use Docker, you can follow the Dockerfile to
install packages to your local system.
</details>

To create a loadable binary
--------------------------------------------------------------------------------
Once you have [Docker pinetime-build](docker/README.md#build)
```sh
./docker/build.sh
```

To demo an application
--------------------------------------------------------------------------------
Once you have [Docker lvgl-emscripten](docker/README.md#demo)
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

Development
================================================================================
You have great ideas for how you'd like to use a watch.

To realize those ideas:
* create an ISSUE
* develop a [solution](docs/development.md)

