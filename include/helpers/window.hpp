#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "helpers/vector.hpp"



namespace gm {
	class Window {
		public:
			Window(const std::string &title, const gm::Vec2i &size);
			~Window();

			void resize(const gm::Vec2i &size);
			void setMinSize(const gm::Vec2i &minSize);
			void handleResize();

			inline SDL_Window *getWindow() const noexcept {return m_window;}
			inline const gm::Vec2i &getSize() const noexcept {return m_size;}


		private:
			SDL_Window *m_window;
			gm::Vec2i m_size;
	};

} // namespace gm
