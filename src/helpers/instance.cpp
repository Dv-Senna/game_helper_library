#include "helpers/instance.hpp"

#include <stdexcept>

#include <SDL2/SDL.h>



namespace gm {
	Instance::Instance(const std::function<void()> &construct, const std::function<void()> destruct) :
		m_destruct {destruct}
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
			throw std::runtime_error("Can't init SDL2");

		if (construct != nullptr)
			construct();
	}


	Instance::~Instance() {
		if (m_destruct != nullptr)
			m_destruct();

		SDL_Quit();
	}


} // namespace gm
