#pragma once

#include "../Renderer/Animator.h"
#include "../Renderer/Texture.h"
#include "../Physics/BoxCollider.h"
#include "../Physics/Physics.h"

namespace Ghost
{
	class GameObject
	{
	public:
		void virtual Update();
		void Move(SDL_Point destination);
		void Rotate(int angle);
		void SetTexture(Texture& texture);
		void SetAnimator(Animator* animator);
		void AddAnimation(std::string title, Animation* animation);
		void IsFlip(bool isFlip);
		void SetCollider(BoxCollider& collider);
		void SetPosition(SDL_Point position);
		void SetRotation(int angle);
		void SetScale(SDL_FPoint scale);
		void ClampRotation();
		const std::shared_ptr<Texture>& GetTexture() { return m_Texture; }
		const std::shared_ptr<Animator>& GetAnimator() { return m_Animator; }
		const std::shared_ptr<BoxCollider>& GetCollider() { return m_BoxCollider; }
		SDL_Point GetPosition() { return m_Position; }
		SDL_FPoint GetScale() { return m_Scale; }
		int GetRotation() { return m_Rotation; }
	private:
		std::shared_ptr<Texture> m_Texture;
		std::shared_ptr<Animator> m_Animator;
		std::shared_ptr<BoxCollider> m_BoxCollider;
		SDL_Point m_Position = { 0,0 };
		SDL_FPoint m_Scale = { 1,1 };
		int m_Rotation = 0;
	};
}


