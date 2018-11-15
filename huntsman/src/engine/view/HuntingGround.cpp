//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/view/HuntingGround.hpp"

#include <Logger.hpp>
#include <engine/view/HuntingGround.hpp>


namespace huntsman
{

	HuntingGround::HuntingGround( Settings const& settings )
			:
			gridChunkSize_( settings.getHuntingGroundChunkSize() )
			, logger_( spdlog::get( "main" ) )
	{
		LOG_DEBUG( logger_, "[CTOR]" );
		createGrid( settings.getHuntingGroundSize() );

		LOG_DEBUG_F( logger_, "Hunting ground size : {} pixels.", gridChunkSize_ * grid_.size() );
		LOG_INFO( logger_, "Hunting ground ready." );
	}

	void HuntingGround::createGrid( GridSize const& gridSize )
	{
		auto[gridX, gridY] = gridSize;
		LOG_DEBUG_F( logger_, "Creating hunting grid of size: x = {}, y={}", gridX, gridY );
		for( auto i = 0u; i < gridX; i++ )
		{
			grid_.emplace_back( gridY );
		}
	}

}