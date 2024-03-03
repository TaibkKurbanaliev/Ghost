#include "Player.h"

void Player::Update()
{
	SDL_FPoint CurrentPos = GetPosition();
	Jump();
	Move({CurrentPos.x, CurrentVerticalSpeed});
}

void Player::Jump()
{
	if (Ghost::Input::GetKeyDown(SDL_SCANCODE_SPACE))
	{
		CurrentVerticalSpeed = -JumpSpeed;
		SetRotation(-AngleOffset);
	}
	else if (CurrentVerticalSpeed < -Gravity)
	{
		CurrentVerticalSpeed -= Ghost::Time::GetDeltaTime() * Gravity;

		GHOST_CORE_INFO(GetRotation());

		if (GetRotation() <= AngleOffset)
			SetRotation(std::lerp(GetRotation(), AngleOffset, RotationSpeed));
	}
}
