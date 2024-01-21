#include "Texture.h"

namespace Ghost
{
	Texture::Texture()
	{
		m_DestinationRect = { 0,0,0,0 };
		m_SreenRect = { 0,0,0,0 };
	}

	Texture::~Texture()
	{
		SDL_DestroyTexture(m_Texture);
	}

	bool Texture::TryLoadTexture(const char* path, SDL_Renderer* render, SDL_Point destination)
	{
		SDL_Surface* surface = IMG_Load(path);

		if (surface == NULL)
		{
			GHOST_CORE_ERROR("Couldn't load image! SDL Error: {}", SDL_GetError());
			return false;
		}

		m_DestinationRect = {destination.x, destination.y, surface->w, surface->h };
		m_Texture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
	}
}