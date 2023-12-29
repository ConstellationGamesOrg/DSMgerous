extern DSMgine::Application* DSMgine::CreateApplication();

int main(int argc, char** argv)
{
	DSMgine::InitializeCore();
	DSMgine::Application* app = DSMgine::CreateApplication();
	app->Run();
	delete app;
	DSMgine::ShutdownCore();
}