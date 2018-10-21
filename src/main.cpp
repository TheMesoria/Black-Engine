#include <iostream>
#include <spdlog/spdlog.h>
#include <global/Generators.hpp>
#include <SFML/Graphics.hpp>
#include <cxxabi.h>

int main(int argc, char** args)
{
	std::cout << "Argc: " << argc << std::endl;
	std::cout << "Starting args are: " << std::endl;
	for ( auto i = 0; i < argc; i++ )
	{
		std::cout << i << ") " << std::string(args[i]) << std::endl;
	}
	std::cout << "Hello World" << std::endl;

	std::cout << Global::Default::Functions::GenerateId() << std::endl;

	return EXIT_SUCCESS;
}