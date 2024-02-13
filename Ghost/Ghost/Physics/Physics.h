#pragma once

#include "../MainIncludes.h"
#include "BoxCollider.h"

namespace Ghost
{
	class Physics
	{
	public:
		static bool IsTouching(BoxCollider& collider, std::string& collisionObjectName);
		static void AddCollider(std::shared_ptr<BoxCollider>& collider);
	private:
		static std::vector<std::shared_ptr<BoxCollider>> s_Colliders;
	};
}


