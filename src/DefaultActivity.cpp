#include "System.hpp"

using namespace Pinetime;

DefaultActivity::DefaultActivity() {

}

DefaultActivity::~DefaultActivity() {

}

bool DefaultActivity::add(std::unique_ptr<FaceActivity>&) {
    // TODO
    return false;
}

bool DefaultActivity::remove(std::unique_ptr<FaceActivity>&) {
    // TODO
    return false;
}
