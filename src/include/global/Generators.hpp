//
// Created by Wojciech Ormaniec on 06.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <cstdint>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

namespace Global::Default::Functions
{
	std::string GenerateId( uint8_t size = 8, uint8_t partialSize = 8 );
}


