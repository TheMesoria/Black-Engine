//
// Created by Wojciech Ormaniec on 05.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#pragma once

#include <list>

#include <model/Object.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <model/hunt/behavior/Behavior.hpp>

namespace huntsman::model
{
class HuntObject
    : public Object
{
    std::list<std::shared_ptr<Behavior>> behaviors_;
public:
    HuntObject() = default;
    virtual sf::Drawable const& getDrawable() = 0;
    virtual const std::pair<float, float> getSize() = 0;
    virtual void setSize(std::pair<float, float> const&) = 0;
    virtual const std::pair<float, float> getPosition() = 0;
    virtual void setPosition(std::pair<float, float> const&) = 0;

    virtual void onUpdate()
    {};

    void addBehavior(std::shared_ptr<Behavior> behavior)
    {
        behaviors_.push_back(behavior);
    }
    const std::list<std::shared_ptr<Behavior>>& getBehaviors() const
    {
        return behaviors_;
    }
};
}

using HuntObject = huntsman::model::HuntObject;

