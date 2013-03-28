/*
 * StateMachine.cpp
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

#include"StateMachine.h"

void setNextState(int newState) {
	if (nextState != STATE_QUIT) {
		nextState = newState;
	}
}

void changeState() {
	if (nextState != STATE_NULL) {
		if (nextState != STATE_QUIT) {
			delete currentState;
		}
		switch (nextState) {
		case STATE_TITLE:
			currentState = new Title();
			break;

		case STATE_OVERWORLD:
			currentState = new OverWorld(stateID);
			break;

		case STATE_STAGE1:
			currentState = new Stage1();
			break;
		}

		//Change the current state ID
		stateID = nextState;

		//NULL the next state ID
		nextState = STATE_NULL;
	}
}

Intro::Intro() {
}

Intro::~Intro() {
}

void Intro::handle_events() {
}

void Intro::logic() {
}

void Intro::render() {
}

Title::Title() {
}

Title::~Title() {
}

void Title::handle_events() {
}

void Title::logic() {
}

void Title::render() {
}

OverWorld::OverWorld(int int1) {
}

OverWorld::~OverWorld() {
}

void OverWorld::handle_events() {
}

void OverWorld::logic() {
}

void OverWorld::render() {
}

Stage1::Stage1() {
}

Stage1::~Stage1() {
}

void Stage1::handle_events() {
}

void Stage1::logic() {
}

void Stage1::render() {
}

GameOver::GameOver() {
}

GameOver::~GameOver() {
}

void GameOver::handle_events() {
}

void GameOver::logic() {
}

void GameOver::render() {
}
