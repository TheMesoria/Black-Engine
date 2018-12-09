//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>
#include <thread>

#include <nlohmann/json.hpp>

#include <Logger.hpp>
#include <engine/view/HuntingGround.hpp>
#include <model/hunt/controller/Houndmaster.hpp>
#include <engine/view/Falconer.hpp>
#include "Fancier.hpp"
#include <engine/Fancier.hpp>
#include "engine/utility/SettingsFacade.hpp"

namespace huntsman
{
using json = nlohmann::json;

class Huntsman
{
    static Huntsman huntsmanInstance;

    sf::Clock   clock_;
    std::thread runner_;

    LoggerPtr                      logger_;
    std::unique_ptr<Settings>      settings_;
    std::unique_ptr<Falconer>      falconer_;
    std::unique_ptr<Fancier>       fancier_;
    std::shared_ptr<HuntingGround> huntingGround;

    std::vector<std::thread>                            houndmasterThreadVector_;
    std::vector<std::shared_ptr<Houndmaster>>           houndmasterVector_;
    std::vector<std::shared_ptr<Houndmaster>>::iterator houndmasterIterator_;

    bool isRunning_ = true;
public:
    static Huntsman& getInstance();

    void start();
    void start(std::string const& configPath);
    bool isRunning() const;
    void registerNewObject(std::shared_ptr<HuntObject>& huntObject);

    Fancier& getFancier()
    { return *fancier_; }

    Falconer& getFalconer()
    { return *falconer_; }

    HuntingGround& getHuntingGround()
    { return *huntingGround; }

    sf::Clock& getGameClock()
    { return clock_; }

protected:
    Huntsman() = default;
    ~Huntsman();

    void loadConfig(std::string const& configPath);
    void run();
    bool ready();

    friend class StartupManager;
};
}

namespace hsn =  huntsman;
using Huntsman = hsn::Huntsman;
