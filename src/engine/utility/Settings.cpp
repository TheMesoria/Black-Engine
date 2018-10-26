//
// Created by Wojciech Ormaniec on 26.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <engine/utility/Settings.hpp>

#include <fstream>

namespace huntsman::utility::settings
{
	json load( std::string const &settingsFilePath )
	{
		std::ifstream file(settingsFilePath);
		return nlohmann::json::parse(file);
	}
}