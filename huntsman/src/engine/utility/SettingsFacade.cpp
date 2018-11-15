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
	SettingsFacade::SettingsFacade( std::string const& settingsFilePath )
	{
		std::ifstream file( settingsFilePath );
		file >> activeConfigFile_;
	}

	std::pair<size_t, size_t> SettingsFacade::getWindowSize() const
	{
		int height, width;
		height = activeConfigFile_[ "window-settings" ][ "height" ];
		width  = activeConfigFile_[ "window-settings" ][ "width" ];

		return { height, width };
	}

	std::vector<spdlog::sink_ptr> SettingsFacade::getSinks() const
	{
		auto sinks = activeConfigFile_[ "logger" ][ "sinks" ];

		std::vector<spdlog::sink_ptr> resultVector;

		auto helper = LoggerHelper();;

		for( auto const& sink : sinks )
		{
			std::string
					type  = sink[ "type" ].get<std::string>()
			,       path  = sink[ "path" ].get<std::string>()
			,       level = sink[ "level" ].get<std::string>();
			resultVector.push_back( helper.getSink( type, level, path ) );
		}

		return resultVector;
	}

	spdlog::level::level_enum SettingsFacade::getFlushOnLevel() const
	{
		return spdlog::level::from_str( activeConfigFile_[ "logger" ][ "flush-on" ] );
	}

	spdlog::level::level_enum SettingsFacade::getLoggerLevel() const
	{
		return spdlog::level::from_str( activeConfigFile_[ "logger" ][ "level" ] );
	}

	size_t SettingsFacade::getHuntingGroundChunkSize() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "settings" ][ "chunk-size" ].get<size_t>();
	}

	std::pair<size_t, size_t> SettingsFacade::getHuntingGroundSize() const
	{
		auto x = activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "settings" ][ "grid-size" ][ "x" ].get<size_t>(),
			 y = activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "settings" ][ "grid-size" ][ "y" ].get<size_t>();
		return {x,y};
	}

	size_t SettingsFacade::getHoundmasterHoundCount() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "hound-master" ][ "amount" ].get<size_t>();
	}

	size_t SettingsFacade::getHoundmasterAmount() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "hound-master" ][ "hound-count" ].get<size_t>();
	}

}