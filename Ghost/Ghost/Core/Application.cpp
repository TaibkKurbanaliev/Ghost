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

			SDL_Delay(1000 / 60);
		}
	}

	void Applictation::AddGameObject(std::shared_ptr<GameObject>& gameObject)
	{
		m_Window->AddGameObject(gameObject);
	}

	Texture* Applictation::LoadTexture(const char* path, SDL_Point destination)
	{
		Texture* texture = new Texture();

		if (texture->TryLoadTexture(path, m_Window->GetRender(), destination))
			return texture;
		
		return NULL;
	}
}
