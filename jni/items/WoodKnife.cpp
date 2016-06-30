#include "WoodKnife.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

WoodKnife::WoodKnife(short itemId) : Item("woodKnife", itemId - 256)
{
	Item::mItems[itemId] = this;
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("knife_wood", 0);
	setMaxStackSize(1);
	setMaxDamage(Item::mSword_wood->getMaxDamage() / 2);
	setHandEquipped();
}

bool WoodKnife::canDestroyInCreative() const
{
	return false;
}

int WoodKnife::getAttackDamage()
{
	return (Item::mSword_wood->getAttackDamage() / 2);
}

int WoodKnife::getEnchantSlot() const
{
	return 16;
}

int WoodKnife::getEnchantValue() const
{
	return 1;
}

void WoodKnife::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void WoodKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	item->hurtAndBreak(2, mob);
}
