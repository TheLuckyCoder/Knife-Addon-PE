#include "StoneKnife.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

StoneKnife::StoneKnife(short itemId) : Item("stoneKnife", itemId - 256)
{
	Item::mItems[itemId] = this;
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("knife_stone", 0);
	setMaxStackSize(1);
	setMaxDamage(Item::mSword_stone->getMaxDamage() / 2);
	setHandEquipped();
}

bool StoneKnife::canDestroyInCreative() const
{
	return false;
}

int StoneKnife::getAttackDamage()
{
	return (Item::mSword_stone->getAttackDamage() / 2);
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
