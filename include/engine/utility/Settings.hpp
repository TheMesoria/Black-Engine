//
// Created by Wojciech Ormaniec on 26.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

namespace huntsman::utility::settings
{
	using nlohmann::json;

	json load(std::string const& settingsFilePath);
}
