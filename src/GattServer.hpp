#pragma once

namespace Pinetime {

/* FIXME */
class Service;
class EventHandler;

class GattServer {

    bool registerService(const Service&, EventHandler&);

};

} // end namespace Pinetime