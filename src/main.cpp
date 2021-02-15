#include <FreeRTOS.h>
#include <task.h>
#include <assert.h>

#include "System.hpp"

// create the System resource repository and event bus
static Pinetime::GattServer gattServer;
static Pinetime::System mSystem(gattServer);

int main(void) {

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

