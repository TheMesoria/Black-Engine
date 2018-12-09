//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#include <list>

#include <model/hunt/HuntObject.hpp>

namespace huntsman::view::component
{
	struct HuntingGroundChunk
	{
		std::list<std::weak_ptr<HuntObject>> availableHuntObjectList_;

		HuntingGroundChunk() = default;
		HuntingGroundChunk( HuntingGroundChunk& ) = default;
		HuntingGroundChunk& operator=( HuntingGroundChunk const& ) = default;
	};
}

using HuntingGroundChunk = huntsman::view::component::HuntingGroundChunk;