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
		bool isStart = true;
	public:
		GameObject() { m_ObjectType = typeid(GameObject).name(); }
		GameObject(std::string ObjectType) { m_ObjectType = ObjectType; }
		virtual ~GameObject() {};
		void virtual Update();
		void virtual Start();
		void Move(SDL_FPoint destination);
		void Rotate(int angle);
		void SetTexture(Texture& texture);
		void SetAnimator(Animator* animator);
		void AddAnimation(std::string title, Animation* animation);
		void IsFlip(bool isFlip);
		void SetCollider(BoxCollider& collider);
		void SetPosition(SDL_FPoint position);
		void SetRotation(float angle);
		void SetScale(SDL_FPoint scale);
		void ClampRotation();
		const std::shared_ptr<Texture>& GetTexture() { return m_Texture; }
		const std::shared_ptr<Animator>& GetAnimator() { return m_Animator; }
		const std::shared_ptr<BoxCollider>& GetCollider() { return m_BoxCollider; }
		SDL_FPoint GetPosition() { return m_Position; }
		SDL_FPoint GetScale() { return m_Scale; }
		float GetRotation() { return m_Rotation; }
	private:
		std::shared_ptr<Texture> m_Texture;
		std::shared_ptr<Animator> m_Animator;
		std::shared_ptr<BoxCollider> m_BoxCollider;
		SDL_FPoint m_Position = { 0,0 };
		SDL_FPoint m_Scale = { 1,1 };
		float m_Rotation = 0;
		std::string m_ObjectType;
	};
}


