//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/Object.hpp>
#include <global/Generators.hpp>

#include "model/Object.hpp"

namespace huntsman::model
{
	std::function<std::string()> Object::idGenerator = []() { return Global::Default::Functions::GenerateId(); };

	Object::Object()
			: id_( idGenerator())
			  , logger_( spdlog::get( "main" )) {}

	void Object::log( std::string const &message, spdlog::level::level_enum level )
	{
		std::string parseMessage = "[" + id_ + "]" + message;
		logger_->log(
				level,
				parseMessage
		);
	}

}
