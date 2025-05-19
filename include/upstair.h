//
// Created by zys on 25-5-19.
//

#ifndef UPSTAIR_H
#define UPSTAIR_H
#include "terrain.h"


class upstair final :public terrain {
public:
	upstair();
	bool interact(Player &p) override;

	bool onClear() override;

};



#endif //UPSTAIR_H
