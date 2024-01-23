#pragma once

#include "Log.h"

namespace Ghost
{
	class Input
	{
	public:
		static void SetHorizontal(int value);
		static void SetVertical(int value);
		static int GetHorizontal() { return s_Horizontal; }
		static int GetVertical() { return s_Vertical; }
	private:
		static int s_Horizontal;
		static int s_Vertical;
	};
}

#define HORIZONTAL_AXIS_RIGHT 1
#define HORIZONTAL_AXIS_LEFT -1
#define VERTICAL_AXIS_UP -1
#define VERTICAL_AXIS_DOWN 1
