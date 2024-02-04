#pragma once

#include "Animation.h"
#include <map>

namespace Ghost
{
	class Animator
	{
	public:
		void SetNextAnimation(std::string title);
		void AddAnimation(std::string title, std::shared_ptr<Animation> animation);
		void FlipAllAnimations(bool isFlip);
		std::shared_ptr<Animation>& GetCurrentAnimation() { return m_CurrentAnimation; }
	private:
		std::map<std::string, std::shared_ptr<Animation>> m_Animations;
		std::shared_ptr<Animation> m_CurrentAnimation;
	};
}


