#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char** args)
{
    std::cout << "Argc: " << argc << std::endl;
    std::cout << "Starting args are: " << std::endl;
    for ( auto i = 0; i < argc; i++ )
    {
        std::cout << i << ") " << std::string(args[i]) << std::endl;
    }
    std::cout << "Hello World" << std::endl;

    std::cout << ULONG_LONG_MAX << std::endl;

	return EXIT_SUCCESS;
}