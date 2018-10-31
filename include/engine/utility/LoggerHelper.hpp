//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <spdlog/common.h>
#include <spdlog/logger.h>

namespace huntsman
{

	using spdlog::level::level_enum;
	using spdlog::logger;

	class LoggerHelper
	{
		template< class SinkType >
		spdlog::sink_ptr getSink( level_enum logLevel = spdlog::level::info );

		template< class SinkType >
		spdlog::sink_ptr getFileSink( std::string const &filePath, level_enum logLevel = spdlog::level::info );
	};


	template< class SinkType >
	spdlog::sink_ptr LoggerHelper::getSink( level_enum logLevel )
	{
		auto sink = std::make_shared<SinkType>();
		sink->set_level( logLevel );
		return sink;
	}

	template< class SinkType >
	spdlog::sink_ptr LoggerHelper::getFileSink( std::string const &filePath, level_enum logLevel )
	{
		auto sink = std::make_shared<SinkType>( filePath );
		sink->set_level( logLevel );
		return sink;
	}

}

