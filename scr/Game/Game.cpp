//
// Created by zys on 25-5-18.
//

#include "../../include/Game.h"

#include <format>
#include <graphics.h>
#include <iostream>

#include "MapLoader.h"


std::string Game::msg = "";
std::shared_ptr<Map> Game::getMapById(const int id) const {
	if (id < 0 || id >= maps.size()) {
		std::cerr << "Invalid map id: " << id << std::endl;
		return nullptr;
	}
	return maps[id];
}
void Game::showmsg(const std::string &msg) {
	std::cout<< msg << std::endl;
	Game::msg = msg;
}
Game::Game() {
	int i = 0;
	while (true) {
		auto a =MapLoader::createMap(i);
		if (a == nullptr)break;
		this->maps.push_back(std::move(a));
		i++;
	}


	player = std::make_unique<Player>(maps[0],*this);

	player->game = this;
	canvas= std::make_unique<Canvas>(maps[0],player);
	canvas->update(player->getMap(),player, msg);
}
void Game::run() const {
	ExMessage msg{};
	bool done = true;
	bool keyPressed = false; // 用于标记按键是否已经处理

	while (done) {
		if (peekmessage(&msg, EM_KEY)) {
			if (msg.message == WM_KEYDOWN && !keyPressed) { // 仅在按键首次按下时执行
				keyPressed = true; // 标记按键已处理

				switch (msg.vkcode) {
					case VK_UP: player->move(0, -1); break;
					case VK_DOWN: player->move(0, 1); break;
					case VK_LEFT: player->move(-1, 0); break;
					case VK_RIGHT: player->move(1, 0); break;
					case VK_SPACE: done = false; break;
					default: break;
				}

				canvas->update(player->getMap(), player, Game::msg);
			}
			else if (msg.message == WM_KEYUP) {
				keyPressed = false; // 按键释放后，允许再次移动
			}
		}
	}
}


