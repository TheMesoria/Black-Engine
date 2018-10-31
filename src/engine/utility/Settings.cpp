//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/utility/Settings.hpp"

#include <fstream>
#include <engine/utility/Settings.hpp>


namespace huntsman::utility
{
	Settings::Settings( std::string const &settingsFilePath )
	{
		std::ifstream file( settingsFilePath );
		file >> activeConfigFile_;
//		activeConfigFile_ = nlohmann::json::parse( file );
	}
}