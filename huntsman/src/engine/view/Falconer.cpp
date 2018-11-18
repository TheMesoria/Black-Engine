//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include "engine/view/Falconer.hpp"

#include <bitset>

#include <SFML/Graphics.hpp>

#include <Logger.hpp>

namespace huntsman::view
{
	Falconer::Falconer( Settings const& settings )
			:
			logger_( spdlog::get( "main" ) )
	{
		auto[sizeX, sizeY] = settings.getWindowSize();
		renderWindowPtr_ = std::make_unique<sf::RenderWindow>(
				sf::VideoMode( sizeX, sizeY, 32 )
				, settings.getWindowTitle()
				, settings.getWindowStyle()
				, sf::ContextSettings(
						settings.getWindowDepth()
						, settings.getWindowStencil()
						, settings.getWindowAntialiasing()
						, settings.getMajor()
						, settings.getMinor()
						, settings.getWindowAttribute()
						, settings.isSrgb() ) );

		LOG_DEBUG_F( logger_, "Window size : [{},{}]", sizeX, sizeY );
		LOG_DEBUG_F( logger_, "Window style : {}", std::bitset<4>( settings.getWindowStyle() ).to_string() );
		LOG_DEBUG_F( logger_, "Context settings version : {}.{}", settings.getMajor(), settings.getMinor() );

		LOG_INFO( logger_, "Falconer is ready." );
	}

}


