//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <nlohmann/json.hpp>

#include "utility/Settings.hpp"

namespace huntsman
{
	using json = nlohmann::json;
	using LoggerPtr = std::shared_ptr<spdlog::logger>;

	class Huntsman
	{
		LoggerPtr logger_;
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

namespace hsn =  huntsman;
using Huntsman = hsn::Huntsman;
