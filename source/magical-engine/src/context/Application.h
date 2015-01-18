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
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "PlatformMacros.h"
#include "Common.h"

typedef std::function<void( void )> MainDelegate;

class Application
{
public:
	static void Init( void );
	static void Delc( void );
	static void Run( MainDelegate maindel );

public:	
	static void SetInterval( double interval );
	static double GetInterval( void );
	static void SetResizable( bool resizable );
	static bool IsResizable( void );
	static void SetWindowTitle( const char* title );
	static void SwapBuffers( void );
	static void Exit( void );

private:
	static void InitWindow( void );
	static void DelcWindow( void );
	static void InitRenderContext( void );
	static void DelcRenderContext( void );
};

#endif //__APPLICATION_H__