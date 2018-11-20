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
		template< class TYPE > MaybeObject<TYPE> getFirst( std::function<bool( Object )> const& predicate );
		template< class TYPE > MaybeObject<TYPE> getUnique();
		template< class TYPE > MaybeObject<TYPE> getUnique( std::function<bool( Object )> const& predicate );

		template< class TYPE > std::list<std::weak_ptr<TYPE>> get();


	};

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getFirst( std::function<bool( Object )> const& predicate )
	{
		return std::optional<std::weak_ptr<TYPE>>();
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getFirst()
	{
		return std::dynamic_pointer_cast<TYPE>( objectMapping_.at( typeid( TYPE ) ).front() );
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getUnique()
	{
		auto result = get<TYPE>();

		return result.size() != 1 ? nullptr : result.front();
	}

	template< class TYPE >
	MaybeObject<TYPE> Fancier::getUnique( std::function<bool( Object )> const& predicate )
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

}

using Fancier = huntsman::Fancier;