#pragma once

#include "../../Ghost/Core/Ghost.h"

class Platform :
	public Ghost::GameObject
{
public:
	std::string name;
	Platform(std::string Name) : Ghost::GameObject(typeid(Platform).name()) { name = Name; }
	void Update() override;
	static SDL_Point m_StartPosition;
	static SDL_Point m_EndPosition;
};