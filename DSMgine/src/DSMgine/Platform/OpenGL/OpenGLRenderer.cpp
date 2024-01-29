#include <DSMginePCH.h>

#include "OpenGLRenderer.h"
#include "DSMgine/Renderer/Renderer.h"

#include <glad/glad.h>

namespace DSMgine
{
#ifndef DSMGINE_FORCE_OPENGL_3_2
	static void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			DSMGINE_CORE_ERROR("[OpenGL Debug HIGH] {0}", message);
			DSMGINE_CORE_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			DSMGINE_CORE_WARNING("[OpenGL Debug MEDIUM] {0}", message);
			break;
		case GL_DEBUG_SEVERITY_LOW:
			DSMGINE_CORE_INFO("[OpenGL Debug LOW] {0}", message);
			break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			DSMGINE_CORE_VERBOSE("[OpenGL Debug NOTIFICATION] {0}", message);
			break;
		}
	}
#else
#endif

	void OpenGLRenderer::Init()
	{
		Renderer::Submit([]()
		{
#ifndef DSMGINE_FORCE_OPENGL_3_2
			glDebugMessageCallback(OpenGLLogMessage, nullptr);
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
#else
#endif

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