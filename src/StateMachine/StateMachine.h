/*
 * StateMachine.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
enum STATES {
	STATE_NULL,
	STATE_INTRO,
	STATE_TITLE,
	STATE_STAGE,
	STATE_GAMEOVER,
	STATE_QUIT
};

class stateMachine {
public:
	virtual void handle_events();
	virtual void logic();
	virtual void render();
	virtual ~stateMachine(){};
	void setNextState();
	void changeState();
private:
	int stateID;
	int nextState;
	stateMachine *currentState;
};

#endif /* STATEMACHINE_H_ */
