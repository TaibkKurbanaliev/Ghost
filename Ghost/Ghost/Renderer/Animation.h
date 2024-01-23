#pragma once

#include "Texture.h"
#include "../Core/Time.h"

namespace Ghost
{
	class Animation
	{
	public:
		Animation(Texture& spriteSheet, SDL_Point frameSize, SDL_Point startPoint, int numberOfFrames);
		void SetNextRowFrame();
		void SetPreviousRowFrame();
		void UpdateFrame(bool isReverse);
		std::shared_ptr<Texture>* GetTexture() { return &m_SpriteSheet; }
	private:
		std::shared_ptr<Texture> m_SpriteSheet;
		SDL_Point m_FrameSize;
		SDL_Point m_StartPoint;
		SDL_Point m_CurrentFrame;
		int m_NumberOfFrames;
		double m_Delay = 0.2;
		double m_CurentFrameTime;
	};
}
