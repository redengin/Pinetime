Where can you make a difference?
================================================================================
* General developers - need to understand how to make something
* Embedded developers - need to understand the low-level details

General Development
================================================================================
To minimize the power usage of the watch, the focus should be on differentiating
between compute required by the watch vs other compute resources (phone). Where
compute can be performed outside of the watch, the result can be easily plumbed
into the watch output resources (display, vibration).

For on-watch API see [watch-api](watch-api.md).

Embedded Development
================================================================================
The focus of embedded development is to ensure that the General Development
isn't impacted by low-level concerns.

Leverage the exploration of hardware from all the available sources, commit
changes to them (in this way others will be able to stand upon the shoulders
of giants).
