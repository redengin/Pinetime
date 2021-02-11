#pragma once

#include <vector>
#include <memory>
#include <FreeRTOS.h>
#include <task.h>

namespace Pinetime {

// forward declarations
class Activity;

class System {
public:
    explicit System();
    virtual ~System();

    /**
     * will call Activity::onAdd() to allow the application
     * to acquire any resources it needs (thread(s), BLE service(s))
     */
    bool add(std::unique_ptr<Activity>&); 
    bool remove(std::unique_ptr<Activity>&); 

    void retry(const TaskHandle_t&);
protected:

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


// FIXME move to separate file
class DefaultActivity : public Activity {
public:
    explicit DefaultActivity();
    virtual ~DefaultActivity();

private:
}; // end class Pinetime


// FIXME move to separate file
class DfuActivity : public Activity {
public:
    explicit DfuActivity();
    virtual ~DfuActivity();

private:
}; // end class Pinetime



} // end namespace Pinetime