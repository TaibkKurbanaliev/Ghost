#pragma once

#include <SDL.h>

namespace Ghost
{
	class Time
	{
	public:
		static void SetDeltaTime();
		static double GetDeltaTime() { return m_DeltaTime; }
	private:
		static double m_DeltaTime;
		static int m_LastTime;
		static int m_NewTime;
	};
}


