//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

#include <CMakeVariables.hpp>
#include <engine/utility/SettingsFacade.hpp>
#include <engine/Huntsman.hpp>
#include <engine/utility/StartupManager.hpp>

namespace huntsman
{
using Settings = huntsman::utility::SettingsFacade;

void Huntsman::loadConfig(std::string const& configPath)
{
    settings_ = std::make_unique<Settings>(configPath);
    StartupManager startupManager(*this, *settings_);

    if (!startupManager.initialiseHuntsman())
    {
        std::cout << "Initialisation Failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    LOG_INFO(logger_, "Initialised successfully.");
}

void Huntsman::start(std::string const& configPath)
{
    loadConfig(configPath);
    runner_ = std::thread(&Huntsman::run, this);
}

void Huntsman::run()
{
    for (auto i = 0u; i < settings_->getHoundmasterAmount(); i++)
    {
        houndmasterVector_.emplace_back(new Houndmaster(clock_));
        houndmasterThreadVector_
            .emplace_back(&Houndmaster::run, houndmasterVector_.back().get(), std::ref(isRunning_));
    }
    houndmasterIterator_ = houndmasterVector_.begin();

    // Start the game loop
    while ((*falconer_)->isOpen())
    {
        while (fancier_->isUntracked())
        {
            auto obj = fancier_->getUntrackedObject();
            registerNewObject(obj);
            huntingGround->add(obj);
        }
        if (ready())
        {
            huntsman::controller::Houndmaster::setGroupClear(!huntsman::controller::Houndmaster::isGroupClear());
            falconer_->operator->()->clear();
            falconer_->run();
        }
    }
    isRunning_ = false;
}

void Huntsman::start()
{
    start(CMAKE_CURRENT_BINARY_DIR + "config/settings.json");
}

Huntsman& Huntsman::getInstance()
{
    return huntsmanInstance;
}

Huntsman::~Huntsman()
{
    for (auto& houndMaster : houndmasterThreadVector_)
    {
        houndMaster.join();
    }
    runner_.join();
}

void Huntsman::registerNewObject(std::shared_ptr<HuntObject>& huntObject)
{
    houndmasterIterator_->get()->registerNewObject(huntObject);
    houndmasterIterator_++;
    if (houndmasterVector_.end() == houndmasterIterator_)
    {
        houndmasterIterator_ = houndmasterVector_.begin();
    }
}

bool Huntsman::isRunning() const
{
    return isRunning_;
}

bool Huntsman::ready()
{
    auto ready = true;
    for (auto& houndmaster : houndmasterVector_)
    {
        if (houndmaster->isClear() != huntsman::controller::Houndmaster::isGroupClear())
        {
            ready = false;
        }
    }
    return ready;
}

Huntsman Huntsman::huntsmanInstance;
}