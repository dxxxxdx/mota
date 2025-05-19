//
// Created by zys on 25-5-17.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <vector>

#include "Block.h"

enum enemytags {
	UNBEATABLE
};
class enemy :public Block {

	public:
	int hp;int atk;int def;int value;std::vector<enemytags> tags;
	enemy(int id,int hp,int atk,int def,int value,std::vector<enemytags> tags);
	bool interact(Player& p) override;
	bool onClear() override;
	[[nodiscard]] bool canBattle(const Player& p) const;

	static bool onBattle(int &mon_hp, int &hero_hp, const int &mon_atk, const int &hero_atk, const int &mon_def, const int &hero_def, const std
	                     ::vector<enemytags> &tags);
};



#endif //ENEMY_H
