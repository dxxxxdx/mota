//
// Created by zys on 25-5-17.
//

#ifndef BLOCK_H
#define BLOCK_H
class Player;

class Block {
public:
	enum blocktype { NULL_,TERRAIN,ENEMY,ITEM,};
	Block();

	virtual ~Block();
	[[nodiscard]] int getId() const;
	void setId(int id);
	[[nodiscard]] blocktype getType() const;
	void setType(blocktype type);
	virtual bool interact(Player& p);

	bool virtual onClear();

private:
	int id;
	blocktype type;

};



#endif //BLOCK_H
