#pragma once

#include "../MainIncludes.h"
#include "Log.h"
#include "../Renderer/Window.h"
#include "Time.h"
#include "Input.h"
#include "../Renderer/Animation.h"

namespace Ghost
{
	class Applictation
	{
	public:
		Applictation();
		~Applictation();
		/*void Init();
		void DeInit();*/
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
	};
}