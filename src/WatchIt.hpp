#pragma once

enum class Swipe {UP, DOWN, LEFT, RIGHT};
struct TouchPosition {
    unsigned int x;
    unsigned int y;
};
typedef DoubleTap :: TouchPosition;
typedef Tap :: TouchPosition;
struct Event {
    unsigned int id;
    unsigned int size_bytes;
    char data[];
};

class WatchIt {
    WatchIt();
    virtual ~WatchIt();

    virtual void onSwipe(const Swipe) {}
    virtual void onDoubleTap(const DoubleTap) {}
    virtual void onTap(const Tap) {}
    virtual void onEvent(const Event) {}

    createService(const GATT service);
};
