//
// Created by zys on 25-5-18.
//

#ifndef GGAME_H
#define GGAME_H
#include "Canvas.h"
#include "Player.h"


class Game {
	public:

	std::unique_ptr<Player> player;
	std::unique_ptr<Canvas> canvas;
	std::vector<std::shared_ptr<Map>> maps;
	static std::string msg;
	static void showmsg(const std::string &msg);
	Game();
	~Game()=default;
	void run () const;
	std::shared_ptr<Map> getMapById(int id) const;

};



#endif //GGAME_H
