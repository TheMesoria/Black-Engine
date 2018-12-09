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
    auto& falconer = Huntsman::getInstance().getFalconer();
    auto frame = falconer.getFrame();
    while (isRunning)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if (frame == falconer.getFrame())
        {
            LOG_DEBUG(logger_, "Frame is not displaced!");
            continue;
        }

        for (auto mbyHuntObject                              = huntObjectList_.begin();
             mbyHuntObject != huntObjectList_.end(); mbyHuntObject++)
        {
            if (mbyHuntObject->expired())
            {
                removeExpiredObject(mbyHuntObject);
                continue;
            }
            auto huntObject = mbyHuntObject->lock();
            for (auto const& behavior : huntObject->getBehaviors())
            {
                behavior->behave();
            }
            huntObject->onUpdate();
        }

        std::list<std::shared_ptr<HuntObject>> drawableObjectList;
        for (auto                              mbyHuntObject = huntObjectList_.begin();
             mbyHuntObject != huntObjectList_.end(); mbyHuntObject++)
        {
            if (mbyHuntObject->expired())
            {
                removeExpiredObject(mbyHuntObject);
                continue;
            }
            drawableObjectList.push_back(mbyHuntObject->lock());
        }
        frame = falconer.addToDraw(drawableObjectList);
        clear_=!clear_;
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

bool huntsman::controller::Houndmaster::groupClear_ = false;

bool huntsman::controller::Houndmaster::isClear() const
{
    return clear_;
}

bool huntsman::controller::Houndmaster::isGroupClear()
{
    return groupClear_;
}

void huntsman::controller::Houndmaster::setGroupClear(bool groupClear)
{
    Houndmaster::groupClear_ = groupClear;
}
