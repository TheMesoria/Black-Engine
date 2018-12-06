//
// Created by Wojciech Ormaniec on 05.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once


#include <model/Object.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace huntsman::model
{
class HuntObject
    : public Object
{
public:
    HuntObject() = default;
    virtual sf::Drawable const& getDrawable() = 0;
    virtual std::pair<float,float> const& getSize() = 0;
    virtual std::pair<float,float> const& getPosition() = 0;
};
}

using HuntObject = huntsman::model::HuntObject;

