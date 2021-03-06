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

#ifndef zenic_psp_Vector4_h
#define zenic_psp_Vector4_h

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../../Types.h"

#include <math.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Forwards
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{
	class Serializer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Vector4
{
public:

	Vector4();
	Vector4(f32 x, f32 y, f32 z, f32 w);
	Vector4(const Vector4& v);

	void serialize(Serializer& s, const char* name = 0);

	Vector4& operator = (const Vector4& v);

	Vector4 operator + (const Vector4& v) const;
	Vector4 operator - (const Vector4& v) const;
	Vector4 operator * (float f) const;
	Vector4 operator - (void) const;

	Vector4& operator += (const Vector4& v);
	Vector4& operator -= (const Vector4& v);
	Vector4& operator *= (float f);

	Vector4 normalize() const;
	Vector4 cross(const Vector4& v1, const Vector4& v2) const;
	f32 dot(const Vector4& v) const;

	f32 x,y,z,w;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector4.inl"

}

#endif
