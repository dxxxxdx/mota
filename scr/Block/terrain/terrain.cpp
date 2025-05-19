//
// Created by zys on 25-5-17.
//

#include "terrain.h"

#include <iostream>
#include <ostream>

terrain::terrain(const int id, const bool can_pass, const bool can_destroy) {
	setId(id);
	this->can_pass = can_pass;
	this->can_destroy = can_destroy;
	this->setType(TERRAIN);
	this->is_destroyed = false;

}
bool terrain::interact(Player&p) {
	std::cout<<"interact a terrain"<<std::endl;
	if (can_pass) {
		std::cout<<"can pass"<<std::endl;
		return true;
	}
	return false;
}
bool terrain::onClear() {
	if (is_destroyed){return true;}
	return false;
}

terrain::terrain() {
	setId(0);
	setType(TERRAIN);
	can_pass = true;
	can_destroy = false;
	is_destroyed = false;
}
