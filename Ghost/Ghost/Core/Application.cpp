#include "Application.h"

namespace Ghost
{
	Applictation::Applictation()
	{
	}

	Applictation::~Applictation()
	{

	}
	void Applictation::Run()
	{
		Log::Init();
		GHOST_CORE_INFO("Initialize log");

		m_Window = std::make_unique<Window>();
		SDL_Event ev;
		bool isRunning = true;
		Texture* texture = new Texture();
		SDL_Point dest = { 0,0 };

		texture->TryLoadTexture("D:\\Test.png", m_Window->GetRender(), dest);
		m_Window->AddTexture(*texture);

		while (isRunning)
		{
			while (SDL_PollEvent(&ev))
			{
				switch (ev.type)
				{
				case SDL_QUIT:
					isRunning = false;
					m_Window->DeInit(0);
					break;
				default:
					break;
				}
			}

			m_Window->WindowUpdate(NULL);
		}
	}
}
