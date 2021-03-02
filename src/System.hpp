#pragma once

namespace Pinetime {

// forward declarations
class Activity;

class System {
public:
    explicit System();
    virtual ~System() {};

    /* when the scheduler has nothing left to do, go into the
     * lowest power mode that will support registred system needs
     */
    void idle(void) { /* FIXME */ };

    /** should a task blow it's stack, attempt to restart it */
    void retry(const TaskHandle_t&) { /* FIXME */ };

private:
    // GattServer mGattServer;

}; // end class System

} // end namespace Pinetime
