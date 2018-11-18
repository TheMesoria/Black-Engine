//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#include <gmock/gmock.h>

#include <engine/Huntsman.hpp>

class HuntsmanMock
		: public Huntsman
{
public:

	MOCK_METHOD0( start, void( void ) );
};