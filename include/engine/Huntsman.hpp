//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <bits/shared_ptr.h>
#include <spdlog/logger.h>

namespace huntsman
{
	class Huntsman
	{
		std::shared_ptr<spdlog::logger> logger_;
	public:
		Huntsman();

	private:
		bool initialiseLogger();
	};
}

