#include "DiamondKnife.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

DiamondKnife::DiamondKnife(short itemId) : Item("diamondKnife", itemId - 256)
{
	Item::mItems[itemId] = this,
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("knife_diamond", 0);
	setMaxStackSize(1);
	setMaxDamage(Item::mSword_diamond->getMaxDamage() / 2);
	setHandEquipped();
}

bool DiamondKnife::canDestroyInCreative() const
{
	return false;
}

int DiamondKnife::getAttackDamage()
{
	return (Item::mSword_diamond->getAttackDamage() / 2);
}

int DiamondKnife::getEnchantSlot() const
{
	return 16;
}

int DiamondKnife::getEnchantValue() const
{
	return 1;
}

void DiamondKnife::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void DiamondKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	item->hurtAndBreak(2, mob);
}
