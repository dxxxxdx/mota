#ifndef DOWNSTAIR_H
#define DOWNSTAIR_H

#include "terrain.h"
#include "Player.h"

class downstair final : public terrain {
public:
	downstair(); // 构造函数
	bool interact(Player &p) override; // 交互方法
	bool onClear() override; // 清除方法
};

#endif // DOWNSTAIR_H
