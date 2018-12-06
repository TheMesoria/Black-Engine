//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <vector>

#include <Logger.hpp>
#include <engine/utility/SettingsFacade.hpp>
#include <engine/view/components/HuntingGroundChunk.hpp>

namespace huntsman::view
{
	using Grid            = std::vector<std::vector<HuntingGroundChunk>>;
	using Size            = size_t;
	using GridSize        = std::pair<Size, Size>;

	class HuntingGround
	{
		Size     gridChunkSize_;
		Grid     grid_;

		LoggerPtr logger_;

	public:
		HuntingGround() = delete;
		HuntingGround( HuntingGround& ) = default;
		HuntingGround( Settings const& settings );
		HuntingGround& operator=( HuntingGround const& ) = default;

		HuntObject* verifyCollision(HuntObject* testObject);

	private:
		void createGrid(GridSize const& gridSize);
	};
}

using HuntingGround = huntsman::view::HuntingGround;