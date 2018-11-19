//
// Created by Wojciech Ormaniec on 23.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#include <model/Object.hpp>
#include <list>
#include <typeindex>

namespace huntsman
{
	class Fancier
	{
		std::list<std::shared_ptr<Object>>                                    hounds_;
		std::unordered_map<std::type_index, std::list<std::weak_ptr<Object>>> objectMapping_;
	public:
		template< class TYPE > std::weak_ptr<TYPE> getUnique();
		template< class TYPE > std::weak_ptr<TYPE> getUnique(std::function<bool(Object)> const& );
		template< class TYPE > std::list<std::weak_ptr<TYPE>> get();


	};

	template< class TYPE >
	std::weak_ptr<TYPE> Fancier::getUnique()
	{
		return std::dynamic_pointer_cast<TYPE>( objectMapping_.at( typeid( TYPE ) ).front() );
	}

	template< class TYPE >
	std::list<std::weak_ptr<TYPE>> Fancier::get()
	{
		std::list<std::weak_ptr<TYPE>> outList;
		for( auto& ref : objectMapping_.at( typeid( TYPE ) ) )
		{
			outList.push_back( std::dynamic_pointer_cast<TYPE>( ref.lock() ) );
		}
		return outList;
	}
}

using Fancier = huntsman::Fancier;