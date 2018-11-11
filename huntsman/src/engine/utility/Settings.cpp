//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/utility/Settings.hpp"

#include <fstream>
#include <engine/utility/Settings.hpp>
#include <iostream>
#include <engine/utility/LoggerHelper.hpp>


namespace huntsman::utility
{
	Settings::Settings( std::string const& settingsFilePath )
	{
		std::ifstream file( settingsFilePath );
		file >> activeConfigFile_;
	}

	std::pair<int, int> Settings::getWindowSize() const
	{
		int height, width;
		height = activeConfigFile_[ "window-settings" ][ "height" ];
		width  = activeConfigFile_[ "window-settings" ][ "width" ];

		return { height, width };
	}

	std::vector<spdlog::sink_ptr> Settings::getSinks() const
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

	spdlog::level::level_enum Settings::getFlushOnLevel() const
	{
		return spdlog::level::from_str( activeConfigFile_[ "logger" ][ "flush-on" ] );
	}
}