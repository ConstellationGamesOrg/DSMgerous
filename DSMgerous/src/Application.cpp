#include <DSMgine.h>

class GameLayer : public DSMgine::Layer
{
public:
	GameLayer()
		: Layer("GameLayer")
	{
	}

	virtual ~GameLayer()
	{
	}

	virtual void OnAttach() override
	{
		DSMGINE_VERBOSE("GameLayer::OnAttach");
	}

	virtual void OnDetach() override
	{
		DSMGINE_VERBOSE("GameLayer::OnDetach");
	}

	virtual void OnUpdate(float ts) override
	{
		//DSMGINE_VERBOSE("GameLayer::OnUpdate");
	}

	virtual void OnEvent(DSMgine::Event& event) override
	{
		DSMGINE_VERBOSE(event.ToString());
	}
};

class DSMgerous : public DSMgine::Application
{
public:
	DSMgerous()
	{
	}

	virtual ~DSMgerous()
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new GameLayer());
	}

	virtual void OnShutdown() override
	{
	}
};

DSMgine::Application* DSMgine::CreateApplication()
{
	return new DSMgerous();
}