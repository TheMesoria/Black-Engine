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

	class SettingsFacade
	{
	public:
		SettingsFacade() = default;
		explicit SettingsFacade( std::string const& settingsFilePath );

		std::vector<spdlog::sink_ptr> getSinks() const;
		std::pair<size_t, size_t> getWindowSize() const;
		spdlog::level::level_enum getFlushOnLevel() const;
		spdlog::level::level_enum getLoggerLevel() const;
		size_t getHuntingGroundChunkSize() const;
		std::pair<size_t, size_t> getHuntingGroundSize() const;

	private:
		json activeConfigFile_;
	};
}

using Settings = huntsman::utility::SettingsFacade;

