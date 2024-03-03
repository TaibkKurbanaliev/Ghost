#pragma once

#include "../../Ghost/Core/Ghost.h"

class Player : public Ghost::GameObject
{
public:
	float RotationSpeed = 0.015;
	float CurrentVerticalSpeed = 5;
	float JumpSpeed = 10;
	float AngleOffset = 40;
	int Gravity = -15;
public:
	void Update() override;
	void Jump();
};

