#include "Animation.h"


namespace Ghost
{
	Animation::Animation(Texture& spriteSheet, SDL_Point frameSize, SDL_Point startPoint, int numberOfFrames)
	{
		m_SpriteSheet = std::make_shared<Texture>(spriteSheet);
		m_FrameSize = frameSize;
		m_StartPoint = startPoint;
		m_NumberOfFrames = numberOfFrames;
		SDL_Rect startPosition = { 0,0,frameSize.x,frameSize.y };
		m_SpriteSheet->SetDestinationRect(startPosition);
	}

	void Animation::SetNextRowFrame()
	{
		SDL_Point rowEnd = { m_FrameSize.x * m_NumberOfFrames, m_CurrentFrame.y };

		if (m_CurrentFrame.x >= rowEnd.x)
			m_CurrentFrame = m_StartPoint;
		else
			m_CurrentFrame.x += m_FrameSize.x;

		m_SpriteSheet->SetScreenRect({m_CurrentFrame.x, m_CurrentFrame.y, m_FrameSize.x, m_FrameSize.y});
	}

	void Animation::SetPreviousRowFrame()
	{
		SDL_Point rowEnd = { m_FrameSize.x * m_NumberOfFrames, m_CurrentFrame.y };

		if (m_CurrentFrame.x <= m_StartPoint.x)
			m_CurrentFrame = rowEnd;
		else
			m_CurrentFrame.x -= m_FrameSize.x;

		m_SpriteSheet->SetScreenRect({ m_CurrentFrame.x, m_CurrentFrame.y, m_FrameSize.x, m_FrameSize.y });
	}

	void Animation::UpdateFrame(bool isReverse)
	{
		m_CurentFrameTime += Time::GetDeltaTime();

		if (m_CurentFrameTime < m_Delay)
			return;

		m_CurentFrameTime = 0;
		isReverse ? SetPreviousRowFrame() : SetNextRowFrame();
	}
}

