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

#ifndef zenic_ps2_CubeRenderer_h
#define zenic_ps2_CubeRenderer_h

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Shared/Base/Types.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{
	class Matrix4;
	class Vector3;
	class Model;

	namespace ps2
	{
		class Dma;
		class Renderer;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{
	namespace ps2
	{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CubeRenderer
{
public:

	CubeRenderer(Renderer& renderer, Dma& dmaChain);

	void begin(const Vector3& directionalLightPosition);
	void render(const Matrix4& matrix);
	void end();

	void beginShadow();
	void renderShadow(const Matrix4& matrix);
	void endShadow();

private:

	void addQuad(const Vector3& p0, const Vector3& p1, const Vector3& p2, const Vector3& p3);

	Renderer& m_renderer;
	Dma& m_dmaChain;
	Model* m_shadowModel;
	s32 m_vu1Address;
	u32 m_destBuffer1;
	u32 m_destBuffer2;
	bool m_started;
	bool m_hasSetMaterial;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
