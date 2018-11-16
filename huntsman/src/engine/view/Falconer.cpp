//
// Created by Wojciech Ormaniec on 16.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include "engine/view/Falconer.hpp"

#include <SFML/Graphics.hpp>

namespace huntsman::view
{
	Falconer::Falconer( Settings const& settings )
	{
		renderWindowPtr_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(),"",0);
		sf::RenderWindow(sf::VideoMode(),"",0,sf::ContextSettings());
	}
}


