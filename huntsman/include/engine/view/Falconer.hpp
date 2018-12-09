//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>
#include <list>

#include <SFML/Graphics.hpp>

#include <Logger.hpp>
#include <model/hunt/HuntObject.hpp>
#include <engine/utility/SettingsFacade.hpp>

namespace huntsman::view
{
class Falconer
{
private:
    std::unique_ptr<sf::RenderWindow>    renderWindowPtr_;
    std::list<std::shared_ptr<HuntObject>> toDrawList_;

    std::mutex listAccessMutex_;

    LoggerPtr logger_;

    unsigned frame_ = 0;
public:
    unsigned int getFrame() const;

public:
    explicit Falconer(Settings const& settings);

    void run();
    unsigned int addToDraw(std::list<std::shared_ptr<HuntObject>> huntObjectList);

    sf::RenderWindow* operator ->();

private:
    void draw();
};
}


using Falconer = huntsman::view::Falconer;