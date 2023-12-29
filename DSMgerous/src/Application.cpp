#include <DSMgine.h>

class DSMgerous : public DSMgine::Application
{
public:
	DSMgerous()
	{
		DSMGINE_VERBOSE("Hello!");
	}

	virtual ~DSMgerous() override
	{
		DSMGINE_VERBOSE("Goodbye!");
	}
};

DSMgine::Application* DSMgine::CreateApplication()
{
	return new DSMgerous();
}