#include "Animator.h"

namespace Ghost
{
	void Animator::SetNextAnimation(std::string title)
	{
		auto animation = std::find_if(m_Animations.begin(), m_Animations.end(), [&](std::pair<std::string, std::shared_ptr<Animation>> value) {return value.first == title; });

		if (animation == m_Animations.end())
		{
			GHOST_CORE_WARN("Animation {} doesn't exist", title);
			return;
		}

		if (m_CurrentAnimation == animation->second)
			return;

		if (m_CurrentAnimation.get() != NULL)
			m_CurrentAnimation->SetStartFrame();

		m_CurrentAnimation = animation->second;
	}

	void Animator::AddAnimation(std::string title, std::shared_ptr<Animation> animation)
	{
		if (animation.get() == NULL)
		{
			GHOST_CORE_WARN("Animation is NULL");
			return;
		}

		m_Animations.emplace(title, animation);
		m_CurrentAnimation = animation;
	}

	void Animator::FlipAllAnimations(bool isFlip)
	{
		for (auto animation : m_Animations)
			animation.second->GetTexture()->SetFlip(isFlip);
	}
}