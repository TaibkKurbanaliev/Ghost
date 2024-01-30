#include "BoxCollider.h"

namespace Ghost
{
    BoxCollider::BoxCollider(SDL_Rect properties)
    {
        m_Properties = properties;
    }

    bool BoxCollider::CheckCollision(SDL_Rect a, SDL_Rect b)
	{
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;

        leftB = b.x;
        rightB = b.x + b.w;
        topB = b.y;
        bottomB = b.y + b.h;

        if (bottomA <= topB)
        {
            return false;
        }

        if (topA >= bottomB)
        {
            return false;
        }

        if (rightA <= leftB)
        {
            return false;
        }

        if (leftA >= rightB)
        {
            return false;
        }

        return true;
	}

    void BoxCollider::Move(SDL_Point distance)
    {
        m_Properties = { m_Properties.x + distance.x, m_Properties.y + distance.y, m_Properties.w, m_Properties.h };
    }

    void BoxCollider::SetPosition(SDL_Point position)
    {
        m_Properties = { position.x, position.y, m_Properties.w, m_Properties.h };
    }
}