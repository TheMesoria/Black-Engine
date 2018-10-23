//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <engine/Huntsman.hpp>
#include <spdlog/spdlog.h>

#include "engine/Huntsman.hpp"

namespace huntsman
{
	Huntsman::Huntsman()
	{

	}

	bool Huntsman::initialiseLogger()
	{
		logger_ = spdlog::create( "main",
								  {
//			spdlog::sinks::
								  } );
	}
}