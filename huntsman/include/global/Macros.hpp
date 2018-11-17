//
// Created by Wojciech Ormaniec on 12.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_DEBUG_O( logger, msg ) logger->debug("[{}:{}][{}][{}][{}] : {}", __FILENAME__ , __LINE__, __FUNCTION__, this->getId(), this->getClassName(), msg)

#define LOG_DEBUG( logger, msg ) logger->debug("[{}:{}][{}]: {}", __FILENAME__ , __LINE__, __FUNCTION__, msg)
#define LOG_DEBUG_F( logger, formatString, ... ) logger->debug(std::string(std::string("[{}:{}][{}]: ") + std::string(formatString)).c_str(), __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__)

#define LOG_INFO( logger, msg )logger->info("[{}:{}][{}]: {}", __FILENAME__ , __LINE__, __FUNCTION__, msg)
#define LOG_INFO_F( logger, fmt, ... ) logger->info(std::string(std::string("[{}:{}][{}]: ") + std::string(fmt)).c_str(), __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__)

#define LOG_WARN( logger, msg ) logger->warn("[{}:{}][{}]: {}", __FILENAME__ , __LINE__, __FUNCTION__, msg)
#define LOG_WARN_F( logger, fmt, ... ) logger->warn(std::string(std::string("[{}:{}][{}]: ") + std::string(fmt)).c_str(), __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__)

#define LOG_ERR( logger, msg ) logger->error("[{}:{}][{}]: {}", __FILENAME__ , __LINE__, __FUNCTION__, msg)
#define LOG_ERR_F( logger, fmt, ... ) logger->error(std::string(std::string("[{}:{}][{}]: ") + std::string(fmt)).c_str(), __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__)

#define LOG_CRIT( logger, msg ) logger->critical("[{}:{}][{}]: {}", __FILENAME__ , __LINE__, __FUNCTION__, msg)
#define LOG_CRIT_F( logger, fmt, ... ) logger->critical(std::string(std::string("[{}:{}][{}]: ") + std::string(fmt)).c_str(), __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__)
