#pragma once

#include <DSMginePCH.h>

namespace DSMgine
{
	class RenderCommandQueue
	{
	public:
		using RenderCommand = std::function<void(void*)>;
		typedef void(*RenderCommandFunction)(void*);

		RenderCommandQueue();
		virtual ~RenderCommandQueue();

		void* Allocate(RenderCommandFunction function, uint32_t size);

		void Execute();
	private:
		uint8_t* m_CommandBuffer;
		uint8_t* m_CommandBufferPtr;
		uint32_t m_CommandCount = 0;
	};
}