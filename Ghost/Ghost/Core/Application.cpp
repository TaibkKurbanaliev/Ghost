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
		std::shared_ptr<Texture> texture3 = std::make_shared<Texture>();
		SDL_Point dest = { 0,0 };

		texture->TryLoadTexture("D:\\Test.png", m_Window->GetRender(), dest);
		texture2->TryLoadTexture("D:\\LightBandit.png", m_Window->GetRender(), {0,0});
		texture3->TryLoadTexture("D:\\platform-long.png", m_Window->GetRender(), { 0,500 });

		Animation* anim = new Animation(*texture2, { 48,48 }, { 0,48 }, 7);
		Animation* idle = new Animation(*texture2, { 48,48 }, { 0,0 }, 3);
		Animator* playerAnimator = new Animator();
		playerAnimator->AddAnimation("run", std::make_shared<Animation>(*anim));

		std::shared_ptr<GameObject> player = std::make_shared<GameObject>();
		player->SetAnimator(playerAnimator);
		std::shared_ptr<GameObject> background = std::make_shared<GameObject>();
		background->SetTexture(*texture);
		std::shared_ptr<GameObject> platform = std::make_shared<GameObject>();
		platform->SetTexture(*texture3);
		BoxCollider* playerCollider = new BoxCollider({ 0,0,48,46 });
		player->SetCollider(*playerCollider);

		player->SetScale({ 5,5 });
		player->AddAnimation("idle", idle);
		platform->SetScale({ 5,2 });

		BoxCollider* platformCollider = new BoxCollider(*platform->GetTexture()->GetDestinationRect());

		platform->SetCollider(*platformCollider);
		
		m_Window->AddGameObject(background);
		m_Window->AddGameObject(platform);
		m_Window->AddGameObject(player);
		
		while (isRunning)
		{
			Input::ReadInputEvents();

			if (Input::GetQuit())
			{
				isRunning = false;
				m_Window->DeInit(0);
			}

			GHOST_CORE_INFO(Input::GetKey(SDL_SCANCODE_SPACE));

			if (Input::GetHorizontal() != 0 || Input::GetVertical() != 0)
			{
				player->Move({ Input::GetHorizontal(), Input::GetVertical() });
				player->GetAnimator()->SetNextAnimation("run");
				
				if (Input::GetHorizontal() > 0)
					player->IsFlip(true);
				else if (Input::GetHorizontal() < 0)
					player->IsFlip(false);
			}
			else 
				player->GetAnimator()->SetNextAnimation("idle");



			Time::SetDeltaTime();

			m_Window->WindowUpdate(NULL);

			SDL_Delay(1000 / 60);
		}
	}
}
