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
    run();
}

void Huntsman::run()
{
    // Start the game loop
    while ((*falconer_)->isOpen())
    {
        // Process events
        sf::Event event;
        while ((*falconer_)->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                (*falconer_)->close();
        }
        // Clear screen
        (*falconer_)->clear();
        // Update the window
        (*falconer_)->display();
    }
}

void Huntsman::start()
{
    start(CMAKE_CURRENT_BINARY_DIR + "config/settings.json");
}

Huntsman& Huntsman::getInstance()
{
    return huntsmanInstance;
}

Huntsman Huntsman::huntsmanInstance;
}