#include <vector>

class WatchIt; // TODO

class Face {
public:
    Face(std::vector<WatchIt> &watchIts)
    :   mWatchIts(watchIts)
    {
        for(auto watchIt : mWatchIts)
            pinetime_subscribe(watchIt.EVENTS);
    }
    virtual ~Face();
private:
    const std::vector<WatchIt> &mWatchIts;
};
