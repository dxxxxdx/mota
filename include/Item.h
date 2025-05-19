//
// Created by zys on 25-5-19.
//

#ifndef ITEM_H
#define ITEM_H
#include <vector>

#include "Block.h"

enum itemtype {
	ITEM_NONE,
	ITEM_HEALPOTION,
	ITEM_GEM,
	ITEM_WEAPON,
	ITEM_ARMOUR
};
enum itemtags {
	NONE,
	ADDATK,
	ADDDEF
};
class Item :public Block {
public:
	bool interact(Player &p) override;
	bool onClear() override;
	itemtype itemtype;
	int effect;
	std::vector<itemtags> tags;
	bool available;
	Item(int id,enum itemtype itemtype,int effect, const std::vector<itemtags> &tags);

};



#endif //ITEM_H
