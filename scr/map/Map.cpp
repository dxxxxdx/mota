//
// Created by zys on 25-5-17.
//

#include "Map.h"

#include <iostream>
#include <utility>

Map::Map(const int size, std::vector<std::unique_ptr<Block>>& blocklist, const int spawnx, const int spawny,const int id) {
	if (blocklist.size() != size * size) {
		std::cerr << "Map::Map size is not equal to blocklist.size()" << std::endl;
		this->size = 0;
		this->blocklist.clear();
		return;
	}
	this->id = id;
	this->size = size;
	this->blocklist = std::move(blocklist);
	this->spawnx = spawnx;
	this->spawny = spawny;
}


int Map::getBlockId(const int x,const int y) const {
	return blocklist[x+y*size]->getId();
}
void Map::setBlock(const int x, const int y, Block& b) {
	blocklist[x+y*size] = std::make_unique<Block>(b);
}

Block* Map::getBlock(const int x, const int y) const {
	if (x < 0 || x >= size || y < 0 || y >= size) {
		std::cout << "Map::getBlock out of bounds" << std::endl;
		return nullptr;
	}
	return blocklist[x+y*size].get() ;
}

bool Map::clear() {
	for (auto &b : blocklist) {
		if (b && b->onClear()) {
			b= std::make_unique<Block>();
		}
	}




return true;
}

