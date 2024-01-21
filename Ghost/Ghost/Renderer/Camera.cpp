#include "Camera.h"

namespace Ghost
{
	Camera::Camera(int w, int h, int posX, int posY)
	{
		m_Properties = { w, h, posX, posY };
	}

	void Camera::SetPosition(int posX, int posY)
	{

	}

	void Camera::SetResolution(int w, int h)
	{
	}
}