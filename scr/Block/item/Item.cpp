//
// Created by zys on 25-5-19.
//

#include "Item.h"
#include "algorithm"
#include "Game.h"


Item::Item(const int id, const enum itemtype itemtype, const int effect, const std::vector<itemtags> &tags) {
	setId(id);
	setType(ITEM);
	this->itemtype = itemtype;
	this->effect = effect;
	this->tags = tags;
	available = true;
}

bool Item::interact(Player &p) {
	switch (this->itemtype) {
		case ITEM_NONE:
			Game::showmsg("You are not allowed to interact with this item.");
			return false;
		case ITEM_HEALPOTION:
			p.heal(effect);
			available = false;
			return true;
		case ITEM_GEM:
			if (std::ranges::contains(tags,ADDATK)) {
				p.addatk(effect*(1+p.getMap()->id));
			}
			if (std::ranges::contains(tags,ADDDEF)) {
				p.adddef(effect*(1+p.getMap()->id));
			}
			available = false;
			return true;
		case ITEM_WEAPON:
			p.addatk(effect);
			available = false;
			return true;
		case ITEM_ARMOUR:
			p.adddef(effect);
			available = false;
			return true;
		default:
			Game::showmsg("You are not allowed to interact with this item.");
			return false;
	}
}
bool Item::onClear() {
	if (available) {
		return false;
	}
	return true;
}










