//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <memory>

#include <nlohmann/json.hpp>

namespace huntsman::utility
{
	using nlohmann::json;

	class Settings
	{
	public:
		Settings() = default;
		explicit Settings( std::string const &settingsFilePath );
	private:
		json activeConfigFile_;
	};
}

