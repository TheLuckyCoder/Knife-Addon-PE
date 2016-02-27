#pragma once
#include <vector>
#include <string>
#include "../Item.h"
#include "../ItemInstance.h"
#include "../../level/block/Block.h"

class Recipes {
public:
    struct Type {
        Item* item;
        Block* block;
        ItemInstance inst;
        char letter;
    };

    static Recipes* getInstance();
    
    void init();
    void addShapedRecipe(const ItemInstance&, const std::vector<std::string>&, const std::vector<Recipes::Type>&);
};
