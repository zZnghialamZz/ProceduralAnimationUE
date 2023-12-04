// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#pragma once

#include "Logging/LogMacros.h"

PROCEDURALANIM_API DECLARE_LOG_CATEGORY_EXTERN(LogProcAnim, Log, All);

#define PALOG(type, msg, ...) UE_LOG(LogProcAnim, type, TEXT(msg), ##__VA_ARGS__)

#define PALOG_DISPLAY(msg, ...) UE_LOG(LogProcAnim, Display, TEXT(msg), ##__VA_ARGS__)
#define PALOG_WARNING(msg, ...) UE_LOG(LogProcAnim, Warning, TEXT(msg), ##__VA_ARGS__)
#define PALOG_ERROR(msg, ...) UE_LOG(LogProcAnim, Error, TEXT(msg), ##__VA_ARGS__)
#define PALOG_FATAL(msg, ...) UE_LOG(LogProcAnim, Fatal, TEXT(msg), ##__VA_ARGS__)
