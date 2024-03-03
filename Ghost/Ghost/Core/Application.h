#pragma once

#include "../MainIncludes.h"
#include "Log.h"
#include "../Renderer/Window.h"
#include "Time.h"
#include "Input.h"
#include "../Renderer/Animation.h"

namespace Ghost
{
	class Applictation
	{
	public:
		Applictation();
		~Applictation();
		/*void Init();
		void DeInit();*/
		void Run();
		void AddGameObject(std::shared_ptr<GameObject>& gameObject);
		void ChangeFPS(int fps);
		Texture* LoadTexture(const char* path, SDL_Point destination);
	private:
		std::unique_ptr<Window> m_Window;
		int m_FPS = 60;
	};
}