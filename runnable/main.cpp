//
// Created by Wojciech Ormaniec on 07.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <engine/Huntsman.hpp>
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

int main( int argc, char** args )
{
	std::wcerr << "argc : " << argc << std::endl;
	std::wcerr << "args : " << std::endl;
	for( auto i = 0; i < argc; i++ )
	{
		std::wcerr << i+1 << ")" << args[ i ] << std::endl;
	}
	std::wcerr << std::endl << std::endl;

	Huntsman::getInstance().start();

	spdlog::get("main")->info("Fuck?");

	return EXIT_SUCCESS;
}