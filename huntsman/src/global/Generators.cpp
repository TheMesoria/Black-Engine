//
// Created by Wojciech Ormaniec on 07.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <global/Generators.hpp>

namespace
{
	std::string GeneratePartialId( uint8_t size )
	{
		static const char alphabet[] =
								  "abcdefghijklmnopqrstuvwxyz"
								  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
								  "0123456789";

		std::random_device              rd;
		std::default_random_engine      rng( rd());
		std::uniform_int_distribution<> dist( 0, sizeof( alphabet ) / sizeof( *alphabet ) - 2 );
		std::string str;

		str.reserve( size );
		std::generate_n( std::back_inserter( str ), size,
						 [ & ]() { return alphabet[ dist( rng ) ]; } );

		return str;
	}
}

namespace Global::Default::Functions
{
	std::string GenerateId( uint8_t size, uint8_t partialSize )
	{
		std::string returnId = "";
		for(auto i = 0u; i < size; i++)
		{
			returnId+=GeneratePartialId(partialSize)+"-";
		}
		returnId.pop_back();
		return returnId;
	}
}