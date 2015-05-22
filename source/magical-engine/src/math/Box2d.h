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
#ifndef __BOX2D_H__
#define __BOX2D_H__

struct Box2d
{
	Vector2 min;
	Vector2 max;

public:
	static const Box2d Invalid;

public:
	inline Box2d( const Vector2& min, const Vector2& max );
	inline Box2d( const Box2d& box );
	inline Box2d( void );

public:
	inline bool operator==( const Box2d& box ) const;
	inline bool operator!=( const Box2d& box ) const;
	inline Box2d& operator=( const Box2d& box );

public:
	bool equals( const Box2d& box ) const;
	bool isValid( void ) const;
	inline void set( const Vector2& min, const Vector2& max );
	inline void set( const Box2d& box );
	void setOriginBox( const Vector2& origin, float w, float h );
	void setCenterBox( const Vector2& center, float w, float h );
	static inline Box2d createOriginBox( const Vector2& origin, float w, float h );
	static inline Box2d createCenterBox( const Vector2& center, float w, float h );

public:
	static void scale( Box2d& out, const Box2d& box, float s );
	static void merge( Box2d& out, const Box2d& box1, const Box2d& box2 );
	static void center( Vector2& out, const Box2d& box );
	static void closest( Vector2& out, const Box2d& box, const Vector2& v );
	static inline Box2d scale( const Box2d& box, float s );
	static inline Box2d merge( const Box2d& box1, const Box2d& box2 );
	inline void scale( float s );
	inline void merge( const Box2d& box );
	inline Vector2 center( void ) const;
	inline Vector2 closest( const Vector2& v ) const;

public:
	inline void shrink( float w, float h );
	inline void shrink( float a );
	inline void expand( float w, float h );
	inline void expand( float a );
	inline void expandBy( const Vector2& v );
	inline float size( void ) const;
	inline float width( void ) const;
	inline float height( void ) const;

public:
	bool intersects( const Box2d& box ) const;
	bool containsPoint( const Vector2& point ) const;
};

#endif //__BOX2D_H__
