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
needs of the active local software. The local software registers needs via
subscription to the event bus.

For instance, applications that require *continuous display* will use much more
power than applications that are simply ready to render a display upon a
*look gesture* (the user raises the watch into the field of view).

The design of the *local* software should decouple state from the physical
behavior. For instance, *local* software can process an event to be ready to
paint an update, but the behavior of painting should be tied to a *paint*
event that will be published only while the display is active.
