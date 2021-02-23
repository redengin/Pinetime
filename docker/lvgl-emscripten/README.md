Create a web demonstration of your application
================================================================================

Gotchas
================================================================================
The current emscripten port is tightly coupled to an earlier version of LVGL.
As such, your demos will reflect the `lv_conf.h` inside emscripten (rather
than the project's).

FIXME: fix the [emscripten port](https://github.com/littlevgl/emscripten) to
decouple it from an LVGL version.
