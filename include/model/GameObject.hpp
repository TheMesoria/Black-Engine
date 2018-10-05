//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once


class GameObject
{
private:
	static unsigned long long activeId_;

	// ULONG_LONG_MAX == 18.446.744.073.709.551.615
	const unsigned long long id_;

protected:
	GameObject();
	GameObject(unsigned long long id);

public:
	virtual ~GameObject() = default;

	long unsigned getId() { return id_; }
};