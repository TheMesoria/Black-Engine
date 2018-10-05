//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <model/GameObject.hpp>

#include "model/GameObject.hpp"

GameObject::GameObject()
		: id_( activeId_++ ) {}

GameObject::GameObject( unsigned long long id )
		: id_( id ) {}