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

inline Ray2d::Ray2d( const Vector2& origin, const Vector2& direction ) 
: origin( origin ), direction( direction )
{
	
}

inline Ray2d::Ray2d( const Ray2d& ray ) 
: origin( ray.origin ), direction( ray.direction )
{
	
}

inline Ray2d::Ray2d( void )
{
	
}

inline bool Ray2d::operator==( const Ray2d& ray ) const
{
	return equals( ray );
}

inline bool Ray2d::operator!=( const Ray2d& ray ) const
{
	return equals( ray ) == false;
}

inline Ray2d& Ray2d::operator=( const Ray2d& ray )
{
	origin = ray.origin;
	direction = ray.direction;
	return *this;
}

inline bool Ray2d::equals( const Ray2d& ray ) const
{
	return
		Math::isAlmostEqual( ox, ray.ox, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( oy, ray.oy, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( dx, ray.dx, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( dy, ray.dy, Math::VectorEpsilon );
}

inline bool Ray2d::isValid( void ) const
{
	return !(
		Math::isAlmostZero( dx, Math::VectorEpsilon ) &&
		Math::isAlmostZero( dy, Math::VectorEpsilon ) );
}

inline void Ray2d::set( const Vector2& origin, const Vector2& direction )
{
	this->origin = origin;
	this->direction = direction;
}

inline void Ray2d::set( const Ray2d& ray )
{
	origin = ray.origin;
	direction = ray.direction;
}

inline void Ray2d::setOriginToEnd( const Vector2& origin, const Vector2& end )
{
	Vector2 nd = end - origin;
	nd.normalize();

	this->origin = origin;
	this->direction = nd;
}

inline Ray2d Ray2d::createOriginToEnd( const Vector2& origin, const Vector2& end )
{
	Ray2d dst;
	dst.setOriginToEnd( origin, end );
	return dst;
}