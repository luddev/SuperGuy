/* ============================================================================
 * Name        : main.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

<<<<<<< HEAD
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
=======
#include <SDL2/SDL.h>
#include "Log.h"
#include "Engine/Engine.h"
>>>>>>> 2ed59a04090f2d4df9c4bff0d27bc4f4fcc3847f

int main(int argc, char ** argv) {
	Log::Open("log.txt");

	try {
		EngineInstance = new Engine();

		EngineInstance->Run();

		delete EngineInstance;
	} catch (std::exception * e) {
		if (EngineInstance) // Checks if eng isn't NULL
			delete EngineInstance;
		Log::Error("Engine crashed!");
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


	Log::Close();
	return 0;
}
