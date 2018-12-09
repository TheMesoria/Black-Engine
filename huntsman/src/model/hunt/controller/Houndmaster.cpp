//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/hunt/controller/Houndmaster.hpp>
#include <engine/Huntsman.hpp>

#include "model/hunt/controller/Houndmaster.hpp"

void huntsman::controller::Houndmaster::run(bool const& isRunning)
{
    LOG_DEBUG(logger_, "Starting houndmaster run.");
    while (isRunning)
    {
        for (auto mbyHuntObject = huntObjectList_.begin(); mbyHuntObject != huntObjectList_.end(); mbyHuntObject++)
        {
            if(mbyHuntObject->expired())
            {
                removeExpiredObject(mbyHuntObject);
                continue;
            }
            LOG_DEBUG(logger_, "Behave loop");
            auto huntObject = mbyHuntObject->lock();
            for(auto const& behavior : huntObject->getBehaviors())
            {
                behavior->behave();
            }
            LOG_DEBUG(logger_, "On Update");
            huntObject->onUpdate();
        }
        auto& falconer = Huntsman::getInstance().getFalconer();
        std::list<const sf::Drawable*> drawablePtrList_;
        for(auto mbyHuntObject = huntObjectList_.begin(); mbyHuntObject != huntObjectList_.end(); mbyHuntObject++)
        {
            if(mbyHuntObject->expired())
            {
                removeExpiredObject(mbyHuntObject);
                continue;
            }
            auto huntObject = mbyHuntObject->lock();
            drawablePtrList_.push_back(&huntObject->getDrawable());
        }
        falconer.addToDraw(drawablePtrList_);
    }
}

void huntsman::controller::Houndmaster::registerNewObject(std::shared_ptr<HuntObject>& objectToRegister)
{
    std::lock_guard<std::mutex> lockGuard(huntObjectListMutex_);
    LOG_DEBUG(logger_, "New Object registration...");
    huntObjectList_.emplace_back(objectToRegister);
}

void huntsman::controller::Houndmaster::removeExpiredObject(std::list<std::weak_ptr<HuntObject>>::iterator& elem)
{
    std::lock_guard<std::mutex> lockGuard(huntObjectListMutex_);
    LOG_DEBUG(logger_, "Object expired...");
    huntObjectList_.erase(elem);
}
