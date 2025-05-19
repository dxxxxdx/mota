//
// Created by zys on 25-5-17.
//

#include "enemy.h"

#include <iostream>
#include <ostream>
#include <utility>

#include <algorithm>
#include <vector>

#include "Game.h"
#include "../../../include/Player.h"


enemy::enemy(const int id ,const int hp, const int atk, const int def,const int value, std::vector<enemytags> tags) {
	setId(id);
	this->hp=hp;
	this->atk=atk;
	this->def=def;
	this->value=value;
	this->tags=std::move(tags);
	this->setType(ENEMY);
}
bool enemy::interact(Player& p) {
	std::cout<<"fight" <<std::endl;
	if (!canBattle(p)) {
		Game::showmsg("you are not able to do that");
		return false;
	}
	const bool a = onBattle(hp,p.getHpref(),atk,p.getatk(),def,p.getdef(),tags);
	Game::showmsg("you win");
	p.addcoin(value);
	return a;

}
bool enemy::canBattle(const Player& p) const {

	auto hp_mon = hp;

	int hp_hero = p.getHp();

	return onBattle( hp_mon, hp_hero, atk,p.getatk(), def,p.getdef(), tags);

}
bool enemy::onBattle(int& mon_hp,int& hero_hp,const int& mon_atk,const int&hero_atk,const int&mon_def,const int&hero_def,const std::vector<enemytags>&tags) {
	while (true) {
		if (std::ranges::contains(tags,UNBEATABLE)) {

			return false;
		}
		if (hero_atk<=mon_def) {
			return false;
		}
		mon_hp-=hero_atk+mon_def;
		if (mon_hp<=0) {
			return true;
		}
		hero_hp-=mon_atk+hero_def;
		if (hero_hp<=0) {
			return false;
		}

	}



}
bool enemy::onClear() {
	if (hp<=0) {
	return true;
	}
	return false;
}

