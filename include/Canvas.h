//
// Created by zys on 25-5-18.
//

#ifndef CANVAS_H
#define CANVAS_H
#include <easyx.h>
#include <string>

#include "Map.h"


class Canvas {
public:

	IMAGE img;
	Canvas(const std::shared_ptr<Map>& map,const std::unique_ptr<Player>& player);
	~Canvas();
	bool update(const std::shared_ptr<Map> &map, const std::unique_ptr<Player> &player, const std::string &msg) const; // NOLINT(*-use-nodiscard)
	static std::string fpth(int picid);

	static std::string fpth(const std::string& name);
};



#endif //CANVAS_H
