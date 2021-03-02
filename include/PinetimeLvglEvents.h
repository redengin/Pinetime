#pragma once

/**
 * To decouple LVGL implementation from PineTime, the Pinetime::Application
 * sends System level events to the LVGL default screen. (see /docs/watch-api.md)
 * In this way, LVGL implementations do not require Pinetime specific methods
 * but simply a comprehension of the system level events at the LVGL context.
 */

#include <stddef.h>
#include <stdint.h>

/// system events published to lvgl implementations via lv_event_send(lv_scr_act()...)
enum LV_SYSTEM_EVENT {
// BATTERY EVENTS
    LV_SYSTEM_EVENT_BATTERY_CHARGING,
    LV_SYSTEM_EVENT_BATTERY_REMAINING,
// TIME EVENTS
    LV_SYSTEM_EVENT_CURRENT_TIME,   ///< should be used instead of LVGL timers
// GATT PROPERTY EVENTS (sent upon remote change to local properties)
    LV_SYSTEM_EVENT_GATT_PROPERTY,
// NOTE: please extend this as necessary for your APP, and either implement
//  the necessary event bus modifications or create an ISSUE to have your
//  event supported.
};

// definitions for lv_event_get_data()
//------------------------------------------------------------------------------
struct BATTERY_REMAINING {
    size_t remaining;
};

struct CURRENT_TIME {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint16_t millisecond;
};

struct GATT_PROPERTY {
    char* name;         ///< null-terminated string
    uint8_t* value;
    size_t value_sz;
};
