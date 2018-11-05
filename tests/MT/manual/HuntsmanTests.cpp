//
// Created by Wojciech Ormaniec on 05.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <gtest/gtest.h>
#include <engine/Huntsman.hpp>
#include <global/CmakeVariables.hpp>
#include "../../COMMON/TestBase.hpp"

class HuntsmanManualTests
		: public TestBase, public ::testing::Test
{
public:
	HuntsmanManualTests() = default;
};

TEST_F( HuntsmanManualTests, StandardRun )
{
	huntsman::Huntsman engine;
//	system("ls ../../../config");
//	system("ls");
	if( spdlog::get( "main" ) ) { spdlog::get( "main" )->info( "yeah so that did happen." ); }
	else { spdlog::get( "" ); }
	engine.start();
}