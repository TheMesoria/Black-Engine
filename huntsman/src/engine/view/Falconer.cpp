//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include "engine/view/Falconer.hpp"

#include <bitset>
#include <list>

#include <SFML/Graphics.hpp>

#include <Logger.hpp>
#include <engine/view/Falconer.hpp>


namespace huntsman::view
{
Falconer::Falconer(Settings const& settings)
    :
    logger_(spdlog::get("main"))
{
    auto[sizeX, sizeY] = settings.getWindowSize();
    renderWindowPtr_ = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(sizeX, sizeY, 32)
        , settings.getWindowTitle()
        , settings.getWindowStyle()
        , sf::ContextSettings(
            settings.getWindowDepth()
            , settings.getWindowStencil()
            , settings.getWindowAntiAliasing()
            , settings.getMajor()
            , settings.getMinor()
            , settings.getWindowAttribute()
            , settings.isSrgb()));

    LOG_DEBUG_F(logger_, "Window size : [{},{}]", sizeX, sizeY);
    LOG_DEBUG_F(logger_, "Window style : {}", std::bitset<4>(settings.getWindowStyle())
        .to_string());
    LOG_DEBUG_F(logger_, "Context settings version : {}.{}", settings.getMajor(), settings
        .getMinor());

    LOG_INFO(logger_, "Falconer is ready.");
}

sf::RenderWindow* Falconer::operator ->()
{
    return &*renderWindowPtr_;
}

unsigned int Falconer::addToDraw(std::list<std::shared_ptr<HuntObject>> huntObjectList)
{
    std::lock_guard<std::mutex> lockGuard_(listAccessMutex_);
    toDrawList_.merge(huntObjectList);

    return frame_;
}

void Falconer::run()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    frame_++;
    if (not toDrawList_.empty())
    {
        draw();
    }
}

void Falconer::draw()
{
    std::lock_guard<std::mutex> lockGuard_(listAccessMutex_);
    renderWindowPtr_->clear();
    for (auto& elem : toDrawList_)
    {
        renderWindowPtr_->draw(elem->getDrawable());
    }
    renderWindowPtr_->display();
    toDrawList_.clear();
    if (frame_ > 1'000'000)
    {
        frame_ = 0;
    }
}

unsigned int Falconer::getFrame() const
{
    return frame_;
}

}


