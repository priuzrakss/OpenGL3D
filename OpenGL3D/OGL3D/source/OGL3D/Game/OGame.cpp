#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <Windows.H>

OGame::OGame()
{	
	m_GraphicsEngine = std::make_unique<OGraphicsEngine>();
	m_display = std::make_unique<OWindow>();

	m_display->makeCurrentCntext();
}

OGame::~OGame()
{
}

void OGame::onCreate()
{
	m_GraphicsEngine->clear(OVec4(1,0,0,1));


	m_display->present(false);
}

void OGame::onUpdate()
{
}

void OGame::onQuite()
{
}

void OGame::run()
{
	onCreate();
	while (m_isRunning)
	{
		MSG msg = {};
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) { m_isRunning = false; continue; }
			else{TranslateMessage(&msg); DispatchMessage(&msg); }
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		onUpdate();
	}

	onQuite();
}

void OGame::quit()
{
	m_isRunning = false;
}
