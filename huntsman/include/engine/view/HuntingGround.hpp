//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <vector>
#include <engine/utility/Settings.hpp>
#include <engine/view/components/HuntingGroundChunk.hpp>

namespace huntsman
{
	using Grid = std::vector<std::vector<HuntingGroundChunk>>;
	using Size = size_t;

	class HuntingGround
	{
		Size gridSize_;
		Size gridChunkSize_;
		Grid grid_;

	public:
		HuntingGround(Settings settings);

	};
}

using HuntingGround = huntsman::HuntingGround;