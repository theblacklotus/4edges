/*

Copyright (c) 2004-2006 Jesper Svennevid, Daniel Collin

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "Material.h"
#include <Shared/Base/Serialize/Serializer.h>
#include <Shared/Base/Serialize/SerializableVersion.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{
	namespace opengl
	{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZENIC_CREATE_SERIALIZABLE_FACTORY(Material, SERIALIZABLE_ID('O','G','L',' '), SERIALIZABLE_ID('M','A','T','R'))

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Material::Material()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Material::serialize(Serializer& s)
{
//	zenic::Material::serialize(s);
	SerializableVersion version(1, factory());

	s << version;

	s.descriptor(SERIALIZER_NAME("m_shaders")) << m_shaders;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Material::execute()
{
	for (uint i = 0; i < m_shaders.count(); ++i)
		m_shaders[i]->execute();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Material::addInternal(Serializer& s)
{
	for (uint i = 0; i < m_shaders.count(); ++i)
	{
		s.add(m_shaders[i]);
		m_shaders[i]->addInternal(s);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}
