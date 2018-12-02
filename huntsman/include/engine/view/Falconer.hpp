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
public:
    std::unique_ptr<sf::RenderWindow> renderWindowPtr_;
    LoggerPtr                         logger_;

public:
    Falconer(Settings const& settings);

    sf::RenderWindow& operator ->()
    { return *renderWindowPtr_; }
};
}

1111111111111111111111111111111111111111111111111111111

using Falconer = huntsman::view::Falconer;