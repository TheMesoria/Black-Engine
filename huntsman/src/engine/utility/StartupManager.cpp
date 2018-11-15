//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <engine/utility/StartupManager.hpp>

#include <iostream>


namespace huntsman
{
	StartupManager::StartupManager( Huntsman& huntsman, Settings const& settings ) :
			settings_( settings ), huntsman_( huntsman ) {}

	bool StartupManager::initialiseHuntsman()
	{
		bool failedInitialisation = false;

		failedInitialisation |= not initialiseLogger();
		failedInitialisation |= not initialiseHuntingGround();

		return failedInitialisation;
	}

	bool StartupManager::initialiseLogger()
	{

		if( spdlog::get( "main" ) )
		{
			logger_ = spdlog::get( "main" );
		}
		else
		{
			auto sinks = settings_.getSinks();
			logger_ = std::make_shared<spdlog::logger>( "main", sinks.begin(), sinks.end() );
			spdlog::register_logger( logger_ );
		}

		logger_->flush_on( settings_.getFlushOnLevel() );
		logger_->set_level( settings_.getLoggerLevel() );

		logger_->info( "############################################################" );
		logger_->info( "#                        Run Started                       #" );
		logger_->info( "############################################################" );
		logger_->flush();

		huntsman_.logger_ = logger_;


		return logger_ ? true : false;
	}

	bool StartupManager::initialiseHuntingGround()
	{
		try
		{
			huntsman_.huntingGround = std::make_shared<HuntingGround>( settings_ );
		}
		catch( std::exception& e )
		{
			std::cerr << "Failed to initialise HuntingGround." << std::endl;
			return false;
		}
		return true;
	}
}
