//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <experimental/filesystem>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>


#include <engine/utility/Settings.hpp>
#include <engine/Huntsman.hpp>
#include <engine/utility/StartupManager.hpp>

namespace huntsman
{
	using Settings = huntsman::utility::Settings;

//	bool Huntsman::loadConfigFromFile( std::string const &configFilePath )
//	{
//		try
//		{
//			auto settings = Settings::get();
//			settings.load( configFilePath );
//
//			auto errorScreenSink    = settings.getSink<spdlog::sinks::stderr_sink_mt>( spdlog::level::err );
//			auto standardScreenSink = settings.getSink<spdlog::sinks::stdout_sink_mt>( spdlog::level::info );
//			auto debugScreenSink    = settings.getSink<spdlog::sinks::ansicolor_stdout_sink_mt>( spdlog::level::debug );
//
//			auto standardFileSink = settings.getFileSink<spdlog::sinks::simple_file_sink_mt>(
//					"logs/RunLog.log"
//					, spdlog::level::info );
//			auto debugFileSink    = settings.getFileSink<spdlog::sinks::v>(
//					"logs/DebugLog.log"
//					, spdlog::level::debug );
//
//
//			std::cout << "Your value is: " << settings[ "initSettings" ][ "sink" ][ "std::sink" ].get<std::string>()
//					  << std::endl;
//		}
//		catch( nlohmann::detail::type_error const &e )
//		{
//			std::cerr << "Could not load settings from file," << std::endl;
//			std::cerr << "Path: " + configFilePath + "." << std::endl;
//			std::cerr << "Are you sure everything is alright?" << std::endl;
//			std::cerr << e.what() << std::endl;
//		}
//		return false;
//	}

	void Huntsman::loadConfig()
	{
		settings_ = std::make_unique<Settings>( "settings.json" );
		StartupManager startupManager(*this, *settings_);

		if(startupManager.initialiseHuntsman())
		{
			std::cerr << "Initialisation Failed!" << std::endl;
		}
	}

	void Huntsman::start()
	{
		loadConfig();
	}
}