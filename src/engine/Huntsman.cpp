//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <fstream>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <iostream>

#include <engine/utility/Settings.hpp>
#include <engine/Huntsman.hpp>

namespace huntsman
{
	Huntsman::Huntsman()
	{
		loadConfigFromFile("settings.json");
	}

	bool Huntsman::initialiseLogger()
	{
//		logger_ = spdlog::create( "main",
//								  {
//			spdlog::sinks::
//								  } );
	}

	bool Huntsman::loadConfigFromFile( std::string const &configFilePath )
	{
		try
		{
			auto settings = huntsman::utility::settings::load( configFilePath );

			huntsman::utility::settings::getSink<spdlog::sinks::stderr_sink_mt>(spdlog::level::info);



			std::cout << "Your value is: " << settings[ "initSettings" ][ "sink" ][ "std::sink" ].get<std::string>()
					  << std::endl;
		}
		catch( nlohmann::detail::type_error const &e )
		{
			std::cerr << "Could not load settings from file," << std::endl;
			std::cerr << "Path: " + configFilePath + "." << std::endl;
			std::cerr << "Are you sure everything is alright?" << std::endl;
			std::cerr << e.what() << std::endl;
		}
		return false;
	}
}