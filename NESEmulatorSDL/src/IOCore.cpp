#include "IOCore.h"


	
	void IOCore::Init() {
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("NESEmulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 224, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	void IOCore::HandleEvents() {
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT: exit(0); break;
		default: break;
		}
	}
	void IOCore::RefreshDisplay() {
		for (int i = 0; i < 50; i++) {
			SDL_SetRenderDrawColor(renderer, 255, i * 5, 0, 255);
			SDL_RenderDrawPoint(renderer, i, 50);
		
		}
		SDL_RenderPresent(renderer);
		Uint32 FrameTime = SDL_GetTicks() - LastFramTime;
		
		if (FrameTime < TargetFrameTime) {
			SDL_Delay(TargetFrameTime - FrameTime);
		}
		LastFramTime = SDL_GetTicks();
	}
