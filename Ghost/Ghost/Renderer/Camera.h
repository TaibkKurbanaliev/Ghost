#pragma once

#include <SDL.h>
#include "../Core/Log.h"

namespace Ghost
{
	class Camera
	{
	public:
		Camera(int posX, int posY, int w, int h);
		void SetPosition(int posX, int posY);
		void SetResolution(int w, int h);
		SDL_Rect* const GetProperties() { return &m_Properties; }
	private:
		SDL_Rect m_Properties;
	};
}


