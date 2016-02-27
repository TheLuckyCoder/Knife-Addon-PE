#include "IronKnife.h"

IronKnife::IronKnife(short itemId) : Item("knifeIron", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 2);
	this->setMaxStackSize(1);
	this->setMaxDamage(125);
	this->setHandEquipped();
	this->setStackedByData(true);
}

bool IronKnife::canDestroyInCreative() const{
	return false;
}

int IronKnife::getAttackDamage() {
	return 3.5F;
}

int IronKnife::getEnchantSlot() const{
	return 16;
}

int IronKnife::getEnchantValue() const{
	return 1;
}

void IronKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void IronKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
