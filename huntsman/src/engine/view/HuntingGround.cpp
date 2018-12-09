//
// Created by Wojciech Ormaniec on 11.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "engine/view/HuntingGround.hpp"

#include <Logger.hpp>
#include <engine/view/HuntingGround.hpp>


namespace huntsman::view
{

HuntingGround::HuntingGround(Settings const& settings)
    :
    gridChunkSize_(settings.getHuntingGroundChunkSize())
    , logger_(spdlog::get("main"))
{
    createGrid(settings.getHuntingGroundSize());

    LOG_DEBUG_F(logger_, "Hunting ground size : {} pixels.", gridChunkSize_ * grid_.size());
    LOG_INFO(logger_, "Hunting ground ready.");
}

void HuntingGround::createGrid(GridSize const& gridSize)
{
    auto[gridX, gridY] = gridSize;
    LOG_DEBUG_F(logger_, "Creating hunting grid of size: x = {}, y={}", gridX, gridY);
    for (auto i = 0u; i < gridX; i++)
    {
        grid_.emplace_back(gridY);
    }
}

bool CheckCollision(HuntObject* obj_1, HuntObject* obj_2)
{
    auto[obj_1X, obj_1Y] = obj_1->getPosition();
    auto[obj_2X, obj_2Y] = obj_2->getPosition();

    auto[obj_1sizeX, obj_1sizeY] = obj_1->getSize();
    auto[obj_2sizeX, obj_2sizeY] = obj_2->getSize();

    if ((obj_1Y + obj_1sizeY) > obj_2Y && obj_1Y < obj_2Y)
    {
        if ((obj_1X + obj_1sizeX) > obj_2X && obj_1X < obj_2X)
        {
            return true;
        }
        else if (obj_1X > obj_2X && (obj_1X + obj_1sizeX) < (obj_2X + obj_2sizeX))
        {
            return true;
        }
    }
    else if( obj_1Y  < (obj_2Y+obj_2sizeY) && obj_1Y > obj_2Y )
    {
        if ((obj_1X + obj_1sizeX) > obj_2X && obj_1X < obj_2X)
        {
            return true;
        }
        else if (obj_1X > obj_2X && (obj_1X + obj_1sizeX) < (obj_2X + obj_2sizeX))
        {
            return true;
        }
    }

    return false;
}

HuntObject* HuntingGround::verifyCollision(HuntObject* test)
{
    auto[positionX, positionY]  = test->getPosition();
    auto[sizeX, sizeY]          = test->getSize();

    int idX = static_cast<int>((int) positionX / this->gridChunkSize_) + 1,
        idY = static_cast<int>((int) positionY / this->gridChunkSize_) + 1;

    // Collision occurs with map border
    if (idX == 0 || idY == 0)
    {
        assert(false && "Object out of the bounds!");
        return nullptr;
    }

    std::vector<HuntingGroundChunk*> activeChunkVector =
                                         {
                                             &grid_[idX - 1][idY - 1], &grid_[idX][idY - 1], &grid_[
                                             idX + 1][idY], &grid_[idX - 1][idY], &grid_[idX][idY]
                                             , &grid_[idX + 1][idY], &grid_[idX - 1][idY + 1]
                                             , &grid_[idX][idY + 1], &grid_[idX + 1][idY + 1],};

    for (auto& chunk : activeChunkVector)
    {
        for (auto& obj : chunk->availableHuntObjectList_)
        {
            if (obj.expired())
            {
                continue;
            }
            auto activeObj = obj.lock();
            if (CheckCollision(test, &*activeObj))
            {
                return &*activeObj;
            }
        }
    }

    return nullptr;
}

void HuntingGround::moveHuntObject(std::shared_ptr<HuntObject>& obj, std::pair<float, float> vector)
{
    LOG_DEBUG_F(logger_
                , "Moving object with vector[{},{}]"
                , vector.first
                , vector.second);

    if (pop(obj))
    {
        auto[positionX, positionY] = obj->getPosition();
        obj->setPosition({positionX - vector.first, positionY - vector.second});

        if (verifyCollision(&*obj) != nullptr)
        {
            auto[positionX, positionY] = obj->getPosition();
            LOG_DEBUG(logger_, "Object Collided!");
            obj->setPosition({positionX + vector.first, positionY + vector.second});
        }

        add(obj);
    }
    else
    {
        LOG_ERR(logger_, "Object have been not moved!");
    }

}

void HuntingGround::add(std::shared_ptr<HuntObject>& obj)
{
    auto[positionX, positionY] = obj->getPosition();

    auto idX = static_cast<int>((int) positionX / this->gridChunkSize_) + 1,
         idY = static_cast<int>((int) positionY / this->gridChunkSize_) + 1;

    LOG_DEBUG_F(logger_, "Registering object on hunting ground [{},{}]", positionX, positionY);

    auto& chunk = grid_[idX][idY];

    chunk.availableHuntObjectList_.push_back(obj);
}

bool HuntingGround::pop(std::shared_ptr<HuntObject>& obj)
{
    auto[positionX, positionY] = obj->getPosition();

    int idX = static_cast<int>((int) positionX / this->gridChunkSize_) + 1,
        idY = static_cast<int>((int) positionY / this->gridChunkSize_) + 1;

    auto& chunk = grid_[idX][idY];

    for (auto mbyObject = chunk.availableHuntObjectList_.begin();
         mbyObject != chunk.availableHuntObjectList_.end(); mbyObject++)
    {
        if (mbyObject->expired())
        {
            chunk.availableHuntObjectList_.erase(mbyObject);
            continue;
        }

        auto activeObj = mbyObject->lock();
        if (activeObj == obj)
        {
            chunk.availableHuntObjectList_.erase(mbyObject);
            return true;
        }
    }

    LOG_CRIT(logger_, "Object not found in chunk, even though it have been requested!");
    return false;
}

}