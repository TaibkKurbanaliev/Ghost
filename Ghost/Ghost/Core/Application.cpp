#include "Application.h"

namespace Ghost
{
	Applictation::Applictation()
	{
		Log::Init();
		GHOST_CORE_INFO("Initialize log");

		m_Window = std::make_unique<Window>();
	}

	Applictation::~Applictation()
	{

	}

	void Applictation::Run()
	{
		bool isRunning = true;
		
		while (isRunning)
		{
			Input::ReadInputEvents();

			if (Input::GetQuit())
			{
				isRunning = false;
				m_Window->DeInit(0);
			}

			Time::SetDeltaTime();

			m_Window->WindowUpdate(NULL);

			if (m_FPS != 0)
				SDL_Delay(1000 / m_FPS);
		}
	}

	void Applictation::AddGameObject(std::shared_ptr<GameObject>& gameObject)
	{
		m_Window->AddGameObject(gameObject);
	}

	void Applictation::ChangeFPS(int fps)
	{
		if (fps < 0)
		{
			GHOST_CORE_WARN("FPS value must be greater than 0");
			return;
		}

		m_FPS = fps;
	}

	Texture* Applictation::LoadTexture(const char* path, SDL_Point destination)
	{
		Texture* texture = new Texture();

		if (texture->TryLoadTexture(path, m_Window->GetRender(), destination))
			return texture;
		
		return NULL;
	}
}
