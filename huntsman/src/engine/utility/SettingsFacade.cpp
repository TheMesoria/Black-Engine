//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/utility/SettingsFacade.hpp"

#include <fstream>
#include <engine/utility/SettingsFacade.hpp>
#include <iostream>
#include <engine/utility/LoggerHelper.hpp>


namespace huntsman::utility
{
SettingsFacade::SettingsFacade(std::string const& settingsFilePath)
{
    std::ifstream file(settingsFilePath);
    file >> activeConfigFile_;
}

std::pair<unsigned, unsigned> SettingsFacade::getWindowSize() const
{
    return {
        activeConfigFile_["engine-settings"]["falconer"]["window"]["size"]["height"]
            .get<unsigned>()
        , activeConfigFile_["engine-settings"]["falconer"]["window"]["size"]["width"]
            .get<unsigned>()
    };
}

std::vector<spdlog::sink_ptr> SettingsFacade::getLoggerSinks() const
{
    auto sinks = activeConfigFile_["logger"]["sinks"];

    std::vector<spdlog::sink_ptr> resultVector;

    auto helper = LoggerHelper();;

    for (auto const& sink : sinks)
    {
        auto
            type  = sink["type"].get<std::string>()
        ,   path  = sink["path"].get<std::string>()
        ,   level = sink["level"].get<std::string>();
        resultVector.push_back(helper.getSink(type, level, path));
    }

    return resultVector;
}

spdlog::level::level_enum SettingsFacade::getLoggerFlushOnLevel() const
{
    return spdlog::level::from_str(activeConfigFile_["logger"]["flush-on"]);
}

spdlog::level::level_enum SettingsFacade::getLoggerLevel() const
{
    return spdlog::level::from_str(activeConfigFile_["logger"]["level"]);
}

size_t SettingsFacade::getHuntingGroundChunkSize() const
{
    return activeConfigFile_["engine-settings"]["hunting-ground"]["settings"]["chunk-size"]
        .get<size_t>();
}

std::pair<size_t, size_t> SettingsFacade::getHuntingGroundSize() const
{
    auto x = activeConfigFile_
                ["engine-settings"]["hunting-ground"]
                ["settings"]["grid-size"]["x"]
            .get<size_t>(),
         y = activeConfigFile_
                 ["engine-settings"]["hunting-ground"]
                 ["settings"]["grid-size"]["y"]
             .get<size_t>();
    return {x, y};
}

size_t SettingsFacade::getHoundmasterHoundCount() const
{
    return activeConfigFile_["engine-settings"]["hound-master"]["hound-count"].get<size_t>();
}

size_t SettingsFacade::getHoundmasterAmount() const
{
    return activeConfigFile_["engine-settings"]["hound-master"]["amount"].get<size_t>();
}

unsigned SettingsFacade::getWindowDepth() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["depth"]
        .get<size_t>();
}

unsigned SettingsFacade::getWindowStencil() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["stencil"]
        .get<size_t>();
}

unsigned SettingsFacade::getWindowAntiAliasing() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["anti-aliasing"]
        .get<size_t>();
}

unsigned SettingsFacade::getMajor() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["major"]
        .get<size_t>();
}

unsigned SettingsFacade::getMinor() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["minor"]
        .get<size_t>();
}

SettingsFacade::Attribute SettingsFacade::getWindowAttribute() const
{
    const static std::map<std::string, Attribute> attributeMapping = {
        {  "Debug"  , Attribute::Debug}
        , {"Default", Attribute::Default}
        , {"Core"   , Attribute::Core}
    };

    return attributeMapping.at(
        activeConfigFile_["engine-settings"]["falconer"]["window"]["attribute"]
            .get<std::string>());
}

bool SettingsFacade::isSrgb() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["sRgb"].get<bool>();
}

std::string SettingsFacade::getWindowTitle() const
{
    return activeConfigFile_["engine-settings"]["falconer"]["window"]["title"].get<std::string>();
}

unsigned SettingsFacade::getWindowStyle() const
{
    unsigned style = sf::Style::None;

    static const std::map<std::string, unsigned> windowStyleMapping = {
        {  "None"      , sf::Style::None}
        , {"Titlebar"  , sf::Style::Titlebar}
        , {"Resize"    , sf::Style::Resize}
        , {"Close"     , sf::Style::Close}
        , {"Fullscreen", sf::Style::Fullscreen}
        , {"Default"   , sf::Style::Default}
    };

    for (const auto& activeStyle : activeConfigFile_["engine-settings"]["falconer"]["window"]["style"])
    {
        style |= windowStyleMapping.at(activeStyle.get<std::string>());
    }

    return style;
}
}