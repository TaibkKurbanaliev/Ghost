#pragma once

#include <SDL.h>

namespace Ghost
{
	class Collider
	{
	public:
		virtual bool CheckCollision(SDL_Rect thisObject, SDL_Rect checkObject) = 0;
		virtual void Move(SDL_Point distance) = 0;
		virtual void SetPosition(SDL_Point position) = 0;
	};
}