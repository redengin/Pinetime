#include <FreeRTOS.h>
#include <task.h>
#include <assert.h>

#include "System.hpp"

static Pinetime::System mSystem;

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
    // go into LPO/event driven mode to conserve power
    mSystem.idle();
}

extern "C"
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    // kill the task
    vTaskDelete(NULL);
    // restart the task
    mSystem.retry(pxTask);
}

