//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once


#include <list>
#include <model/hunt/HuntObject.hpp>

#include <Logger.hpp>

namespace huntsman::controller
{
class Houndmaster
{
    std::mutex                           huntObjectListMutex_;
    std::list<std::weak_ptr<HuntObject>> huntObjectList_ = {};

    LoggerPtr logger_ = spdlog::get("main");
public:
    Houndmaster() {};
    Houndmaster(Houndmaster& houndmaster)
    {huntObjectList_=houndmaster.huntObjectList_;};

    void registerNewObject(std::shared_ptr<HuntObject>& objectToRegister);
    void removeExpiredObject(std::list<std::weak_ptr<HuntObject>>::iterator& elem);
    void run(bool const& isRunning);
};
}

using Houndmaster = huntsman::controller::Houndmaster;

