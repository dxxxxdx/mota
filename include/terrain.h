//
// Created by zys on 25-5-17.
//

#ifndef TERRAIN_H
#define TERRAIN_H
#include <Block.h>


class terrain :public Block{
	public:
	bool can_pass;
	bool can_destroy;
	bool is_destroyed;
	terrain(int id,bool can_pass,bool can_destroy);
	bool interact(Player& p) override;
	bool onClear() override;

	terrain();


};



#endif //TERRAIN_H
