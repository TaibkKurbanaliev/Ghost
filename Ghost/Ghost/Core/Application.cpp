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
		std::shared_ptr<Texture> texture = std::make_shared<Texture>();
		Texture* texture2 = new Texture();
		SDL_Point dest = { 0,0 };

		texture->TryLoadTexture("D:\\Test.png", m_Window->GetRender(), dest);
		texture2->TryLoadTexture("D:\\LightBandit.png", m_Window->GetRender(), {0,0});

		Animation* anim = new Animation(*texture2, { 48,48 }, { 0,48 }, 4);

		std::shared_ptr<GameObject> player = std::make_shared<GameObject>();
		player->SetAnimation(anim);
		std::shared_ptr<GameObject> background = std::make_shared<GameObject>();
		background->SetTexture(*texture);
		
		m_Window->AddGameObject(background);
		m_Window->AddGameObject(player);
		player->SetScale({ 5,5 });

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
				case SDL_KEYDOWN:
					switch (ev.key.keysym.scancode)
					{
					case SDL_SCANCODE_LEFT:
						Input::SetHorizontal(HORIZONTAL_AXIS_LEFT);
						break;
					case SDL_SCANCODE_RIGHT:
						Input::SetHorizontal(HORIZONTAL_AXIS_RIGHT);
						break;
					case SDL_SCANCODE_UP:
						Input::SetVertical(VERTICAL_AXIS_UP);
						break;
					case SDL_SCANCODE_DOWN:
						Input::SetVertical(VERTICAL_AXIS_DOWN);
						break;
					}
					break;
				default:
					Input::SetHorizontal(0);
					Input::SetVertical(0);
					break;
				}
			}

			Time::SetDeltaTime();
			m_Window->WindowUpdate(NULL);

			SDL_Delay(1000 / 60);
		}
	}
}
