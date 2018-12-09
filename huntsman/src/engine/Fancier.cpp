//
// Created by black on 19.11.18.
//

#include <model/hunt/HuntObject.hpp>
#include "engine/Fancier.hpp"

namespace huntsman
{
std::shared_ptr<model::HuntObject> Fancier::getUntrackedObject()
{
    if(untrackedObjects_.empty())
    {
        LOG_DEBUG(logger_, "Requested object, returning none.");
        return {};
    }
    auto lastNotTrackedObject = untrackedObjects_.front();
    untrackedObjects_.pop_front();
    return std::static_pointer_cast<HuntObject>(lastNotTrackedObject);
}
}