﻿/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#ifndef __TOLUA_EXT_H__
#define __TOLUA_EXT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "tolua++.h"

typedef int LuaFunctionRef;

#ifndef TOLUA_REFID_FUNCTION_MAPPING
#define TOLUA_REFID_FUNCTION_MAPPING "__trfm__"
#endif

TOLUA_API void luaopen_tolua_ext( lua_State* L );

TOLUA_API int tolua_ext_isfunction( lua_State* L, int lo, const char* type, int def, tolua_Error* err );
TOLUA_API int tolua_ext_tofunction( lua_State* L, int lo, int def );

TOLUA_API void tolua_ext_get_function_by_refid( lua_State* L, int refid );
TOLUA_API void tolua_ext_remove_function_by_refid( lua_State* L, int refid );

#ifdef __cplusplus
}
#endif


#endif //__TOLUA_EXT_H__