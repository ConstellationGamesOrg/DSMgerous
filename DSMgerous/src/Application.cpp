#include <DSMgine.h>

#include <iostream>

class Sandbox : public DSMgine::Application
{
public:
	Sandbox()
	{
		std::cout << "Hello!\n";
	}

	virtual ~Sandbox() override
	{
		std::cout << "Goodbye!\n";
	}
};

DSMgine::Application* DSMgine::CreateApplication()
{
	return new Sandbox();
}