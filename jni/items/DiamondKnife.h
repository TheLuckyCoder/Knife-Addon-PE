#pragma once

#include "minecraftpe/world/item/Item.h"

class DiamondKnife : public Item
{
public:
	DiamondKnife(short itemId);

	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
