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
    return true;
}

HuntObject* HuntingGround::verifyCollision(HuntObject* test)
{
    auto[positionX, positionY]  = test->getPosition();
    auto[sizeX, sizeY]          = test->getSize();

    int idX = static_cast<int>((int) positionX / this->gridChunkSize_),
        idY = static_cast<int>((int) positionY / this->gridChunkSize_);

    // Collision occurs with map border
    if (idX == 0 || idY == 0)
    {
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

    }
    else
    {
        LOG_ERR(logger_, "Object have been not moved!");
    }

}

void HuntingGround::add(std::shared_ptr<HuntObject>& obj)
{
    auto[positionX, positionY] = obj->getPosition();

    int idX = static_cast<int>((int) positionX / this->gridChunkSize_),
        idY = static_cast<int>((int) positionY / this->gridChunkSize_);

    auto& chunk = grid_[idX][idY];

    chunk.availableHuntObjectList_.push_back(obj);
}

bool HuntingGround::pop(std::shared_ptr<HuntObject>& obj)
{
    auto[positionX, positionY] = obj->getPosition();

    int idX = static_cast<int>((int) positionX / this->gridChunkSize_),
        idY = static_cast<int>((int) positionY / this->gridChunkSize_);

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