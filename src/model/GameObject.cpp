//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/GameObject.hpp>
#include <global/Generators.hpp>

#include "model/GameObject.hpp"

namespace Model
{
	GameObject::GameObject()
			: id_( idGenerator()) {}
}

std::function<std::string()> Model::GameObject::idGenerator = [](){ return Global::Default::Functions::GenerateId(); };