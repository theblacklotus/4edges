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

#ifndef zenic_Assert_h
#define zenic_Assert_h

#if !defined(ZENIC_FINAL)

#if defined(ZENIC_WIN32)
	#include "Win32/Assert.h"
#elif defined(ZENIC_PS2)
	#include "Ps2/Assert.h"
#elif defined(ZENIC_PSP)
	#include "Psp/Assert.h"
#else
	#error "Unsupported platform"
#endif

#define ZENIC_ASSERT(exp) (void)((exp) || ( zenic::Assert::assertStatement(#exp, __FILE__, __LINE__), 0 ))
#define ZENIC_ASSERT_DESC(exp,desc) (void)((exp) || ( zenic::Assert::assertStatement(desc, __FILE__, __LINE__), 0 ))

#else

#define ZENIC_ASSERT(exp) ((void)0)
#define ZENIC_ASSERT_DESC(exp,desc) ((void)0)

#endif

#endif
