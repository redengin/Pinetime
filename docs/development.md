Where can you make a difference?
================================================================================
* General developers - need to understand how their design impacts power usage
* Embedded developers - need to understand the low-level details

General Development
================================================================================
To minimize the power usage of the watch, the focus should be on differentiating
between compute required by the watch vs other compute resources (phone). Where
compute can be performed outside of the watch, the result can be easily plumbed
into the watch output resources (display, vibration).

For on-watch API see [watch-api](watch-api.md).

Embedded Development (Things running on the watch)
================================================================================
The focus of embedded development SDK is to ensure that the General Development
isn't impacted by low-level concerns.

Leverage the exploration of hardware from all the available sources, commit
changes to them (in this way others will be able to stand upon the shoulders
of giants).
