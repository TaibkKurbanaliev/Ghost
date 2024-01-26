#include "GameObject.h"

namespace Ghost
{
	void GameObject::Move(SDL_Point destination)
	{
		m_Position.x += destination.x;
		m_Position.y += destination.y;

		if (m_Texture != NULL && m_Animation == NULL)
		{
			SDL_Rect oldTextureDest = *m_Texture->GetDestinationRect();
			SDL_Rect newTextureDest = { m_Position.x, m_Position.y, oldTextureDest.w, oldTextureDest.h };
			m_Texture->SetDestinationRect(newTextureDest);
		}
		else
		{
			SDL_Rect oldTextureDest = *(*m_Animation->GetTexture())->GetDestinationRect();
			SDL_Rect newTextureDest = { m_Position.x, m_Position.y, oldTextureDest.w, oldTextureDest.h };
			(*m_Animation->GetTexture())->SetDestinationRect(newTextureDest);
		}
	}

	void GameObject::Rotate(int angle)
	{
		m_Rotation += angle;

		ClampRotation();
	}
	void GameObject::SetTexture(Texture& texture)
	{
		if (&texture == NULL)
		{
			GHOST_CORE_WARN("Texture is NULL");
			return;
		}


		m_Texture = std::make_shared<Texture>(texture);
	}

	void GameObject::SetAnimation(Animation* animation)
	{
		if (&animation == NULL)
		{
			GHOST_CORE_WARN("Animation is NULL");
			return;
		}

		m_Animation = std::make_shared<Animation>(*animation);
	}

	void GameObject::SetPosition(SDL_Point position)
	{
		m_Position = position;
	}

	void GameObject::SetRotation(int angle)
	{
		m_Rotation = angle;
		ClampRotation();
	}

	void GameObject::SetScale(SDL_FPoint scale)
	{
		if (scale.x < 0 || scale.y < 0)
		{
			GHOST_CORE_WARN("The scale value cannot be less than zero: Scale: x = {}, y = {}", scale.x, scale.y);
			return;
		}

		if (m_Animation != NULL)
		{
			auto texture = m_Animation->GetTexture();
			SDL_Rect oldSize = *(*texture)->GetDestinationRect();
			SDL_Rect newSize = { oldSize.x, oldSize.y, oldSize.w * (scale.x / m_Scale.x), oldSize.h * (scale.y / m_Scale.y) };
			(*texture)->SetDestinationRect(newSize);
		}

		m_Scale = scale;
	}

	void GameObject::ClampRotation()
	{
		if (m_Rotation >= 360 || m_Rotation <= -360)
			m_Rotation %= 360;

		if (m_Rotation < 0)
			m_Rotation = 360 - SDL_abs(m_Rotation);
	}
}