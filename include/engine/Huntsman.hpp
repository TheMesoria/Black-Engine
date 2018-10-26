//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <memory>

#include <spdlog/logger.h>
#include <nlohmann/json.hpp>

namespace huntsman
{
	using json = nlohmann::json;

	class Huntsman
	{
		std::shared_ptr<spdlog::logger> logger_;
	public:
		Huntsman();

		void start(){};

	private:
		bool loadConfigFromFile(std::string const& configFilePath);
		bool initialiseLogger();
	};
}

