//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/Object.hpp>
#include <global/Generators.hpp>

#include "model/Object.hpp"

namespace Model
{
	Object::Object()
			: id_( idGenerator()) {}
}

std::function<std::string()> Model::Object::idGenerator = [](){ return Global::Default::Functions::GenerateId(); };