//
// Created by zys on 25-5-17.
//

#include "MapLoader.h"

#include <fstream>
#include <iostream>

#include "Map.h"
#include "nlohmann/json.hpp"
#include "allblocks.h"


std::shared_ptr<Map> MapLoader::createMap(const int mapid) {
	const std::filesystem::path filepath = std::filesystem::path(MAPS_DIR) / (std::to_string(mapid) + ".json");
	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cout << "cant open " << filepath << std::endl;
		return nullptr;
	}
	nlohmann::json json;
	file >> json;
	file.close();
	const int size = json["size"].get<int>();
	const int spawnx = json["spawnx"].get<int>();
	const int spawny = json["spawny"].get<int>();

	const std::vector<int> ids = json["blocklist"].get<std::vector<int> >();
	std::vector<std::unique_ptr<Block>> blocklist;

	for (int i = 0; i < size*size; i++) {
		blocklist.push_back(createBlock(ids[i])) ;

	}
	std::cout << "created a map , id:" <<mapid<<"   path :"<<filepath<< std::endl;

	return std::make_shared<Map>(size, blocklist,spawnx,spawny,mapid); ;




}




