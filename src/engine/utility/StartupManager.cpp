//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <engine/utility/StartupManager.hpp>

#include "engine/utility/StartupManager.hpp"


namespace huntsman
{
	StartupManager::StartupManager( Huntsman& huntsman, Settings const& settings ) :
			huntsman_( huntsman ), settings_( settings ) {}

	bool StartupManager::initialiseHuntsman()
	{
		return false;
	}
}
