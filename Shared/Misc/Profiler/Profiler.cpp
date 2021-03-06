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

#include "Profiler.h"
#include <Shared/Base/Io/Log.h>
#include <Shared/Base/Debug/Assert.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace zenic
{

Profiler::Node* Profiler::m_root = 0;
Profiler::Node* Profiler::m_pos = 0;
Timer Profiler::m_timer;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::init()
{
	m_timer.reset();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Profiler::Profiler(const char* name)
{
	m_timer.update();
	m_time0 = m_timer.tick();

	m_name = name;
	m_curr = branchStepDown(name);
	
	ZENIC_ASSERT(m_curr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Profiler::~Profiler()
{
	ZENIC_ASSERT(m_curr);

	m_timer.update();
	m_time1 = m_timer.tick();

	m_curr->time = m_time1 - m_time0;
	m_curr->accTime += m_curr->time;
	
	m_curr->timeBuffer[++m_curr->timeIndex] = m_curr->time;
	
	if (m_curr->timeIndex > TimeBuffers-1)
		m_curr->timeIndex = 0;
	
	branchStepUp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Profiler::Node* Profiler::branchStepDown(const char* name)
{
	if (m_pos)
	{
		for (Node* current = m_pos->children; current; current = current->next)
		{
			if (current->name == name)
			{
				m_pos = current; 
				return m_pos;
			}
		}
	}
	
	Node* newNode = new Node;

	memset(newNode, 0, sizeof(Node));
	newNode->name = name;
	newNode->parent = m_pos;

	if (!m_root)
	{
		m_root = newNode;
		m_pos  = newNode;
	} 
	else
	{
		if (!m_pos->childTail)
		{
			m_pos->children = newNode;
			m_pos->childTail = newNode;
		}
		else
		{
			m_pos->childTail->next = newNode;
			m_pos->childTail = newNode;
		}
	
		m_pos = newNode;
	}
	
	return newNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::branchStepUp()
{
	ZENIC_ASSERT(m_pos);
	m_pos = m_pos->parent;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::executeTime(const Profiler::Node* node, u64& time)
{
	if (!node)
		return;

	for (Node* current = node->children; current; current = current->next)
	{
		time += current->time;
		//executeTime(current, time);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::stats()
{
	uint l = 0;
	u64 tot = 0;

	executeTime(m_root, tot);
	printStatsRecurse(m_root, 0, l, tot);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::printStatsRecurse(const Profiler::Node* node, int dpt, uint& line, u64 time)
{
	float timeBufferd;
	float newTime;

	if (!node) 
		return;

	timeBufferd = 0;

	for (uint p = 0; p < TimeBuffers; ++p)
		timeBufferd += node->timeBuffer[p];

	timeBufferd /= TimeBuffers;
	timeBufferd /= (100000 / 1000); // convert

	for (int i = 0; i < dpt; ++i)
		zenic::logOut << " ";

	newTime = time ? 100.0f * ((float)node->time) / (float)time : 0.0f;

	//[Name] t=time (Percent%), ac=Accumalated time

	if (dpt >= 0)
	{
		zenic::logOut << "[" << node->name << "] t=" << timeBufferd << "ms (" <<
		newTime << ") ac=" << Timer::toSeconds(node->accTime) << endl << ends << flush;
	}

	for (Node* current = node->children; current; current = current->next)
		printStatsRecurse(current, dpt+1, line, time);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
