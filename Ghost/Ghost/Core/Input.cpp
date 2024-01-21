#include "Input.h"

namespace Ghost
{
	int Ghost::Input::s_Horizontal;
	int Ghost::Input::s_Vertical;

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
		if (direction > VERTICAL_AXIS_UP || direction < VERTICAL_AXIS_DOWN)
		{
			GHOST_CORE_WARN("Value must be in range (-1,1) but was: value - {}", direction);
			return;
		}

		s_Vertical = direction;
	}
}

