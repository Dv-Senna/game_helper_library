#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>


int main() {

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window {SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 16 * 70, 9 * 70, 0)};

	bool running {true};
	while (running) {
		SDL_Event event {};
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}