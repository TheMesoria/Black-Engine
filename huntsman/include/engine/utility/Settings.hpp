//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <memory>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

namespace huntsman::utility
{
	using nlohmann::json;

	class Settings
	{
	public:
		Settings() = default;
		explicit Settings( std::string const& settingsFilePath );

		std::vector<spdlog::sink_ptr> getSinks() const;
		std::pair<int, int> getWindowSize() const;
		spdlog::level::level_enum getFlushOnLevel() const;
	private:
		json activeConfigFile_;
	};
}

using Settings = huntsman::utility::Settings;

