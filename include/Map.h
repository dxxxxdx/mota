//
// Created by zys on 25-5-17.
//

#ifndef MAP_H
#define MAP_H
#include <memory>
#include <vector>

#include "Block.h"


class Map {
public:
	std::vector<std::unique_ptr<Block>> blocklist;
	int size;
	~Map()=default;
	int id;



	Map(int size, std::vector<std::unique_ptr<Block>>& blocklist, int spawnx, int spawny,int id);

	[[nodiscard]] int getBlockId(int x,int y) const;

	void setBlock(int x,int y,Block& b);

	Block* getBlock(int x, int y) const;

	bool clear();

	int spawnx,spawny;



};



#endif //MAP_H
