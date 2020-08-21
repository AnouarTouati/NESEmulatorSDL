#pragma once
#include "SDL.h"
#include <iostream>
#include <spdlog/spdlog.h>

	class IOCore {
	public:
		IOCore(std::shared_ptr<spdlog::logger> Logger): Logger(Logger){

		}
		void Init();
		void RefreshDisplay();
		void HandleEvents();
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		const uint8_t TargetFrameTime = 16;//60FPS
		Uint32 LastFramTime;//time since SDL initialized
		std::shared_ptr<spdlog::logger> Logger;
	};
