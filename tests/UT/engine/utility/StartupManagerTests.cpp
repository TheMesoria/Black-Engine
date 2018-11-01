//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <gtest/gtest.h>
#include <engine/utility/StartupManager.hpp>

#include <HuntsmanMock.hpp>
#include <SettingsMock.hpp>

class StartupManagerShould
		: public ::testing::Test
{
public:
	StartupManagerShould() :
			sut_( huntsman_, settings_ ) { }

	HuntsmanMock huntsman_;
	SettingsMock settings_;

	huntsman::StartupManager sut_;
};

TEST_F( StartupManagerShould, LoadCorrectlyLogger )
{
	EXPECT_CALL(huntsman_, start).Times(1);
	huntsman_.start();
}