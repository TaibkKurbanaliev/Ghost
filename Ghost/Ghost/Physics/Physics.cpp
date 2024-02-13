#include "Physics.h"

namespace Ghost
{
	std::vector<std::shared_ptr<BoxCollider>> Ghost::Physics::s_Colliders;

	bool Physics::IsTouching(BoxCollider& collider, std::string& collisionObjectName)
	{
		for (int i = 0; i < s_Colliders.size(); i++)
			if (&collider != s_Colliders[i].get() && collider.CheckCollision(collider.GetProperties(), s_Colliders[i]->GetProperties()))
			{
				if (&collisionObjectName != NULL)
					collisionObjectName = s_Colliders[i]->GetObjectName();
				return true;
			}

		return false;
	}
	void Physics::AddCollider(std::shared_ptr<BoxCollider>& collider)
	{
		s_Colliders.emplace_back(collider);
	}
}