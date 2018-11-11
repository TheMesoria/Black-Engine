//
// Created by Wojciech Ormaniec on 31.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <experimental/filesystem>

#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/ansicolor_sink.h>
#include <spdlog/sinks/file_sinks.h>

namespace huntsman
{

	using spdlog::level::level_enum;
	using spdlog::logger;

	class LoggerHelper
	{
	public:
		spdlog::sink_ptr getSink(
				std::string const& type
				, std::string const& level
				, std::string const& path = "" );

		template< class SinkType >
		spdlog::sink_ptr getSink( level_enum logLevel = spdlog::level::info );

		template< class SinkType >
		spdlog::sink_ptr getFileSink( std::string const& filePath, level_enum logLevel = spdlog::level::info );
	};


	template< class SinkType >
	spdlog::sink_ptr LoggerHelper::getSink( level_enum logLevel )
	{
		auto sink = std::make_shared<SinkType>();

		if( logLevel != level_enum::debug )
			sink->set_level( logLevel );

		return sink;
	}

	template< class SinkType >
	spdlog::sink_ptr LoggerHelper::getFileSink( std::string const& filePath, level_enum logLevel )
	{
		auto sink = std::make_shared<SinkType>( filePath );
		if( logLevel != level_enum::debug ) sink->set_level( logLevel );
		return sink;
	}

	spdlog::sink_ptr LoggerHelper::getSink(
			std::string const& type
			, std::string const& level
			, std::string const& path )
	{
		if( "stderr-sink-mt" == type )
		{
			return getSink<spdlog::sinks::stderr_sink_mt>( spdlog::level::from_str( level ) );
		}
		else if( "stdout-sink-mt" == type )
		{
			return getSink<spdlog::sinks::stdout_sink_mt>( spdlog::level::from_str( level ) );
		}
		else if( "ansicolor-stdout-sink" == type )
		{
			return getSink<spdlog::sinks::ansicolor_stdout_sink_mt>( spdlog::level::from_str( level ) );
		}
		else if( "simple-file-sink-mt" == type )
		{
			return getFileSink<spdlog::sinks::simple_file_sink_mt>( path, spdlog::level::from_str( level ) );
		}

		return spdlog::sink_ptr();
	}

}

