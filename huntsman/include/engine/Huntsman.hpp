//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <nlohmann/json.hpp>

#include <Logger.hpp>
#include <engine/view/HuntingGround.hpp>
#include <model/hunt/controller/Houndmaster.hpp>
#include <engine/view/Falconer.hpp>
#include <engine/Fancier.hpp>
#include "engine/utility/SettingsFacade.hpp"

namespace huntsman
{
using json = nlohmann::json;

class Huntsman
{
    static Huntsman huntsmanInstance;

    LoggerPtr                 logger_;
    std::unique_ptr<Settings> settings_;
    std::unique_ptr<Falconer> falconer_;
    std::unique_ptr<Fancier>  fancier_;
    std::vector<Houndmaster>  houndmasterVector_;

    std::shared_ptr<HuntingGround> huntingGround;
public:
    static Huntsman& getInstance();

    void start();
    void start(std::string const& configPath);

    Fancier& getFancier()
    { return *fancier_; }

    Falconer& getFalconer()
    { return *falconer_; }

    HuntingGround& getHuntingGround()
    { return *huntingGround; }

protected:
    Huntsman() = default;
    ~Huntsman() = default;

    void loadConfig(std::string const& configPath);
    void run();

    friend class StartupManager;
};
}

namespace hsn =  huntsman;
using Huntsman = hsn::Huntsman;
