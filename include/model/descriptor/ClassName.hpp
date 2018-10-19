//
// Created by Wojciech Ormaniec on 19.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <string>
#include <cxxabi.h>

class Object;

#pragma once

class ClassName
{
	int errorCode_;
	std::string value_;

public:
	ClassName( Object *object )
	: value_(abi::__cxa_demangle( typeid( object ).name(), 0, 0, &errorCode_ )) {}

	explicit operator int()
	{
		return errorCode_;
	}
	explicit operator const std::string& ()
	{
		return value_;
	}
};
