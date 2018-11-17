//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/Object.hpp>
#include <global/Generators.hpp>
#include <global/Macros.hpp>

#include "model/Object.hpp"
#include <Logger.hpp>

namespace huntsman::model
{
	std::function<std::string()> Object::idGenerator = []() { return Global::Default::Functions::GenerateId(); };

	Object::Object()
			: id_( idGenerator())
			  , logger_( spdlog::get( "main" ))
			  {
				  LOG_DEBUG_O(logger_, "[CTOR]");
			  }

}
