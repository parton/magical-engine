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
#include "SceneObject.h"

NS_MAGICAL_BEGIN

define_class_hash_code( SceneObject );

SceneObject::SceneObject( void )
{
	assign_class_hash_code();
	m_element_id = SceneElement::Object;
}

SceneObject::~SceneObject( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onDestroy();
		itr.second->release();
	}
}

Ptr<SceneObject> SceneObject::create( void )
{
	SceneObject* ret = new SceneObject();
	magicalAssert( ret, "new SceneObject() failed" );
	return Ptr<SceneObject>( Initializer<SceneObject>( ret ) );
}

Ptr<SceneObject> SceneObject::create( const char* name )
{
	SceneObject* ret = new SceneObject();
	magicalAssert( ret, "new SceneObject() failed" );
	ret->setName( name );
	return Ptr<SceneObject>( Initializer<SceneObject>( ret ) );
}

void SceneObject::visit( void )
{
	SceneNode::visit();
}

void SceneObject::start( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStart();
	}
	SceneNode::start();
}

void SceneObject::stop( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStop();
	}
	SceneNode::stop();
}

void SceneObject::update( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onUpdate();
	}
}


NS_MAGICAL_END