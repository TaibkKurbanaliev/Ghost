#pragma once

#include "../MainIncludes.h"
#include "../Core/Log.h";

namespace Ghost
{
	class Texture
	{
	public:
		Texture();
		~Texture();
		bool TryLoadTexture(const char* path, SDL_Renderer* render, SDL_Point destination);
		void SetScreenRect(SDL_Rect screenRect);
		SDL_Texture* GetTexture() { return m_Texture; }
		SDL_Rect* GetDestinationRect() { return m_DestinationRect; }
		SDL_Rect* GetScreenRect() { return m_SreenRect; }
	private:
		SDL_Texture* m_Texture = NULL;
		SDL_Rect* m_SreenRect = NULL;
		SDL_Rect* m_DestinationRect = NULL;
	};
}


