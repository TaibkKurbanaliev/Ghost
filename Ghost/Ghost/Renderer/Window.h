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
		void AddTexture(std::shared_ptr<Texture>& texture);
		SDL_Renderer* const GetRender() { return m_Render; }
		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
	private:
		SDL_Window* m_Window = NULL;
		SDL_Renderer* m_Render = NULL;
		std::string m_Title = "GhostEngine";
		int m_Width = 1920;
		int m_Height = 1080;
		std::vector<std::shared_ptr<Texture>> m_Textures;
	};
}


