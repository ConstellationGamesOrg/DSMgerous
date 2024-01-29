#include <DSMginePCH.h>

#include "DSMgine/Renderer/Renderer.h"
#include "DSMgine/Renderer/RendererAPI.h"

#include "DSMgine/Platform/OpenGL/OpenGLRenderer.h"

namespace DSMgine
{
	static RendererAPI* s_RendererAPI = nullptr;
	static RenderCommandQueue* s_CommandQueue = nullptr;

	static RendererAPI* InitRendererAPI()
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: return new OpenGLRenderer();
		}
		DSMGINE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	void DSMgine::RendererAPI::SetAPI(RendererAPIType api)
	{
		// NOTE: If called, it must be before InitRendererAPI()
		DSMGINE_CORE_VERIFY(api == RendererAPIType::OpenGL, "OpenGL is the only supported renderer API")
		s_CurrentRendererAPI = api;
	}

	void Renderer::Init()
	{
		s_RendererAPI = InitRendererAPI();
		s_CommandQueue = new RenderCommandQueue();

		s_RendererAPI->Init();
	}

	void Renderer::Shutdown()
	{
		s_RendererAPI->Shutdown();
		delete s_CommandQueue;
		delete s_RendererAPI;
	}

	void Renderer::WaitAndRender()
	{
		s_CommandQueue->Execute();
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		s_RendererAPI->Clear(r, g, b, a);
	}

	RenderCommandQueue& Renderer::GetRenderCommandQueue()
	{
		return *s_CommandQueue;
	}
}