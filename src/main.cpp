#include <exception>
#include <iostream>

#include <SDL2/SDL.h>

#include "helpers/instance.hpp"
#include "helpers/window.hpp"



int main() {
	try {
		gm::Instance instance {};
		gm::Window window {"Hello", {16 * 70, 9 * 70}};

		bool running {true};
		while (running) {
			SDL_Event event {};
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					running = false;
					break;
				}

				if (event.type == SDL_QUIT) {
					running = false;
					break;
				}
			}
		}		
	}

	catch (const std::exception &exception) {
		std::cerr << "ERROR : " << exception.what() << std::endl;
		std::cerr << "SDL2 message : " << SDL_GetError() << std::endl;
	}

	return 0;
}