//
// Created by Wojciech Ormaniec on 01.10.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <functional>
#include <spdlog/spdlog.h>

#pragma once

namespace huntsman::model
{
	class Object
	{
	private:
		static std::function<std::string()> idGenerator;

		std::string id_;

		std::shared_ptr<spdlog::logger> logger_;
	protected:
		Object();
		virtual ~Object() = default;

		virtual std::string getClassName() { return "Object"; }
	public:
		void log(std::string const& message, spdlog::level::level_enum level);
		std::string getId() { return id_; }
	};
}

using Object = huntsman::model::Object;