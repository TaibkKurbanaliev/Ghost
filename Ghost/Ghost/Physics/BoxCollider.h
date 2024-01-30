#pragma once
#include "Collider.h"

namespace Ghost
{
	class BoxCollider :
		public Collider
	{
	public:
		BoxCollider(SDL_Rect properties);
		bool CheckCollision(SDL_Rect a, SDL_Rect b) override;
		void Move(SDL_Point distance) override;
		void SetPosition(SDL_Point position) override;
		SDL_Rect GetProperties() { return m_Properties; }
	private:
		SDL_Rect m_Properties;
	};
}


