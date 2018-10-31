//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma onve

#include <gmock/gmock.h>

#include <engine/utility/Settings.hpp>

class SettingsMock
		: public huntsman::utility::Settings
{
	MOCK_METHOD0(  );
};