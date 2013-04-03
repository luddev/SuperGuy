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
#include "engine/state/stateMachine.h"

int main(int argc, char ** argv) {
	log::open("log.txt");

	try {
		engineInstance = new engine();

		SDL_Delay(5 * 1000);

		delete engineInstance;
	} catch (std::exception * e) {
		if (engineInstance) // Checks if eng isn't NULL
			delete engineInstance;
		log::error("Engine crashed!");
	}
	 while( stateID != STATE_QUIT )
	    {

	        //Do state event handling
	        currentState->handle_events();

	        //Do state logic
	        currentState->logic();

	        //Change state if needed
	        changeState();

	        //Do state rendering
	        currentState->render();
	    }


	log::close();
	return 0;
}
