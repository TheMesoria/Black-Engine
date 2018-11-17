//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include "engine/view/Falconer.hpp"

#include <SFML/Graphics.hpp>

#include <Logger.hpp>

namespace huntsman::view
{
	Falconer::Falconer( Settings const& settings )
			:
			logger_( spdlog::get( "main" ) )
	{
		auto[sizeX, sizeY] = settings.getWindowSize();
//		renderWindowPtr_ = std::make_unique<sf::RenderWindow>();
		auto srw = sf::RenderWindow(
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

		LOG_INFO( logger_, "Falconer is ready." );
	}

}


