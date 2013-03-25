/*
 * enemy.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include"AIEntity.h"
class enemyAnt: public aiEntity {

public:
	enemyAnt();
	~enemyAnt();
	void destroyMe();

};

#endif /* ENEMY_H_ */
