//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <spdlog/logger.h>
#include <nlohmann/json.hpp>
#include <global/CmakeVariables.hpp>

#include "utility/Settings.hpp"

namespace huntsman
{
	using json = nlohmann::json;
	using Settings = huntsman::utility::Settings;
	using LoggerPtr = std::shared_ptr<spdlog::logger>;

	class Huntsman
	{
		std::shared_ptr<spdlog::logger> logger_;
		std::unique_ptr<Settings> settings_;
	public:
		Huntsman() = default;
		~Huntsman() = default;

		void start();
		void start( std::string const& configPath );

	private:
		void loadConfig( std::string const& configPath );

		friend class StartupManager;
	};
}

using Huntsman = huntsman::Huntsman;