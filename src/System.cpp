#include "System.hpp"

using namespace Pinetime;

System::System() {

}

System::~System() {

}

bool System::add(std::unique_ptr<Activity>& pActivity) {
    // TODO
    return false;
}

bool System::remove(std::unique_ptr<Activity>& pActivity) {
    // TODO
    return false;
}

void System::retry(const TaskHandle_t&) {

}
