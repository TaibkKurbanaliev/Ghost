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
		if (m_Textures.empty())
			return;

		SDL_RenderClear(m_Render);

		for (auto currentTexture = begin(m_Textures); currentTexture < end(m_Textures); ++currentTexture)
		{
			if (camera != NULL)
				SDL_RenderCopyEx(m_Render, (*currentTexture)->GetTexture(), camera->GetProperties(), (*currentTexture)->GetDestinationRect(), 0, NULL, SDL_FLIP_NONE);
			else 
				SDL_RenderCopyEx(m_Render, (*currentTexture)->GetTexture(), (*currentTexture)->GetScreenRect(), (*currentTexture)->GetDestinationRect(), 0, NULL, SDL_FLIP_NONE);
		}

		SDL_RenderPresent(m_Render);
	}

	void Window::AddTexture(std::shared_ptr<Texture>& texture)
	{
		if (&texture == NULL)
		{
			GHOST_CORE_WARN("Texture value is NULL");
			return;
		}

		m_Textures.emplace_back(texture);
	}
}