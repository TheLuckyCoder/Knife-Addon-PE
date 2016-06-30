#pragma once

#include "minecraftpe/world/item/Item.h"

class KnifeItem : public Item
{
public:
	KnifeItem(short itemId, const std::string &name, int type, int damage);

	virtual bool canDestroyInCreative() const;
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
