//
// Created by zys on 25-5-17.
//

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"


class MapLoader {
	public:
	static std::shared_ptr<Map> createMap(int mapid);
};



#endif //MAPLOADER_H
