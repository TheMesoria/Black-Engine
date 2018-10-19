#include <iostream>
#include <spdlog/spdlog.h>
#include <global/Generators.hpp>

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

	typeid();

	return EXIT_SUCCESS;
}

//#include <iostream>
//#include <cxxabi.h>
//#define quote(x) #x
//template <typename foo,typename bar> class one{ };
//
//class Kek
//{
//public:
//	Kek()
//	{
//		int status;
//		char * demangled = abi::__cxa_demangle(typeid(*this).name(),0,0,&status);
//		std::cout<<demangled<<"\t"<< quote(A) <<"\n";
//		free(demangled);
//	}
//};
//
//int main(){
//	one<int,one<double, int> > A;
//	int status;
//	char * demangled = abi::__cxa_demangle(typeid(A).name(),0,0,&status);
//	std::cout<<demangled<<"\t"<< quote(A) <<"\n";
//	free(demangled);
//
//	Kek kek;
//
//	return 0;
}