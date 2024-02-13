#pragma once
#include "Collider.h"
#include <string>

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
		void Resize(SDL_Point newSize);
		void SetObjectName(std::string& name);
		std::string& GetObjectName() { return m_ObjectName; }
		SDL_Rect GetProperties() { return m_Properties; }
	private:
		SDL_Rect m_Properties;
		std::string m_ObjectName;
	};
}


