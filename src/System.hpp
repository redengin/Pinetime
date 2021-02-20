#pragma once

#include <vector>
#include <memory>
#include <FreeRTOS.h>
#include <task.h>
#include "GattServer.hpp"

namespace Pinetime {

// forward declarations
class Activity;

class System {
public:
    explicit System(GattServer& gattServer)
        : mGattServer(gattServer){};
    virtual ~System() { /* FIXME */ };

    /**
     * will call Activity::onAdd() to allow the application
     * to acquire any resources it needs (thread(s), BLE service(s))
     */
    bool add(std::unique_ptr<Activity>&); 
    bool remove(std::unique_ptr<Activity>&); 

    /* when the scheduler has nothing left to do, go into the
     * lowest power mode that will support registred system needs
     */
    void idle(void);

    /** should a task blow it's stack, attempt to restart it */
    void retry(const TaskHandle_t&) { /* FIXME */ };

protected:
    GattServer &mGattServer;

private:
    std::vector<Activity> mActivities;
    struct TaskEntry {
        TaskHandle_t& mHandle;
        size_t mRetries;
        TaskEntry(TaskHandle_t& handle)
        : mHandle(handle)
        {}
    };
    std::vector<TaskEntry> mTasks;

}; // end class System


class Activity {
public:
    explicit Activity();
    virtual ~Activity();

    /**
     * called upon adding the activity to the system
     */
    virtual bool onAdd() { return true; }
}; // end class Activity


} // end namespace Pinetime