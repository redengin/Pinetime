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
Building
--------------------------------------------------------------------------------
To **build** the project, everything is simplified via docker.

To create the docker image:
```sh
# From the checked-out directory
docker build -t pinetime-build docker/pinetime-build
```
Once you have the docker image, you don't need to re-run the above.

To build use:
```sh
./docker/build.sh
```
Development
--------------------------------------------------------------------------------
You have great ideas for how you'd like to use a watch.

To realize those ideas:
* you can create an ISSUE
* you can develop a [solution](docs/development.md)

Playing
--------------------------------------------------------------------------------
You can see what apps in a simulation.
* [LVGL local](https://docs.lvgl.io/latest/en/html/get-started/pc-simulator.html)
* [LVGL in a Webpage](https://github.com/lvgl/lv_sim_emscripten)


