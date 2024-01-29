#pragma once

#include "DSMgine/Renderer/RenderCommandQueue.h"

namespace DSMgine
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		template<typename FunctionTemplate>
		static void Submit(FunctionTemplate&& function)
		{
			auto renderCommand = [](void* ptr)
			{
				auto pFunction = (FunctionTemplate*)ptr;
				(*pFunction)();
				//static_assert(std::is_trivially_destructible_v<FunctionTemplate>, "FunctionTemplate must be trivially destructible");
				pFunction->~FunctionTemplate();
			};

			auto storageBuffer = GetRenderCommandQueue().Allocate(renderCommand, sizeof(function));
			new (storageBuffer) FunctionTemplate(std::forward<FunctionTemplate>(function));
		}

		static void WaitAndRender();

		// Renderer Commands
		static void Clear(float r = 1.0f, float g = 0.0f, float b = 0.54901960784f, float a = 1.0f);

	private:
		static RenderCommandQueue& GetRenderCommandQueue();
	};
}