#include "System.hpp"
#include "apps/WatchFace.hpp"

#include <assert.h>

// create the System resource repository and event bus
static Pinetime::System mSystem;

int main(void) {

    // add the main display
    static Pinetime::DefaultActivity defaultActivity;
    std::unique_ptr<Pinetime::Activity> pDefaultActivity(&defaultActivity);
    assert(pDefaultActivity.get() != nullptr);
    mSystem.add(pDefaultActivity);

    // add faces to UX
    std::unique_ptr<Pinetime::FaceActivity> pWatchFace(new Pinetime::apps::WatchFace);
    assert(pWatchFace.get() != nullptr);
    defaultActivity.add(pWatchFace);

    // add DFU activity (over-the-air update)
    // std::unique_ptr<Pinetime::Activity> pDfu(new Pinetime::DfuActivity);
    // mSystem.add(pDfu);

    vTaskStartScheduler();

    // scheduler should never return
    return -1;
}


extern "C"
void vApplicationIdleHook(void) {
    // FIXME go into LPO/event driven mode to conserve power
    // TODO what is this?
    // lv_tick_inc(1);
}

extern "C"
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    // kill the task
    vTaskDelete(NULL);
    // restart the task
    mSystem.retry(pxTask);
}

