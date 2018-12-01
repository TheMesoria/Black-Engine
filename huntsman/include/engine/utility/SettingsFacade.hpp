//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <memory>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

namespace huntsman::utility
{
	using nlohmann::json;

	class SettingsFacade
	{
		using Attribute = sf::ContextSettings::Attribute;

	public:
		SettingsFacade() = default;
		explicit SettingsFacade( std::string const& settingsFilePath );

		bool isSrgb() const;
		size_t getHuntingGroundChunkSize() const;
		size_t getHoundmasterAmount() const;
		size_t getHoundmasterHoundCount() const;
		unsigned getWindowDepth() const;
		unsigned getWindowStencil() const;
		unsigned getWindowAntiAliasing() const;
		unsigned getMajor() const;
		unsigned getMinor() const;
		unsigned getWindowStyle() const;
		std::string getWindowTitle() const;
		std::pair<unsigned, unsigned> getWindowSize() const;
		std::pair<size_t, size_t> getHuntingGroundSize() const;
		std::vector<spdlog::sink_ptr> getLoggerSinks() const;
		Attribute getWindowAttribute() const;
		spdlog::level::level_enum getLoggerFlushOnLevel() const;
		spdlog::level::level_enum getLoggerLevel() const;

	private:
		json activeConfigFile_;
	};
}

using Settings = huntsman::utility::SettingsFacade;

