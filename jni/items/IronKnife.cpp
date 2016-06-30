#include "IronKnife.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

IronKnife::IronKnife(short itemId) : Item("ironKnife", itemId - 256)
{
	Item::mItems[itemId] = this;
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("knife_iron", 0);
	setMaxStackSize(1);
	setMaxDamage(Item::mSword_iron->getMaxDamage() / 2);
	setHandEquipped();
}

bool IronKnife::canDestroyInCreative() const
{
	return false;
}

int IronKnife::getAttackDamage()
{
	return (Item::mSword_iron->getAttackDamage() / 2);
}

int IronKnife::getEnchantSlot() const
{
	return 16;
}

int IronKnife::getEnchantValue() const
{
	return 1;
}

void IronKnife::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void IronKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob){
	item->hurtAndBreak(2, mob);
}
