//
// Created by Wojciech Ormaniec on 30.09.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <gtest/gtest.h>
#include "../COMMON/TestBase.hpp"

bool TestBase::GTEST_LOGGING;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    for (auto i = 0; i < argc; i++)
    {
        std::string val  = argv[i];
        std::size_t find = val.find("LOGGER");
        if (find != std::string::npos)
        {
            TestBase::GTEST_LOGGING = true;
        }
    }
    std::cout << "GTEST_LOGGING : " << std::boolalpha << TestBase::GTEST_LOGGING << std::endl;

    return RUN_ALL_TESTS();
}