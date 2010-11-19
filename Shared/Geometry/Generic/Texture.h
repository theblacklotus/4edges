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
#ifndef zenic_generic_Texture_h
#define zenic_generic_Texture_h

#include <Shared/Base/Storage/String.h>
#include <Shared/Base/Serialize/Serializable.h>
#include <Shared/Base/Serialize/SerializableFactory.h>

namespace zenic
{

namespace generic
{
	class TextureData;
}

}

namespace zenic
{

namespace generic
{

class Texture : public Serializable
{
	ZENIC_SERIALIZABLE_FACTORY;

public:

	Texture();
	virtual ~Texture();

	virtual void serialize(Serializer& s);

	void setPath(const String& path);
	const String& path() const;

	void setData(TextureData* data);
	TextureData* data() const;

private:

	String m_path;
	TextureData* m_data;
};

#include "Texture.inl"

}

}

#endif
