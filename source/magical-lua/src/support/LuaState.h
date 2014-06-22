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
#ifndef __LUA_STATE_H__
#define __LUA_STATE_H__

#include "Object.h"
#include "LuaSupport.h"

class LuaState_t : public Object_t
{
public:
	LuaState_t( void );
	LuaState_t( LuaState_t& other );
	LuaState_t( LuaState_t&& other );
	LuaState_t& operator=( LuaState_t& other );
	LuaState_t& operator=( LuaState_t&& other );
	virtual ~LuaState_t( void );

	int executeScriptFile( const char* file );
	int executeScriptCode( const char* codes );
	int executeGlobalFunction(const char* func_name, int retc = 0, int argc = 0 );
	void pushNil( void );
	void pushInt( int num );
	void pushFloat( float num );
	void pushBoolean( bool con );
	void pushString( const char* str );
	void pushString( const char* str, int len );
	//void pushUserData( void* obj, const char* type );
	void clean( void );

private:
	lua_State* _L;
};

typedef std::shared_ptr<LuaState_t> LuaState;
#define newLuaState() (std::move(std::shared_ptr<LuaState_t>(new LuaState_t())))
#define newNode_LuaGC() (new std::shared_ptr<Node_t>(new Node_t()))

#endif //__LUA_STATE_H__