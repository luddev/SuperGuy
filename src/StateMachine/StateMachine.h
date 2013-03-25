/*
 * StateMachine.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */
/* FINITE STATE MACHINE
 *  The machine is in only one state at a time;
 *  the state it is in at any given time is called the current state.
 *  It can change from one state to another when initiated by a triggering event or condition;
 *  this is called a transition.
 *  A particular FSM is defined by a list of its states,
 *  and the triggering condition for each transition.
 */


#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
enum STATES {
	STATE_NULL,	//NULL STATE
	STATE_INTRO, //INTRO or SPLASH SCREEN STATE
	STATE_TITLE, //TITLE STATE
	STATE_STAGE1, //STAGE1 can add other Stages later similar to STAGE1
	STATE_GAMEOVER, //GAMEOVER self explanatory
	STATE_QUIT //QUIT After Game over or random quit ;3
}; // States for State Machine

class stateMachine {
public:
	virtual void handle_events(); //Handle events for every state
	virtual void logic(); //Handle Logic for each state
	virtual void render(); //Handle rendering for each state
	virtual ~stateMachine(); //Destructor for each state
	void setNextState();	//Sets our next state
	void changeState();		//Changes State
private:
	int stateID;	//Current state ID any value of enum STATES
	int nextState;	//Next state ID
	stateMachine *currentState; //pointer to current state
};

class Intro: public stateMachine {
private:
	SDL_Surface *background;
	SDL_Surface *message;
public:
	Intro();
	~Intro();
	void handle_events();
	void logic();
	void render();

};

class Title: public stateMachine {
private:
	SDL_Surface *background;
	SDL_Surface *message;
public:
	Title();
	~Title();
	void handle_events();
	void logic();
	void render();

};
class Stage1: public stateMachine {
private:
	SDL_Surface *background;
	const static int levelWidth = 1024;
	const static int levelHeight = 768;
public:
	Stage1();
	~Stage1();
	void handle_events();
	void logic();
	void render();

};
class GameOver: public stateMachine {
private:
	SDL_Surface *background;
	SDL_Surface *message;
public:
	GameOver();
	~GameOver();
	void handle_events();
	void logic();
	void render();

};
#endif /* STATEMACHINE_H_ */
