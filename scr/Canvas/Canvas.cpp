//
// Created by zys on 25-5-18.
//


#include "Canvas.h"

#include <filesystem>
#include <graphics.h>
#include <iostream>
#include <string>

#include "Player.h"


Canvas::Canvas(const std::shared_ptr<Map>& map,const std::unique_ptr<Player>& player) {
	const int size = map->size;
	initgraph(size*64,size*64 + 128);
}


Canvas::~Canvas() {
	closegraph();
}

bool Canvas::update(const std::shared_ptr<Map>& map,const std::unique_ptr<Player>& player, const std::string& msg) const {
	map->clear();
	cleardevice();
	IMAGE bg ;
	loadimage(&bg,fpth("bg").c_str());
	putimage(0,0,&bg);
	for (int i = 0; i < map->size * map->size; i++) {
		const int id = map ->getBlockId(i%map->size, i/map->size);
		IMAGE img ;
		loadimage(&img,fpth(id).c_str());
		putimage(i%map->size*64,128 + (i/map->size)*64 , &img,SRCCOPY);
	}
	IMAGE heroImg;
	loadimage(&heroImg,fpth("hero").c_str());
	putimage(player->getposx()*64,128 + player->getposy()*64,&heroImg,SRCCOPY);
	settextstyle(24, 0, "Arial"); // 设置字体大小
	const std::string status = "HP: " + std::to_string(player->getHp()) +
						 "  ATK: " + std::to_string(player->getatk()) +
						 "  DEF: " + std::to_string(player->getdef()) +
						 "  COINS: " + std::to_string(player->getcoin()) +
						 "\n     " + msg	;
	outtextxy(10, 10, status.c_str()); // 在窗口顶部绘制状态
	return true;
}

std::string Canvas::fpth(const int picid) {
	const auto filepath = PICS_DIR + ("/" + (std::to_string(picid) + ".png"));
	return filepath;
}

std::string Canvas::fpth(const std::string& name) {
	const auto filepath = PICS_DIR+("/"+ name + ".png");
	return filepath;
}
