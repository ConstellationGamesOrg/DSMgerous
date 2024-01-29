#pragma once

#include "DSMgine/Renderer/RendererAPI.h"

namespace DSMgine
{
	class OpenGLRenderer : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void Shutdown() override;

		virtual void Clear(float r, float g, float b, float a) override;
	};
}