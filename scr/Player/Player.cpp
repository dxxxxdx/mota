//
// Created by zys on 25-5-17.
//

#include <iostream>

#include "allblocks.h"
#include "Game.h"

void Player::addatk(const int num) {
	atk = atk + num;
}
void Player::adddef(const int num) {
	def = def + num;
}
void Player::addcoin(const int num) {
	coin = coin + num;
}

void Player::heal(const int num) {
	if (num<0){return;}
	hp += num;
}
void Player::hurt(const int num) {
	if (num<0){return;}
	hp -= num;
}
int Player::getHp() const {
	return hp;
}
Player::Player(const std::shared_ptr<Map>& map,Game& game) {
	hp = 100;
	atk = 5;
	def = 5;
	coin = 0;
	this->map = map;
	this->game = &game;
	posx = this->map->spawnx;
	posy = this->map->spawny;
	std::cout <<"Player Constructor"<<std::endl;
}


void Player::spawn(const std::shared_ptr<Map> &map) {
	this->map = map;
	posx = map->spawnx;
	posy = map->spawny;

}

void Player::move(const int dx ,const int dy) {
	if (dx*dy !=0) {
		std::cout<<"Move to a undefined direction"<<std::endl;
		return;
	}
	if (map==nullptr) {
		std::cout<<"Map is null"<<std::endl;
		return;
	}
	if (map->getBlock(posx+dx,posy+dy)!=nullptr && map->getBlock(posx+dx,posy+dy)->interact(*this)) {
		map->clear();
		posx += dx;
		posy += dy;
		std::cout<<"Player success to move "<<std::endl;
	}
	map->clear();
	std::cout<<"Player now at "<<posx<<" , "<<posy<<std::endl;
}


std::shared_ptr<Map> Player::getMap() const {
	return map;
}
void Player::setMap(const std::shared_ptr<Map>& map) {
	this->map = map;

}
int Player::getposx() const {
	return posx;
}
int Player::getposy() const {
	return posy;
}

int Player::getatk() const {
	return atk;
}
int Player::getdef() const {
	return def;
}

int &Player::getHpref() {
	return hp;
}
int Player::getcoin() const {
	return coin;
}

void Player::gotoUpStair() {
	int count = 0;
	for (const auto &i : this->getMap()->blocklist) {
		if (i->getId()==UPSTAIR) {
			this->posx = count % this->getMap()->size;
			this->posy = count / this->getMap()->size;
		}
		count++;
	}
}
void Player::gotoDownstair() {
	int count = 0;
	for (const auto &i : this->getMap()->blocklist) {
		if (i->getId()==DOWNSTAIR) {
			this->posx = count % this->getMap()->size;
			this->posy = count / this->getMap()->size;
		}
		count++;
	}
}



bool Player::changeFloor(const int targetMapId) {
	const auto oldFloorId = this->getMap()->id;
	if (oldFloorId == targetMapId) {
		return false;
	}
	if (!game->getMapById(targetMapId)) {
		Game::showmsg("Map do not exist "+ std::to_string(targetMapId));
		return false;
	}
	this->setMap(game->getMapById(targetMapId));
	if (oldFloorId >= targetMapId) {
		this->setMap(game->getMapById(targetMapId));
		this->gotoUpStair();
	}
	else if (oldFloorId <= targetMapId) {
		this->setMap(game->getMapById(targetMapId));
		this->gotoDownstair();
	}
	else {
		std::cerr<<"Map have no stair"<<std::endl;
		return false;
	}
	return true;
}

