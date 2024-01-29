#include <DSMginePCH.h>

#include "DSMgine/Renderer/RenderCommandQueue.h"

namespace DSMgine
{
	RenderCommandQueue::RenderCommandQueue()
	{
		// Create a 10mb buffer
		m_CommandBuffer = new uint8_t[10 * 1024 * 1024];
		m_CommandBufferPtr = m_CommandBuffer;
		// Fill the buffer with 0s
		memset(m_CommandBuffer, 0, 10 * 1024 * 1024);
	}

	RenderCommandQueue::~RenderCommandQueue()
	{
		delete[] m_CommandBuffer;
	}

	void* RenderCommandQueue::Allocate(RenderCommandFunction function, uint32_t size)
	{
		*(RenderCommandFunction*)m_CommandBufferPtr = function;
		m_CommandBufferPtr += sizeof(RenderCommandFunction);

		*(uint32_t*)m_CommandBufferPtr = size;
		m_CommandBufferPtr += sizeof(uint32_t);

		void* memory = m_CommandBufferPtr;
		m_CommandBufferPtr += size;

		m_CommandCount++;
		return memory;
	}

	void RenderCommandQueue::Execute()
	{
		DSMGINE_CORE_VERBOSE("RenderCommandQueue::Execute -- {0} commands, {1} bytes", m_CommandCount, (m_CommandBufferPtr - m_CommandBuffer));

		byte* buffer = m_CommandBuffer;

		for (uint32_t i = 0; i < m_CommandCount; i++)
		{
			RenderCommandFunction function = *(RenderCommandFunction*)buffer;
			buffer += sizeof(RenderCommandFunction);

			uint32_t size = *(uint32_t*)buffer;
			buffer += sizeof(uint32_t);
			function(buffer);
			buffer += size;
		}

		m_CommandBufferPtr = m_CommandBuffer;
		m_CommandCount = 0;
	}
}