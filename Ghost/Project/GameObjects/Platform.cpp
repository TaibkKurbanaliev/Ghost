#include "Platform.h"

SDL_Point Platform::m_StartPosition;
SDL_Point Platform::m_EndPosition;

void Platform::Update()
{
	SDL_FPoint direction = { -6, 0 };

	if (this->GetPosition().x <= m_EndPosition.x)
		this->SetPosition({ (float)m_StartPosition.x + direction.x - 2, (float)m_StartPosition.y });

	Move(direction);
}