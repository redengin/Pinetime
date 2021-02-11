#include "System.hpp"

// create the System resource repository and event bus
static Pinetime::System mSystem;

int main(void) {

    // add the main display handler
    std::unique_ptr<Pinetime::Activity> pDefaultActivity(new Pinetime::DefaultActivity);
    mSystem.add(pDefaultActivity);

    // add faces to UX
    // std::unique_ptr<Pinetime::Activity> pWatchFace(new Pinetime::activities::WatchFace);
    // pDefaultActivity.add(pWatchFace);

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

