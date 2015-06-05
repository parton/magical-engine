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
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "magical-macros.h"
#include "magical-math.h"
#include "Common.h"
#include "RenderCommon.h"
#include "Reference.h"

NAMESPACE_MAGICAL

class RenderCommand : public Reference
{
public:
	RenderCommand( void );
	virtual ~RenderCommand( void );

};

class TriangleCommand : public RenderCommand
{
public:
	TriangleCommand( void );
	virtual ~TriangleCommand( void );
	static Ptr<TriangleCommand> create( void );

public:
	void initVertexes( const Vertex3f_Color4b_TexCoord2f* vertexes, size_t size );
	void initIndices( const uint16_t* indices, size_t size );

protected:
	Vertex3f_Color4b_TexCoord2f* m_vertexes;
	uint16_t* m_indices;
	size_t m_vertexes_size;
	size_t m_indices_size;
};

NAMESPACE_END

#endif //__RENDERER_H__
