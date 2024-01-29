#include <DSMginePCH.h>

#include "OpenGLRendererAPI.h"
#include "DSMgine/Renderer/Renderer.h"

#include <glad/glad.h>

namespace DSMgine
{
	void OpenGLRenderer::Init()
	{
		Renderer::Submit([]()
		{
			glEnable(GL_DEPTH_TEST);
			//glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
			glFrontFace(GL_CCW);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glEnable(GL_MULTISAMPLE);
			glEnable(GL_STENCIL_TEST);

			GLenum error = glGetError();
			while (error != GL_NO_ERROR)
			{
				DSMGINE_CORE_ERROR("OpenGL Error {0}", error);
				error = glGetError();
	}
		});
	}

	void OpenGLRenderer::Shutdown()
	{
		Renderer::Submit([]()
		{
		});
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