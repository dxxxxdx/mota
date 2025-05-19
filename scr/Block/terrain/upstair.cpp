//
// Created by zys on 25-5-19.
//


#include "upstair.h"
#include <allblocks.h>
#include "Player.h"

upstair::upstair() {
	setId(UPSTAIR);
	setType(TERRAIN);
	can_pass = true;
	can_destroy = false;
	is_destroyed = false;
}

bool upstair::onClear() {
	return false;
}

bool upstair::interact(Player &p) {
	return !p.changeFloor(p.getMap()->id +1);
}
