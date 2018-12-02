//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#include <model/Object.hpp>
#include <list>
#include <typeindex>
#include <Logger.hpp>
#include <typeinfo>

namespace huntsman
{
template<class TYPE> using MaybeObject = std::optional<std::shared_ptr<TYPE>>;
template<class TYPE> using CastObjectList = std::list<std::shared_ptr<TYPE>>;
template<class TYPE> using Predicate = std::function<bool(TYPE)>;
template<class TYPE> using CastObjectPtr = std::shared_ptr<TYPE>;

using ObjectPtr = std::shared_ptr<Object>;
using ObjectList = std::list<ObjectPtr>;
using MapNode = std::pair<std::type_index, std::list<ObjectList::iterator>>;
using ObjectMapping = std::unordered_map<std::type_index, std::list<ObjectList::iterator>>;


class Fancier
{
    ObjectList    hounds_;
    ObjectMapping objectMapping_;

    LoggerPtr logger_;
public:
    Fancier(LoggerPtr loggerPtr)
        : logger_(loggerPtr)
    {};

    template<class TYPE> CastObjectPtr<TYPE> add();

    template<class TYPE> MaybeObject<TYPE> getFirst();
    template<class TYPE> MaybeObject<TYPE> getFirst(Predicate<TYPE> const& predicate);
    template<class TYPE> MaybeObject<TYPE> getUnique();
    template<class TYPE> MaybeObject<TYPE> getUnique(Predicate<TYPE> const& predicate);

    template<class TYPE> CastObjectList<TYPE> get();
    template<class TYPE> CastObjectList<TYPE> get(Predicate<TYPE> predicate);

    template<class TYPE> bool removeFirst();
    template<class TYPE> bool removeFirst(Predicate<TYPE> predicate);

    template<class TYPE> bool remove(Predicate<TYPE> predicate);

};

template<class TYPE>
MaybeObject<TYPE> Fancier::getFirst()
{
    auto objectList = get<TYPE>();
    return objectList.empty() ? nullptr : std::static_pointer_cast<TYPE>(objectList.front());
}

template<class TYPE>
MaybeObject<TYPE> Fancier::getFirst(std::function<bool(TYPE)> const& predicate)
{
    auto objectList = get<TYPE>(predicate);
    return objectList.empty() ? nullptr : std::static_pointer_cast<TYPE>(objectList.front());
}

template<class TYPE>
MaybeObject<TYPE> Fancier::getUnique()
{
    auto objectList = get<TYPE>();

    return objectList.size() != 1 ? nullptr : std::static_pointer_cast<TYPE>(objectList.front());
}

template<class TYPE>
MaybeObject<TYPE> Fancier::getUnique(std::function<bool(TYPE)> const& predicate)
{
    auto objectList = get<TYPE>(predicate);

    return objectList.size() != 1 ? nullptr : std::static_pointer_cast<TYPE>(objectList.front());
}

template<class TYPE>
CastObjectList<TYPE> Fancier::get()
{
    std::list<std::shared_ptr<TYPE>> objectList;
    for (const auto& ref : objectMapping_.at(typeid(TYPE)))
    {
        if (*ref)
        {
            objectList.push_back(std::dynamic_pointer_cast<TYPE>(*ref));
        }
    }
    return objectList;
}

template<class TYPE>
CastObjectList<TYPE> Fancier::get(std::function<bool(TYPE)> predicate)
{
    std::list<std::shared_ptr<TYPE>> out;

    for (auto const& elem : objectMapping_.at(typeid(TYPE)))
    {
        auto elemOfType = std::dynamic_pointer_cast<TYPE>(*elem);
        LOG_DEBUG_F(logger_, "Text: {}", elemOfType->Text);
        if (predicate(*elemOfType))
        {
            out.push_back(elemOfType);
        }
    }
    return out;
}

template<class TYPE>
bool Fancier::removeFirst()
{
    auto objectList = objectMapping_.find(typeid(TYPE));
    if (objectList != objectMapping_.end())
    {
        objectList->second.pop_front();
        return true;
    }

    LOG_DEBUG_F(logger_
                , "Requested item could not be found in local storage! [{}]"
                , typeid(TYPE).name());
    return false;
}

template<class TYPE>
bool Fancier::removeFirst(Predicate<TYPE> predicate)
{
    auto objectList = objectMapping_.find(typeid(TYPE));
    if (objectList != objectMapping_.end())
    {
        for (auto& elem : objectList->second)
        {
            auto val = std::static_pointer_cast<TYPE>(elem);
            if (predicate(val))
            {
                objectList->second.pop_front();
                return true;
            }
        }
    }

    LOG_DEBUG_F(logger_
                , "Requested item could not be found in local storage! [{}][{}]"
                , typeid(TYPE).name()
                , typeid(predicate).name());
    return false;
}

template<class TYPE>
bool Fancier::remove(Predicate<TYPE> predicate)
{
    auto objectList = objectMapping_.find(typeid(TYPE));
    auto removeList = std::list<ObjectList::iterator>();
    auto returnFlag = false;
    if (objectList != objectMapping_.end())
    {
        for (auto& elem : objectList->second)
        {
            auto val = std::static_pointer_cast<TYPE>(*elem);
            if (predicate(*val))
            {
                hounds_.remove(*elem);
                removeList.push_back(elem);
                returnFlag = true;
            }
        }
        for (auto& elem : removeList)
        {
            objectList->second.remove(elem);
        }
    }

    if (returnFlag)
        LOG_DEBUG_F(logger_
                    , "Requested item could not be found in local storage! [{}][{}]"
                    , typeid(TYPE).name()
                    , typeid(predicate).name());
    return returnFlag;
}

template<class TYPE>
CastObjectPtr<TYPE> Fancier::add()
{
    hounds_.push_back(std::dynamic_pointer_cast<Object>(std::make_shared<TYPE>()));

    if (objectMapping_.find(typeid(TYPE)) == objectMapping_.end())
    {
        objectMapping_.insert({typeid(TYPE), {}});
    }
    objectMapping_.at(typeid(TYPE)).push_back(--hounds_.end());

    return std::static_pointer_cast<TYPE>(*(--hounds_.end()));
}

}


using Fancier = huntsman::Fancier;