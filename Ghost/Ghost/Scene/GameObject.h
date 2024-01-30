#pragma once

#include "../Renderer/Animation.h"
#include "../Renderer/Texture.h"
#include "../Physics/BoxCollider.h"
#include "../Physics/Physics.h"

namespace Ghost
{
	class GameObject
	{
	public:
		void Move(SDL_Point destination);
		void Rotate(int angle);
		void SetTexture(Texture& texture);
		void SetAnimation(Animation* animation);
		void SetCollider(BoxCollider& collider);
		void SetPosition(SDL_Point position);
		void SetRotation(int angle);
		void SetScale(SDL_FPoint scale);
		void ClampRotation();
		const std::shared_ptr<Texture>& GetTexture() { return m_Texture; }
		const std::shared_ptr<Animation>& GetAnimation() { return m_Animation; }
		const std::shared_ptr<BoxCollider>& GetCollider() { return m_BoxCollider; }
		SDL_Point GetPosition() { return m_Position; }
		SDL_FPoint GetScale() { return m_Scale; }
		int GetRotation() { return m_Rotation; }
	private:
		std::shared_ptr<Texture> m_Texture;
		std::shared_ptr<Animation> m_Animation;
		std::shared_ptr<BoxCollider> m_BoxCollider;
		SDL_Point m_Position = { 0,0 };
		SDL_FPoint m_Scale = { 1,1 };
		int m_Rotation = 0;
	};
}

