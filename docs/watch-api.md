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

Architecture
================================================================================
GATT (A low power Bluetooth interface)
--------------------------------------------------------------------------------
GATT is a communication method that conserves power. A service under GATT is
essentially a synchronized property set (with each property limited to 512 bytes).

```plantuml
[REMOTE]
[WATCH] -> SERVICE : <GATT>
[REMOTE] -down-> SERVICE : <GATT>
```

WATCH is both compute and power constrained. **As much as possible the REMOTE
should perform compute.**

REMOTE (a cellphone) has much greater compute efficiency and power stores.

Local (On-watch)
--------------------------------------------------------------------------------
To minimize power consumption of the watch, the watch hardware is put into the
lowest power mode possible. The system decides the power mode based upon the
needs of the active local software.

```plantuml
class System {
    BleGatt
    EventBus
    Display
}

class Activity {
    State
    LVGL
}

System *- Activity
```
### LVGL (simply create GUI applications)
The [LVGL](https://docs.lvgl.io/latest/en/html/index.html) framework
simplifies development of GUI activities. The `Activity` class provides a
unique `LVGL` instance.

### Event Bus
LVGL provides it's own event bus. When *displayed*, the LVGL event bus
will receive it's subscribed events.

If your application needs events while not displayed, you should use
the `PineTime Event Bus`. The `PineTime Event Bus` will propagate
system level events (GATT attribute change, local sensor change).

In general, `events` should synchronize a local state structure.
This `state structure` is used to determine what to display once
the `Activity` becomes active, and as well can used to restore
the state of an `Activity` across power upset.


