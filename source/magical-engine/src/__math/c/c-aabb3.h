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
#ifndef __C_AABB3_H__
#define __C_AABB3_H__

#include "c-utility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cAABB3 {
	float minx;
	float miny;
	float minz;
	float maxx;
	float maxy;
	float maxz;
} cAABB3;
#pragma pack( pop )

#include "c-vector3.h"
#include "c-matrix4.h"
#include "c-ray3.h"
#include "c-plane.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAABB3Equals( const cAABB3* aabb1, const cAABB3* aabb2 );
MAGICALAPI_MATH cBool magicalAABB3IsZero( const cAABB3* aabb );

MAGICALAPI_MATH void magicalAABB3Fill( cAABB3* out, float minx, float miny, float minz, float maxx, float maxy, float maxz );
MAGICALAPI_MATH void magicalAABB3Copy( cAABB3* out, const cAABB3* aabb );
MAGICALAPI_MATH void magicalAABB3SetBox( cAABB3* out, const cVector3* center, float width, float height, float depth );
MAGICALAPI_MATH void magicalAABB3SetPoints( cAABB3* out, const cVector3* min, const cVector3* max );
MAGICALAPI_MATH void magicalAABB3SetZero( cAABB3* out );

MAGICALAPI_MATH void magicalAABB3SetMinPoint( cAABB3* out, const cVector3* min );
MAGICALAPI_MATH void magicalAABB3GetMinPoint( cVector3* out, const cAABB3* aabb );
MAGICALAPI_MATH void magicalAABB3SetMaxPoint( cAABB3* out, const cVector3* max );
MAGICALAPI_MATH void magicalAABB3GetMaxPoint( cVector3* out, const cAABB3* aabb );
MAGICALAPI_MATH void magicalAABB3AddPoint( cAABB3* out, const cAABB3* aabb, const cVector3* v );
MAGICALAPI_MATH void magicalAABB3Merge( cAABB3* out, const cAABB3* aabb1, const cAABB3* aabb2 );
MAGICALAPI_MATH void magicalAABB3CenterPoint( cVector3* out, const cAABB3* aabb );
MAGICALAPI_MATH void magicalAABB3NearestPoint( cVector3* out, const cAABB3* aabb, const cVector3* point );
MAGICALAPI_MATH void magicalAABB3Transform( cAABB3* out, const cAABB3* aabb, const cMatrix4* m );

MAGICALAPI_MATH float magicalAABB3Size( const cAABB3* aabb );
MAGICALAPI_MATH float magicalAABB3DiameterX( const cAABB3* aabb );
MAGICALAPI_MATH float magicalAABB3DiameterY( const cAABB3* aabb );
MAGICALAPI_MATH float magicalAABB3DiameterZ( const cAABB3* aabb );

MAGICALAPI_MATH cBool magicalAABB3Intersects( const cAABB3* aabb1, const cAABB3* aabb2 );
MAGICALAPI_MATH cBool magicalAABB3IntersectsPart( cAABB3* out, const cAABB3* aabb1, const cAABB3* aabb2 );
MAGICALAPI_MATH cBool magicalAABB3IntersectsPlane( const cAABB3* aabb, const cPlane* p );
MAGICALAPI_MATH cBool magicalAABB3IntersectsSphere( const cAABB3* aabb, const cSphere* sp );
MAGICALAPI_MATH cBool magicalAABB3IntersectsRay3( float* outt, const cAABB3* aabb, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalAABB3ContainsPoint( const cAABB3* aabb, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_AABB3_H__