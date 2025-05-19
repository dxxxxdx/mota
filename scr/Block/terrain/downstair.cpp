//
// Created by zys on 25-5-19.
//


#include "downstair.h"
#include <allblocks.h>

#include "Player.h"

downstair::downstair() {
	setId(DOWNSTAIR);
	setType(TERRAIN);
	can_pass = true;
	can_destroy = false;
	is_destroyed = false;
}

bool downstair::onClear() {
	return false;
}

bool downstair::interact(Player &p) {
	return !p.changeFloor(p.getMap()->id -1);
}
