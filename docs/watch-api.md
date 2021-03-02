(the following contains PlantUML diagrams)

Application
================================================================================
To satisfy the user, the full experience must be understood.
```plantuml
(intent) -> (response)
```
* intent - what the user desires (both *explicit control* and *automatic control*)
    * as an example to differentiate *explicit control* from *automatic control*
        * EXPLICIT CONTROL - user sets the time
        * AUTOMATIC CONTROL - the REMOTE and WATCH coordinate to determine the
            current time
* response - what does the WATCH need to do to support the user?
    * this is where you as an application designer provide the magic
        (display, touch, etc.)

Architecture
================================================================================
Application Development
--------------------------------------------------------------------------------
[LVGL](https://docs.lvgl.io/v6/en/html/index.html) is the preferred method to
create app UX. In this way the application can be developed and demo using an
LVGL emulator independent of Pinetime.  
(see [how to launch demos](docker/README.md]))

To integrate the app in to the Pinetime, the LVGL implementation creates a
`screen` level callback to handle Pinetime system events
(see [Pinetime LVGL System Events](../include/PinetimeLvglEvents.h))
```c
void lv_... {
    lv_obj_set_event_cb(lv_scr_act(), systemEventHandler);
}

static void systemEventHandler(lv_obj_t* scr, lv_event_t event) {
    ....
}
```

To integrate the LVGL implementation to the Pinetime, you also need to provide
an LvglApplication class implementation.  
For a starting point see [examples/pinetimeApp]()

Minimizing Power Usage
--------------------------------------------------------------------------------
To minimize power consumption of the watch, the watch hardware is put into the
lowest possible power mode. The system decides the what hardware to disable
based upon the needs of the active local software.

The largest power consumption is while the display is active. To minimize power
an Applications are suspended while the display is inactive.

To satisfy the user, Services are created to handle the functionalities that
don't require UX. For example a time-sync can be handled without the need to
enable the display.

As services may desire a display, they can raise up an intent via an event to
allow an active application to promote itself to the display. For example, the
DFU Service (firmware update), can publish a DFU event and promote an
Application to *displayable* to allow the user to monitor/cancel the update.

Service Design
--------------------------------------------------------------------------------
Where the Applications focus on the user experience, Services are necessary
to coordinate the the UX to both local and remote influences. Each service is
created to handle specific influences.

#### GATT
A GATT service essentially a synchronized property set.
```plantuml
[WATCH] -> SERVICE : <GATT>
[REMOTE] -down-> SERVICE : <GATT>
```
Applications can leverage these service properties via GATT events.

### PineTime::Application Life-cycle
--------------------------------------------------------------------------------
```plantuml
[*] -> onCreate
onCreate : restore persisted data
onCreate : subscribe to background events <with intent to display>
onCreate --> onStart : <displayed>
onStart : launch LVGL code
onStart --> [*] : <resources reclaimed>
```
* onCreate  
    Background events are published by a `Service` (see [services](#services))  
* onStart  
    The PineTime::Application provides a private LVGL screen for `lv_src_act()`
    to handle UX via LVGL. This private LVGL screen instance will only receive
    events while displayed.  
* Destruction (resources reclaimed)  
    As the memory is limited on embedded devices, the application may be
    destroyed to make room for other applications.

NOTE: the application can be interrupted at any time (resource need, or power cycle)  
    To persist data across these interruptions, the application should leverage the
    [LVGL file system interfaces](https://docs.lvgl.io/latest/en/html/overview/file-system.html).

Application UX Convention
--------------------------------------------------------------------------------
The Pinetime manages displayed applications as a stack. The button on the
PineTime is used to pop the stack (display the previous application).
<details>
If your application would like to use the button, the PineTime::Application can
register for button events. A long hold of the button will be trapped by the
System to force leaving the application.
</details>
