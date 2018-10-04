//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once


class GameObject
{
private:
	const long unsigned id_;
public:
	GameObject() = default;
	~GameObject() = default;

	long unsigned getId() { return id_; }
};

