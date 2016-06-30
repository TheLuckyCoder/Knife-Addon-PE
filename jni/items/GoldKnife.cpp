#include "GoldKnife.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

GoldKnife::GoldKnife(short itemId) : Item("goldKnife", itemId - 256)
{
	Item::mItems[itemId] = this;
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("knife_gold", 0);
	setMaxStackSize(1);
	setMaxDamage(Item::mSword_gold->getMaxDamage() / 2);
	setHandEquipped();
}

bool GoldKnife::canDestroyInCreative() const
{
	return false;
}

int GoldKnife::getAttackDamage()
{
	return (Item::mSword_gold->getAttackDamage() / 2);
}

int GoldKnife::getEnchantSlot() const
{
	return 16;
}

int GoldKnife::getEnchantValue() const{
	return 1;
}

void GoldKnife::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void GoldKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	item->hurtAndBreak(2, mob);
}
