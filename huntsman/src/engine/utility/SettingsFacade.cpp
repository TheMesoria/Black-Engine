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

	std::pair<unsigned , unsigned > SettingsFacade::getWindowSize() const
	{
		int height, width;
		height = activeConfigFile_[ "window-settings" ][ "height" ];
		width  = activeConfigFile_[ "window-settings" ][ "width" ];

		return { height, width };
	}

	std::vector<spdlog::sink_ptr> SettingsFacade::getLoggerSinks() const
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

	spdlog::level::level_enum SettingsFacade::getLoggerFlushOnLevel() const
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
		auto x = activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "settings" ][ "grid-size" ][ "x" ].get<
				size_t>(),
			 y = activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "settings" ][ "grid-size" ][ "y" ].get<
					 size_t>();
		return { x, y };
	}

	size_t SettingsFacade::getHoundmasterHoundCount() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "hound-master" ][ "amount" ].get<size_t>();
	}

	size_t SettingsFacade::getHoundmasterAmount() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "hound-master" ][ "hound-count" ].get<size_t>();
	}

	unsigned SettingsFacade::getWindowDepth() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "depth" ]
				.get<size_t>();
	}

	unsigned SettingsFacade::getWindowStencil() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "stencil" ]
				.get<size_t>();
	}

	unsigned SettingsFacade::getWindowAntialiasing() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "antialiasing" ]
				.get<size_t>();
	}

	unsigned SettingsFacade::getMajor() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "major" ]
				.get<size_t>();
	}

	unsigned SettingsFacade::getMinor() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "minor" ]
				.get<size_t>();
	}

	sf::ContextSettings::Attribute SettingsFacade::getWindowAttribute() const
	{
		static const std::map<std::string, Attribute> attributeMapping = {
				{ "Debug",   Attribute::Debug },
				{ "Default", Attribute::Default },
				{ "Core",    Attribute::Core }
		};

		return attributeMapping.at( activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "attribute" ]
											.get<std::string>() );
	}

	bool SettingsFacade::isSrgb() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "sRgb" ].get<bool>();
	}

	std::string SettingsFacade::getWindowTitle() const
	{
		return activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "title" ].get<std::string>();
	}

	unsigned SettingsFacade::getWindowStyle() const
	{
		unsigned style = sf::Style::None;

		static const std::map<std::string, unsigned> windowStyleMapping = {
				{ "None",       0 },
				{ "Titlebar",   1 << 0 },
				{ "Resize",     1 << 1 },
				{ "Close",      1 << 2 },
				{ "Fullscreen", 1 << 3 },
		};

		for( const auto activeStyle : activeConfigFile_[ "engine-settings" ][ "hunting-ground" ][ "falconer" ][ "window" ][ "style" ] )
		{
			style |= windowStyleMapping.at( activeStyle.get<std::string>() );
		}

		return style;
	}
}