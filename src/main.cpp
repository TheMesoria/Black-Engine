#include <iostream>
#include <spdlog/spdlog.h>
#include <global/Generators.hpp>
#include <SFML/Graphics.hpp>
#include <cxxabi.h>
#include <engine/Huntsman.hpp>

int main(int argc, char** args)
{
	std::cout << "Argc: " << argc << std::endl;
	std::cout << "Starting args are: " << std::endl;
	for ( auto i = 0; i < argc; i++ )
	{
		std::cout << i << ") " << std::string(args[i]) << std::endl;
	}

	std::cout << Global::Default::Functions::GenerateId() << std::endl;

	huntsman::Huntsman huntsman1;


	return EXIT_SUCCESS;
}