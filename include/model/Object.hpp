//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <functional>

#pragma once

namespace Model
{
	class Object
	{
	private:
		static std::function<std::string()> idGenerator;

		std::string id_;
	protected:
		Object();

	public:
		virtual ~Object() = default;

		std::string getId() { return id_; }
	};
}