Main `Activities` for the Pinetime
================================================================================
The activities in this folder are provided as the base UX to the Pinetime.
If you have additional functionality that isn't a primary function of Pinetime
(games) then these should be `dynamic activities`.

Creating an Activity
================================================================================
Copy the [template/](template/) into a new folder.

Follow the guidance in the template to add functionality.

Getting your Activity to the Screen
================================================================================
The primary activities will be persistent on the Pinetime. If you have a primary
activity, it will need to be added to this repository and incorporated upon
main().

If your activity is secondary (game), then your activity can be sent to the
`App Manager` and be launched via the `App Manager` screen under the primary
screen activity.

For more information on dynamically loadable apps, see the
[AppManager](AppManager/README.md).
