/**
 * @file
 * @brief Core macros.
 */
#pragma once

#if defined(L_GCC) || defined(L_CLANG)
#   define L_FUNCSIG __PRETTY_FUNCTION__
#elif defined(L_MSVC)
#	define L_FUNCSIG __FUNCSIG__
#else
#	error "Unsupported compiler"
#endif

#if defined(L_GCC)
#	define VARARGS		__attribute__((cdecl))
#	define FORCEINLINE	inline __attribute__((always_inline))
#	define STDCALL		__attribute__((stdcall))
#elif defined(L_CLANG)
#	define FORCEINLINE  __forceinline
#	define VARARGS      __cdecl
#	define STDCALL      __stdcall
#elif defined(L_MSVC)
#	define FORCEINLINE __forceinline
#	define VARARGS     __cdecl
#	define STDCALL     __stdcall
#endif

/** 
 * @brief Branch prediction hints. 
 */
#ifndef L_LIKELY
#	if defined(L_GCC) || defined(L_CLANG)
#		define L_LIKELY(x)	 __builtin_expect(!!(x), 1)
#	else
#		define L_LIKELY(x)  (!!(x))
#	endif
#endif /* L_LIKELY */

#ifndef L_UNLIKELY
#	if defined(L_GCC) || defined(L_CLANG)
#		define L_UNLIKELY(x)  __builtin_expect(!!(x), 0)
#	else
#		define L_UNLIKELY(x)  (!!(x))
#	endif
#endif /* L_UNLIKELY */
