/* File: sse_calls.h */
/*
  This file is a part of the Corrfunc package
  Copyright (C) 2015-- Manodeep Sinha (manodeep@gmail.com)
  License: MIT LICENSE. See LICENSE file under the top-level
  directory at https://github.com/manodeep/Corrfunc/
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <nmmintrin.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "function_precision.h"

#if defined(__GNUC__) || defined(__GNUG__)
#define SSE_BIT_COUNT_INT(X)                __builtin_popcount(X)
#else
#define SSE_BIT_COUNT_INT(X)                _popcnt32(X)
#endif


#ifndef DOUBLE_PREC

#define SSE_NVEC                         4
#define SSE_INTS                         __m128i
#define SSE_FLOATS                       __m128

#define SSE_LOAD_FLOATS_UNALIGNED(X)     _mm_loadu_ps(X)
#define SSE_MULTIPLY_FLOATS(X,Y)         _mm_mul_ps(X,Y)
#define SSE_SUBTRACT_FLOATS(X,Y)         _mm_sub_ps(X,Y)
#define SSE_ADD_FLOATS(X,Y)              _mm_add_ps(X,Y)
#define SSE_SQRT_FLOAT(X)                _mm_sqrt_ps(X)
#define SSE_TRUNCATE_FLOAT_TO_INT(X)     _mm_cvttps_epi32(X)
#define SSE_SQUARE_FLOAT(X)              _mm_mul_ps(X,X)
#define SSE_SET_FLOAT(X)                 _mm_set1_ps(X)

#define SSE_COMPARE_FLOATS_GE(X,Y)       _mm_cmpge_ps(X,Y)
#define SSE_COMPARE_FLOATS_LT(X,Y)       _mm_cmplt_ps(X,Y)

// X OP Y
//#define SSE_COMPARE_FLOATS(X,Y,OP)        _mm_cmp_ps(X,Y,OP)
#define SSE_BITWISE_AND(X,Y)              _mm_and_ps(X,Y)

//MoveMask
#define SSE_TEST_COMPARISON(X)            _mm_movemask_ps(X)

#define SSE_BLEND_FLOATS_WITH_MASK(FALSEVALUE,TRUEVALUE,MASK) _mm_blendv_ps(FALSEVALUE,TRUEVALUE,MASK)

//Max
#define SSE_MAX_FLOATS(X,Y)               _mm_max_ps(X,Y)


#else //DOUBLE PRECISION CALCULATIONS

#define SSE_NVEC                         2
#define SSE_INTS                         __m128i
#define SSE_FLOATS                       __m128d

#define SSE_SET_FLOAT(X)                  _mm_set1_pd(X)
#define SSE_LOAD_FLOATS_UNALIGNED(X)     _mm_loadu_pd(X)
#define SSE_LOAD_FLOATS_ALIGNED(X)       _mm_load_pd(X)

//Math ops
#define SSE_MULTIPLY_FLOATS(X,Y)         _mm_mul_pd(X,Y)
#define SSE_SUBTRACT_FLOATS(X,Y)         _mm_sub_pd(X,Y)
#define SSE_ADD_FLOATS(X,Y)              _mm_add_pd(X,Y)
#define SSE_SQRT_FLOAT(X)                _mm_sqrt_pd(X)
#define SSE_SQUARE_FLOAT(X)              _mm_mul_pd(X,X)

//Memory stores
#define SSE_TRUNCATE_FLOAT_TO_INT(X)     _mm_cvttpd_epi32(X)
#define SSE_STORE_FLOATS_TO_MEMORY(X,Y)  _mm_storeu_pd(X,Y)

//The comparisons
#define SSE_COMPARE_FLOATS_GE(X,Y)       _mm_cmpge_pd(X,Y)
#define SSE_COMPARE_FLOATS_LT(X,Y)       _mm_cmplt_pd(X,Y)

//Bitwise and
#define SSE_BITWISE_AND(X,Y)              _mm_and_pd(X,Y)

//MoveMask
#define SSE_TEST_COMPARISON(X)            _mm_movemask_pd(X)

#define SSE_BLEND_FLOATS_WITH_MASK(FALSEVALUE,TRUEVALUE,MASK) _mm_blendv_pd(FALSEVALUE,TRUEVALUE,MASK)




#endif
