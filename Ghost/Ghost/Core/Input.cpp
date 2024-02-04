#include "Input.h"

namespace Ghost
{
	int Ghost::Input::s_Horizontal;
	int Ghost::Input::s_Vertical;
	bool Ghost::Input::s_Quit = false;
	const Uint8* Ghost::Input::KEYBOARD_STATES = SDL_GetKeyboardState(NULL);
	SDL_Event Ghost::Input::s_Event;

	void Input::ReadInputEvents()
	{
		while (SDL_PollEvent(&s_Event))
		{
			switch (s_Event.type)
			{
			case SDL_QUIT:
				s_Quit = true;
				return;
			}
		}

		if ((KEYBOARD_STATES[SDL_SCANCODE_UP] || KEYBOARD_STATES[SDL_SCANCODE_W]) && !(KEYBOARD_STATES[SDL_SCANCODE_DOWN] || KEYBOARD_STATES[SDL_SCANCODE_S]))
			SetVertical(VERTICAL_AXIS_UP);
		if (!(KEYBOARD_STATES[SDL_SCANCODE_UP] || KEYBOARD_STATES[SDL_SCANCODE_W]) && (KEYBOARD_STATES[SDL_SCANCODE_DOWN] || KEYBOARD_STATES[SDL_SCANCODE_S]))
			SetVertical(VERTICAL_AXIS_DOWN);
		if (!(KEYBOARD_STATES[SDL_SCANCODE_UP] || KEYBOARD_STATES[SDL_SCANCODE_W]) && !(KEYBOARD_STATES[SDL_SCANCODE_DOWN] || KEYBOARD_STATES[SDL_SCANCODE_S]))
			SetVertical(0);
		if ((KEYBOARD_STATES[SDL_SCANCODE_LEFT] || KEYBOARD_STATES[SDL_SCANCODE_A]) && !(KEYBOARD_STATES[SDL_SCANCODE_RIGHT] || KEYBOARD_STATES[SDL_SCANCODE_D]))
			SetHorizontal(HORIZONTAL_AXIS_LEFT);
		if (!(KEYBOARD_STATES[SDL_SCANCODE_LEFT] || KEYBOARD_STATES[SDL_SCANCODE_A]) && (KEYBOARD_STATES[SDL_SCANCODE_RIGHT] || KEYBOARD_STATES[SDL_SCANCODE_D]))
			SetHorizontal(HORIZONTAL_AXIS_RIGHT);
		if (!(KEYBOARD_STATES[SDL_SCANCODE_LEFT] || KEYBOARD_STATES[SDL_SCANCODE_A]) && !(KEYBOARD_STATES[SDL_SCANCODE_RIGHT] || KEYBOARD_STATES[SDL_SCANCODE_D]))
			SetHorizontal(0);
	}

	void Input::SetHorizontal(int direction)
	{
		if (direction > HORIZONTAL_AXIS_RIGHT || direction < HORIZONTAL_AXIS_LEFT)
		{
			GHOST_CORE_WARN("Value must be in range (-1,1) but was: value - {}", direction);
			return;
		}
			
		s_Horizontal = direction;
	}

	void Input::SetVertical(int direction)
	{
		if (direction < VERTICAL_AXIS_UP || direction > VERTICAL_AXIS_DOWN)
		{
			GHOST_CORE_WARN("Value must be in range (-1,1) but was: value - {}", direction);
			return;
		}

		s_Vertical = direction;
	}

	bool Input::GetKey(SDL_Scancode key)
	{
		return KEYBOARD_STATES[key];
	}

	bool Input::GetKeyDown(SDL_Scancode key)
	{
		return true;
	}

	bool Input::GetKeyUp(SDL_Scancode key)
	{
		return false;
	}


}

