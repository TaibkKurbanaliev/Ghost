#include "Window.h"
#include "../Core/Log.h"

namespace Ghost
{
	Window::Window()
	{
		Init();
	}

	Window::Window(std::string title, int width, int height)
	{

	}

	Window::~Window()
	{
		DeInit(0);
	}

	void Window::Init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			GHOST_CORE_ERROR("Couldn't init SDL! SDL Error: {}", SDL_GetError());
			DeInit(1);
		}

		int imgInit = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

		if (imgInit == 0)
		{
			GHOST_CORE_ERROR("Couldn't init IMG! SDL Error: {}", SDL_GetError());
			DeInit(1);
		}

		if (imgInit & IMG_INIT_JPG) GHOST_CORE_INFO("Initialized PNG library"); else GHOST_CORE_ERROR("Couldn't init PNG library");
		if (imgInit & IMG_INIT_PNG) GHOST_CORE_INFO("Initialized JPG library"); else GHOST_CORE_ERROR("Couldn't init JPG library");

		m_Window = SDL_CreateWindow(m_Title.c_str(), 1000, 500, m_Width, m_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (m_Window == NULL)
		{
			GHOST_CORE_ERROR("Window could not be created! SDL Error: {}", SDL_GetError());
			DeInit(1);
		}

		GHOST_CORE_INFO("Window has been created");

		m_Render = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

		if (m_Render == NULL)
		{
			GHOST_CORE_ERROR("Renderer could not be created! SDL Error: {}", SDL_GetError());
			DeInit(1);
		}

		GHOST_CORE_INFO("Render has been created");
	}

	void Window::DeInit(int error)
	{
		if (m_Render != NULL) SDL_DestroyRenderer(m_Render);
		if (m_Window != NULL) SDL_DestroyWindow(m_Window);
		GHOST_CORE_ERROR("Destroyed");
		IMG_Quit();
		SDL_Quit();
		exit(error);
	}

	void Window::WindowUpdate(Camera* camera)
	{
		if (m_GameObjects.empty())
			return;

		SDL_RenderClear(m_Render);

		for (auto currentObject = begin(m_GameObjects); currentObject < end(m_GameObjects); ++currentObject)
		{
			if ((*currentObject)->GetAnimation() != NULL)
			{
				auto objectTexture = (*currentObject)->GetAnimation()->GetTexture();
				(*currentObject)->GetAnimation()->UpdateFrame(false);
				SDL_RenderCopyEx(m_Render, (*objectTexture)->GetTexture(), (*objectTexture)->GetScreenRect(),
					(*objectTexture)->GetDestinationRect(), (*currentObject)->GetRotation(), NULL, SDL_FLIP_NONE);
			}
			else if ((*currentObject)->GetTexture() != NULL)
			{
				auto objectTexture = (*currentObject)->GetTexture();
				SDL_RenderCopyEx(m_Render, (*currentObject)->GetTexture()->GetTexture(), (*currentObject)->GetTexture()->GetScreenRect(),
					(*currentObject)->GetTexture()->GetDestinationRect(), (*currentObject)->GetRotation(), NULL, SDL_FLIP_NONE);
			}
				
		}

		SDL_RenderPresent(m_Render);
	}

	void Window::AddGameObject(std::shared_ptr<GameObject>& gameObject)
	{
		if (&gameObject == NULL)
		{
			GHOST_CORE_WARN("GameObject value is NULL");
			return;
		}

		m_GameObjects.emplace_back(gameObject);
	}
}