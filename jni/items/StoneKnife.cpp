#include "StoneKnife.h"

StoneKnife::StoneKnife(short itemId) : Item("knifeStone", itemId - 256)
{
	Item::mItems[itemId] = this;
	creativeCategory = 3;
	setIcon("knife", 1);
	setMaxStackSize(1);
	setMaxDamage(66);
	setHandEquipped();
}

bool StoneKnife::canDestroyInCreative() const
{
	return false;
}

int StoneKnife::getAttackDamage()
{
	return (Item::mSword_stone->getAttackDamage / 2);
}

int StoneKnife::getEnchantSlot() const
{
	return 16;
}

int StoneKnife::getEnchantValue() const
{
	return 1;
}

void StoneKnife::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void StoneKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	item->hurtAndBreak(2, mob);
}
