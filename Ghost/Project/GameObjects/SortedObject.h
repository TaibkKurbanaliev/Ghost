#pragma once
#include "../../Ghost/Core/Ghost.h"

class SortedObject : public Ghost::GameObject
{
public:
	int m_Value = 0;
public:
	SortedObject(int value) : m_Value(value)
	{
	}
};

