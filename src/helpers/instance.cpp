#include "helpers/instance.hpp"

#include <stdexcept>

#include <SDL2/SDL.h>

#include "helpers/global.hpp"



namespace gm {
	Instance::Instance(const std::function<void()> &construct, const std::function<void()> destruct) :
		m_destruct {destruct},
		m_windowStack {}
	{
		gm::Global::setInstance(this);

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


	void Instance::pushCurrentWindow(gm::Window &window) {
		m_windowStack.push(&window);
	}


	void Instance::popCurrentWindow() {
		m_windowStack.pop();
	}


	gm::Window &Instance::getCurrentWindow() const noexcept {
		return *m_windowStack.top();
	}


} // namespace gm
