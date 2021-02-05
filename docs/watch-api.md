Architecture
================================================================================
```plantuml
[REMOTE]
[WATCH] -> SERVICE : <GATT>
[REMOTE] -down-> SERVICE : <GATT>
```
<GATT>
--------------------------------------------------------------------------------
GATT is a communication method that conserves power. A service under GATT is
essentially a synchronized property set (with each property limited to 512 bytes).

WATCH is both compute and power constrained. As much as possible the REMOTE
should perform compute.

REMOTE is often a phone, which has much greater compute efficiency and power
stores.

Application
================================================================================
To satisfy the user, the full experience must be understood well.
```plantuml
(intent) -> (response)
```
* intent - what the user desires (both *explicit control* and *automatic control*)
    * as an example to differentiate *explicit control* from *automatic control*
        * EXPLICIT CONTROL - user sets the time
        * AUTOMATIC CONTROL - the REMOTE and WATCH coordinate to determine the
            current time
* response - how do you best inform the user using both the WATCH and REMOTE?


WatchIt
================================================================================
A WatchIt executes inside the watch hardware.
```plantuml
[WATCHIT] --> [SPECIALIZED SERVICE] : <GATT>
[WATCHIT] --> [SERVICE] : <GATT>
[WATCHIT] --> [LOCAL]
```
SPECIALIZED SERVICE - provides unique properties of the application
SERVICE - provides generic properties of the WATCH and REMOTE
LOCAL - provides ability to change watch behavior (display, vibration)

