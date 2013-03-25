/* ============================================================================
 * Name        : main.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

/*! \mainpage SuperGuy
 *
 * \section intro_sec Introduction
 *
 * A SuperMario themed clone with 8 bit Music.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Download
 *
 *
 */

#include <iostream>
#include <SDL2/SDL.h>
#include "log.h"
#include "engine/engine.h"

int main(int argc, char ** argv) {
	engine * eng = NULL;
	log::open("log.txt");

	try {
		eng = new engine();

		SDL_Delay(5 * 1000);

		delete eng;
	} catch (std::exception * e) {
		if (eng)
			delete eng;
		log::error("Engine crashed!");
	}

	log::close();
	return 0;
}
