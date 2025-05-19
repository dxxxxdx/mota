//
// Created by zys on 25-5-17.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"


class Game;

class Player {

	int hp,atk,def,coin;
	int posx,posy;
	std::shared_ptr<Map> map;//in this map
	public:
	Game* game;//in this game

	void heal(int num);
	void hurt(int num);

	int getHp() const;
	int& getHpref() ;

	int getcoin() const;

	void gotoUpStair();

	void gotoDownstair();



	bool changeFloor(int targetMapId);

	void addatk(int num);
	void adddef(int num);
	void addcoin(int num);
	explicit Player(const std::shared_ptr<Map>& map,Game& game);
	void move(int dx,int dy);
	void spawn(const std::shared_ptr<Map> &map);
	std::shared_ptr<Map> getMap() const;

	void setMap(const std::shared_ptr<Map> &map);

	int getposx() const;
	int getposy() const;
	int getatk() const;
	int getdef() const;





};



#endif //PLAYER_H
