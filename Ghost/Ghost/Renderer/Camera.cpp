#include "Camera.h"

namespace Ghost
{
	Camera::Camera(int posX, int posY, int w, int h )
	{
		m_Properties = { posX, posY, w, h, };
	}

	void Camera::SetPosition(int posX, int posY)
	{
		m_Properties.x = posX;
		m_Properties.y = posY;
	}

	void Camera::SetResolution(int w, int h)
	{
	}
}