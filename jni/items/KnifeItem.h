#pragma once

#include "minecraftpe/world/item/Item.h"

class KnifeItem : public Item
{
public:
	KnifeItem(short id, const std::string &name, short damage);

	virtual bool canDestroyInCreative() const;
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

