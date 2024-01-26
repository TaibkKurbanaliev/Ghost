#include "Texture.h"

namespace Ghost
{
	Texture::Texture()
	{
	}

	Texture::~Texture()
	{
		SDL_DestroyTexture(m_Texture);
		delete m_SreenRect;
		delete m_DestinationRect;
	}

	bool Texture::TryLoadTexture(const char* path, SDL_Renderer* render, SDL_Point destination)
	{
		SDL_Surface* surface = IMG_Load(path);

		if (surface == NULL)
		{
			GHOST_CORE_ERROR("Couldn't load image! SDL Error: {}", SDL_GetError());
			return false;
		}

		m_DestinationRect = new SDL_Rect{destination.x, destination.y, surface->w, surface->h };
		m_Texture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
	}

	void Texture::SetScreenRect(SDL_Rect screenRect)
	{
		if (m_SreenRect == NULL)
			m_SreenRect = new SDL_Rect({ 0,0,0,0 });

		*m_SreenRect = screenRect;
	}

	void Texture::SetDestinationRect(SDL_Rect destRect)
	{
		*m_DestinationRect = destRect;
	}
}