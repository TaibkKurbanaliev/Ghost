#pragma once

#include "Log.h"

namespace Ghost
{
	class Input
	{
	public:
		static void ReadInputEvents();
		static void SetHorizontal(int value);
		static void SetVertical(int value);
		static int GetHorizontal() { return s_Horizontal; }
		static int GetVertical() { return s_Vertical; }
		static bool GetKey(SDL_Scancode key);
		static bool GetKeyDown(SDL_Scancode key);
		static bool GetKeyUp(SDL_Scancode key);
		static bool GetQuit() { return s_Quit; }
	private:
		static const Uint8* KEYBOARD_STATES;
		static bool* PREVIOUS_DOWN_STATES;
		static bool* PREVIOUS_UP_STATES;
		static SDL_Event s_Event; 
		static bool s_Quit;
		static int s_Horizontal;
		static int s_Vertical;
	};
}

#define HORIZONTAL_AXIS_RIGHT 1
#define HORIZONTAL_AXIS_LEFT -1
#define VERTICAL_AXIS_UP -1
#define VERTICAL_AXIS_DOWN 1
