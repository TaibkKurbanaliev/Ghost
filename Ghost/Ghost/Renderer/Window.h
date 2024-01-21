#pragma once

#include "../MainIncludes.h"
#include "../Core/Log.h"
#include "Texture.h"
#include "Camera.h"

namespace Ghost
{
	class Window
	{
	public:
		Window();
		Window(std::string title, int width, int height);
		~Window();
		void Init();
		void DeInit(int error);
		void WindowUpdate(Camera* camera);
		void AddTexture(Texture& texture);
		SDL_Renderer* const GetRender() { return m_Render; }
	private:
		SDL_Window* m_Window = NULL;
		SDL_Renderer* m_Render = NULL;
		std::string m_Title = "GhostEngine";
		int m_Width = 1280;
		int m_Height = 720;
		std::vector<Texture> m_Textures;
	};
}


