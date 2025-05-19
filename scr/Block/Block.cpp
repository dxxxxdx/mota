//
// Created by zys on 25-5-17.
//

#include "Block.h"

#include <iostream>
#include <ostream>



Block::Block() {
	id = 0;
	type = TERRAIN;
}


Block::~Block() = default;

int Block::getId() const {
	return this->id;
}
void Block::setId(const int id) {
	this->id = id;
}

Block::blocktype Block::getType() const{
	return this->type;
}
void Block::setType(const blocktype type) {
	this->type = type;
}

bool Block::interact(Player& p) {
	if (this->id != 0) {
		std::cout << "Interact a block without classified" << std::endl;
		return false;
	}
	return true;
}
bool Block::onClear() {
	id = 0;
	type = TERRAIN;

	return false;
}