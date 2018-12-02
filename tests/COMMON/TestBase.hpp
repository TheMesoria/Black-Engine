//
// Created by Wojciech Ormaniec on 05.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <spdlog/spdlog.h>

class TestBase
{
public:
    static bool GTEST_LOGGING;

    TestBase()
    {

        if (!spdlog::get("main"))
        {
            spdlog::create("main", std::make_shared<spdlog::sinks::stdout_sink_mt>());
            if (GTEST_LOGGING)
            {
                spdlog::get("main")->set_level(spdlog::level::debug);
            }
            else
            {
                spdlog::get("main")->set_level(spdlog::level::off);
            }
        }
    }
};
