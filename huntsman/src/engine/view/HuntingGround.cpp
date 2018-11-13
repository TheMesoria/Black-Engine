//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/view/HuntingGround.hpp"

#include <Logger.hpp>

namespace huntsman
{

	HuntingGround::HuntingGround( Settings const& settings )
			:
			gridChunkSize_( settings.getHuntingGroundChunkSize() )
			, gridSize_( settings.getHuntingGroundSize() )
			, logger_( spdlog::get( "main" ) )
	{
		LOG_DEBUG( logger_, "[CTOR]" );
		logger_->set_level(spdlog::level::debug);
		logger_->debug("lol");
		logger_->flush();

		LOG_INFO( logger_, "Hunting ground ready." );
	}

}