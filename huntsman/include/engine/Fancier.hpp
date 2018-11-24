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
	template< class TYPE > using MaybeObject = std::optional<std::shared_ptr<TYPE>>;
	template< class TYPE > using ObjectList = std::list<std::shared_ptr<TYPE>>;
	template< class TYPE > using Predicate = std::function<bool( TYPE )>;


	class Fancier
	{
		std::list<std::shared_ptr<Object>> hounds_;

		std::unordered_map<std::type_index, std::list<std::shared_ptr<Object>*>> objectMapping_;
	public:

		template< class TYPE > MaybeObject<TYPE> getFirst();
		template< class TYPE > MaybeObject<TYPE> getFirst( Predicate<TYPE> const& predicate );
		template< class TYPE > MaybeObject<TYPE> getUnique();
		template< class TYPE > MaybeObject<TYPE> getUnique( Predicate<TYPE> const& predicate );

		template< class TYPE > std::list<std::shared_ptr<TYPE>> get();
		template< class TYPE > std::list<std::shared_ptr<TYPE>> get( std::function<bool( TYPE )> predicate );

		template< class TYPE > bool removeFirst();
		template< class TYPE > bool removeFirst( Predicate<TYPE> predicate );


		template< class TYPE > bool remove( Predicate<TYPE> predicate );

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
		auto objectList = get<TYPE>( predicate );
		return objectList.empty() ? nullptr : objectList.front();
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
		auto result = get<TYPE>( predicate );

		return result.size() != 1 ? nullptr : result.front();
	}

	template< class TYPE >
	std::list<std::shared_ptr<TYPE>> Fancier::get()
	{
		std::list<std::shared_ptr<TYPE>> outList;
		for( const auto& ref : objectMapping_.at( typeid( TYPE ) ) )
		{
			if( ref ) { outList.push_back( std::dynamic_pointer_cast<TYPE>( *ref ) ); }
		}
		return outList;
	}

	template< class TYPE >
	std::list<std::shared_ptr<TYPE>> Fancier::get( std::function<bool( TYPE )> predicate )
	{
		std::list<std::shared_ptr<TYPE>> out;

		for( auto const& elem : objectMapping_.at( typeid( TYPE ) ) )
		{
			auto elemOfType = std::dynamic_pointer_cast<TYPE>( *elem );
			if( predicate( elemOfType ) )
			{
				out.push_back( elemOfType );
			}
		}
		return out;
	}

	template< class TYPE >
	bool Fancier::removeFirst()
	{

	}
}


using Fancier = huntsman::Fancier;