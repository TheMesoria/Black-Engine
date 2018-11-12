//
// Created by Wojciech Ormaniec on 12.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_DEBUG( logger, fmt, ... ) \
{ \
logger->info("[{}#{}][{}]: ", __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__); \
}

#define LOG_INFO( logger, ... ) \
{ \
logger->info("[{}#{}][{}]: ", __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__); \
}

#define LOG_WARN( logger, ... ) \
{ \
logger->warn("[{}#{}][{}]: ", __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__); \
}

#define LOG_CRIT( logger, ... ) \
{ \
logger->critical("[{}#{}][{}]: ", __FILENAME__ , __LINE__, __FUNCTION__, __VA_ARGS__); \
}
