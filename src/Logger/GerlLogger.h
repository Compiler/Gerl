#ifndef GERLLOGGER_H
#define GERLLOGGER_H
#pragma once
#include <stdio.h>



#define RED         "\x1B[31m"
#define RED_BLD     "\x1B[1;31m"
#define GRN         "\x1B[32m"
#define YEL         "\x1B[33m"
#define BLU         "\x1B[34m"
#define MAG         "\x1B[35m"
#define CYN         "\x1B[36m"
#define WHT         "\x1B[37m"


#define RESET "\x1B[0m"

#define GERL_FATAL(...) printf(RED_BLD "!GerlFatal!:\t\t"); printf(__VA_ARGS__ RESET);
#define GERL_ERROR(...) printf(RED "GerlError:\t"); printf(__VA_ARGS__ RESET);
#define GERL_WARN(...) printf(YEL "GerlWarn:\t"); printf(__VA_ARGS__ RESET);
#define GERL_DEBUG(...) printf(GRN "GerlDebug:\t"); printf(__VA_ARGS__ RESET);
#define GERL_LOG(...) printf(BLU "GerlLog:\t"); printf(__VA_ARGS__ RESET);

#endif