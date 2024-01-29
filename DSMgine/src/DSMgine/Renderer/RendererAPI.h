#pragma once

namespace DSMgine
{
	enum class RendererAPIType
	{
		None,
		OpenGL
	};

	class RendererAPI
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void Clear(float r, float g, float b, float a) = 0;

		static RendererAPIType Current() { return s_CurrentRendererAPI; }
		static void SetAPI(RendererAPIType api);

	private:
		inline static RendererAPIType s_CurrentRendererAPI = RendererAPIType::OpenGL;
	};
}