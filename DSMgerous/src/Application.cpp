#include <DSMgine.h>

#include <iostream>

class Sandbox : public DSMgine::Application
{
public:
	Sandbox()
	{
		DSMGINE_VERBOSE("Hello!");
	}

	virtual ~Sandbox() override
	{
		DSMGINE_VERBOSE("Goodbye!");
	}
};

DSMgine::Application* DSMgine::CreateApplication()
{
	return new Sandbox();
}