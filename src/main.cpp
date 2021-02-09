#include <assert.h>
#include <FreeRTOS.h>
#include <task.h>

int main(void) {

    // create master thread
    // TODO

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

