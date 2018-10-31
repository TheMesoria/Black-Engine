//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <spdlog/logger.h>
#include <nlohmann/json.hpp>

#include "utility/Settings.hpp"

namespace huntsman
{
	using json = nlohmann::json;
	using Settings = huntsman::utility::Settings;

	class Huntsman
	{
		std::shared_ptr<spdlog::logger> logger_;
		std::unique_ptr<Settings> settings_;
	public:
		Huntsman() = default;

		void start();

	private:
		void loadConfig();
	};
}

