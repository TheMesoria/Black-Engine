//
// Created by Wojciech Ormaniec on 26.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include <spdlog/common.h>

namespace huntsman::utility::settings
{
	using spdlog::level::level_enum;
	using nlohmann::json;

	json load(std::string const& settingsFilePath);

	template< class SinkType >
	spdlog::sink_ptr getFileSink( std::string const &filePath, level_enum logLevel = spdlog::level::info );

	template< class SinkType >
	spdlog::sink_ptr getSink( level_enum logLevel = spdlog::level::info );
}
