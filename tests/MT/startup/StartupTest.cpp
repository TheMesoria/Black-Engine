//
// Created by Wojciech Ormaniec on 04.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <gtest/gtest.h>

#include "../../COMMON/TestBase.hpp"

class OnStartupShould
: public TestBase, public ::testing::Test
{
public:
	OnStartupShould() = default;
};

TEST_F( OnStartupShould, Exist )
{
}