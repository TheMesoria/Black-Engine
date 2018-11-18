//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <engine/Huntsman.hpp>
#include "SettingsFacade.hpp"

namespace huntsman
{
	class StartupManager
	{
		Settings const& settings_;
		Huntsman      & huntsman_;
		LoggerPtr 		logger_;
	public:
		StartupManager() = delete;
		StartupManager( Huntsman& huntsman, Settings const& settings );

		StartupManager& operator=( StartupManager const& ) = delete;
		bool initialiseHuntsman();
	private:

		bool initialiseLogger();
		bool initialiseHuntingGround();
		bool initialiseFalconer();
	};
}
