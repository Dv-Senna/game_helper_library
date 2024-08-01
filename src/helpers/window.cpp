#include "helpers/window.hpp"

#include <stdexcept>



namespace gm {
	Window::Window(const std::string &title, const gm::Vec2i &size) :
		m_window {nullptr},
		m_size {size}
	{
		m_window = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_size.x, m_size.y,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
		);
		if (m_window == nullptr)
			throw std::runtime_error("Can't create an SDL2 window");

		SDL_SetWindowMinimumSize(m_window, m_size.x, m_size.y);
	}


	Window::~Window() {
		if (m_window != nullptr)
			SDL_DestroyWindow(m_window);
	}


	void Window::resize(const gm::Vec2i &size) {
		m_size = size;
		SDL_SetWindowSize(m_window, size.x, size.y);
	}


	void Window::setMinSize(const gm::Vec2i &minSize) {
		SDL_SetWindowMinimumSize(m_window, minSize.x, minSize.y);
	}


	void Window::handleResize() {
		SDL_GetWindowSize(m_window, &m_size.x, &m_size.y);
	}


} // namespace gm
