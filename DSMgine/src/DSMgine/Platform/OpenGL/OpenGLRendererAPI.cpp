#include <DSMginePCH.h>

#include "OpenGLRendererAPI.h"
#include "DSMgine/Renderer/Renderer.h"

#include <glad/glad.h>

namespace DSMgine
{
	void OpenGLRenderer::Init()
	{
	}

	void OpenGLRenderer::Shutdown()
	{
	}

	void OpenGLRenderer::Clear(float r, float g, float b, float a)
	{
		Renderer::Submit([r, g, b, a]()
		{
			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		});
	}
}