//
// Created by zys on 25-5-17.
//

#ifndef ALLBLOCKS_H
#define ALLBLOCKS_H
#include <functional>
#include <iostream>
#include "Block.h"
#include <map>
#include "downstair.h"
#include "enemy.h"
#include "Item.h"
#include "terrain.h"
#include "upstair.h"


enum blockid {
        EMPTY = 0,      // 默认空地
        TERRAIN = 1,    // 地形（不可通过但可摧毁）
        GREENSLIME = 2,      // 普通敌人
        PASSABLE_TERRAIN = 3,  // 可通过但不可摧毁的地形
        UNBEATABLE_ENEMY = 4,  // 不可战胜的敌人
        HEALPOTION = 5, // 恢复药水
        GEM = 6,        // 增加攻击的宝石
        ARMOUR = 7,     // 增加防御的装备
        DESTROYABLE_TERRAIN = 8, // 不能通过但可以摧毁的障碍物
        WEAK_ENEMY = 9 , // 弱小敌人
        UPSTAIR = 10,
        DOWNSTAIR = 11,
    };


inline std::map<int, std::function<std::unique_ptr<Block>()>> blockregister = {
    {0, [] { return std::make_unique<Block>(); }},
    {1, [] { return std::make_unique<terrain>(1, false, true); }},
    {2, [] { return std::make_unique<enemy>(2, 20, 3, 3, 2, std::vector<enemytags>{}); }},
    {3, [] { return std::make_unique<terrain>(3, true, false); }}, // 可通过但不能摧毁的地形
    {4, [] { return std::make_unique<enemy>(4, 50, 5, 5, 10, std::vector<enemytags>{UNBEATABLE}); }}, // 不可战胜的敌人
    {5, [] { return std::make_unique<Item>(5, ITEM_HEALPOTION, 20, std::vector<itemtags>{}); }}, // 恢复药水
    {6, [] { return std::make_unique<Item>(6, ITEM_GEM, 5, std::vector<itemtags>{ADDATK}); }}, // 增加攻击的宝石
    {7, [] { return std::make_unique<Item>(7, ITEM_ARMOUR, 30, std::vector<itemtags>{ADDDEF}); }}, // 防御装备
    {8, [] { return std::make_unique<terrain>(8, false, true); }}, // 不能通过但可以摧毁的障碍物
    {9, [] { return std::make_unique<enemy>(9, 15, 2, 1, 3, std::vector<enemytags>{}); }},// 弱小敌人
    {10,[] { return std::make_unique<upstair>(); }},
    {11,[] { return std::make_unique<downstair>(); }},
};

inline std::unique_ptr<Block> createBlock(const int id) {
    if (blockregister.contains(id)) {

        auto a = blockregister[id]();
        std::cout << a->getId();
        if (!a) {
            std::cerr << a->getId();
            return nullptr;
        }
        return std::move(a);
    }
    std::cerr<<"Create Block error"<<id<<std::endl;
    return nullptr;
}



#endif //ALLBLOCKS_H
