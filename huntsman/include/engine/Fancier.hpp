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
	template< class TYPE > using MaybeObject = std::optional<std::weak_ptr<TYPE>>;
	template< class TYPE > using ObjectList = std::list<std::weak_ptr<TYPE>>;

	class Fancier
	{
		std::list<std::shared_ptr<Object>> hounds_;

		std::unordered_map<std::type_index, std::list<std::weak_ptr<Object>>> objectMapping_;
	public:

		template< class TYPE > MaybeObject<TYPE> getFirst();
		template< class TYPE > MaybeObject<TYPE> getFirst( std::function<bool( TYPE )> const& predicate );
		template< class TYPE > MaybeObject<TYPE> getUnique();
		template< class TYPE > MaybeObject<TYPE> getUnique( std::function<bool( TYPE )> const& predicate );

		template< class TYPE > std::list<std::weak_ptr<TYPE>> get();
		template< class TYPE > std::list<std::weak_ptr<TYPE>> get( std::function<bool( TYPE )> predicate );


	};

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getFirst()
	{
		auto objectList = get<TYPE>();
		return objectList.empty ? nullptr : objectList.front();
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getFirst( std::function<bool( TYPE )> const& predicate )
	{
		auto objectList = get( predicate );
		return objectList.empty() ? nullptr : objectList;
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getUnique()
	{
		auto result = get<TYPE>();

		return result.size() != 1 ? nullptr : result.front();
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getUnique( std::function<bool( TYPE )> const& predicate )
	{
		auto            result = get<TYPE>();
		std::list<TYPE> out;

		for( const auto& elem : result )
		{
			if( predicate( elem ) ) { out.push_back( elem ); }
		}

		return out.size() != 1 ? nullptr : out.front();
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

	template< class TYPE >
	std::list<std::weak_ptr<TYPE>> Fancier::get( std::function<bool( TYPE )> predicate )
	{
		std::list<std::weak_ptr<TYPE>> out;

		for( auto const& elem:get<TYPE>() )
		{
			if( predicate( elem ) )
			{
				out.push_back( elem );
			}
		}
		return out;
	}
}


using Fancier = huntsman::Fancier;