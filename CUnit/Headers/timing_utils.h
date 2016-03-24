/*****************************************************************************
* Project:     CBCUnit
* File:        timing_utils.h
* Created:     08 Jan 2016
* Copyright(c) 2016 by CriticalBlue Ltd.
****************************************************************************/

#ifndef TIMING_UTILS_H
#define TIMING_UTILS_H

#ifdef    __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdio.h>

#define USE_TIMING_UTILS

#ifdef USE_TIMING_UTILS
#define CLOCK_TIME(CLK) struct timespec CLK;\
    clock_gettime(CLOCK_MONOTONIC_RAW, &CLK)
#define TIME_DIFF_USECS(CLK_ST, CLK_ET) ((((long long)CLK_ET.tv_sec - (long long)CLK_ST.tv_sec) * 1000000) + (((long long)CLK_ET.tv_nsec - (long long)CLK_ST.tv_nsec) / 1000))
#define TIME_DIFF_NSECS(CLK_ST, CLK_ET) ((((long long)CLK_ET.tv_sec - (long long)CLK_ST.tv_sec) * 1000000000) + ((long long)CLK_ET.tv_nsec - (long long)CLK_ST.tv_nsec))
#define PRINT_REPS printf
#define PRINT_TIME printf
#define PRINT_RATE(CLK_ST, CLK_ET, TRANSACTION_COUNT, TRANSACTION_NAME) (PRINT_TIME("Rate: %.2f %s/s\n", ((double)TRANSACTION_COUNT / ((double)TIME_DIFF_NSECS(CLK_ST, CLK_ET) / 1000000000)), TRANSACTION_NAME))
#else
#define CLOCK_TIME(CLK)
#define TIME_DIFF_USECS(CLK_ST, CLK_ET) 1
#define TIME_DIFF_NSECS(CLK_ST, CLK_ET) 1
#define CHOMP(...)
#define PRINT_REPS CHOMP
#define PRINT_TIME CHOMP
#define PRINT_RATE CHOMP
#endif

#ifdef    __cplusplus
}
#endif

#endif /* TIMING_UTILS_H */

