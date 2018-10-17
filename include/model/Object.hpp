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
		// ====================================================================
		//								FIELDS
		// ====================================================================
		std::string id_;

	protected:
		Object();
		virtual ~Object() = default;

		virtual std::string getName();
	public:
		// ====================================================================
		//  						PUBLIC FUNCTIONS
		// ====================================================================
		void log();

		// ====================================================================
		//								ACCESS
		// ====================================================================
		std::string getId() { return id_; }
	};
}