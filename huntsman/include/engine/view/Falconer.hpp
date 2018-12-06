//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include <Logger.hpp>
#include <engine/utility/SettingsFacade.hpp>

namespace huntsman::view
{
class Falconer
{
private:
    std::unique_ptr<sf::RenderWindow> renderWindowPtr_;
    LoggerPtr                         logger_;

public:
    explicit Falconer(Settings const& settings);

    sf::RenderWindow* operator ->();
};
}


using Falconer = huntsman::view::Falconer;