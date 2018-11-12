//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

#include <Logger.hpp>
#include <CMakeVariables.hpp>
#include <engine/utility/Settings.hpp>
#include <engine/Huntsman.hpp>
#include <engine/utility/StartupManager.hpp>

namespace huntsman
{
	using Settings = huntsman::utility::Settings;

	void Huntsman::loadConfig( std::string const& configPath )
	{
		settings_ = std::make_unique<Settings>( configPath );
		StartupManager startupManager( *this, *settings_ );

		if( startupManager.initialiseHuntsman() )
		{
			std::cerr << "Initialisation Failed!" << std::endl;
		}

		LOG_INFO(logger_,"Initialised successfully.");
	}

	void Huntsman::start( std::string const& configPath )
	{
		loadConfig( configPath );
	}

	void Huntsman::start()
	{
		start( CMAKE_CURRENT_BINARY_DIR + "config/settings.json" );
	}
}