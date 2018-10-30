//
// Created by Wojciech Ormaniec on 26.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <engine/utility/Settings.hpp>

#include <fstream>
#include <spdlog/sinks/stdout_sinks.h>

namespace huntsman::utility::settings
{
	json load( std::string const &settingsFilePath )
	{
		std::ifstream file(settingsFilePath);
		return nlohmann::json::parse(file);
	}

	template< class SinkType >
	spdlog::sink_ptr getSink( level_enum logLevel)
	{
		auto sink = std::make_shared<SinkType>();
		sink->set_level(logLevel);
		return sink;
	}

	template< class SinkType >
	spdlog::sink_ptr getFileSink( std::string const &filePath, level_enum logLevel )
	{
		auto sink = std::make_shared<SinkType>(filePath);
		sink->set_level(logLevel);
		return sink;
	}
}