#include "WoodKnife.h"

WoodKnife::WoodKnife(short itemId) : Item("knifeWood", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 0);
	this->setMaxStackSize(1);
	this->setMaxDamage(30);
	this->setHandEquipped();
	this->setStackedByData(true);
}

bool WoodKnife::canDestroyInCreative() const{
	return false;
}

int WoodKnife::getAttackDamage() {
	return 2.5F;
}

int WoodKnife::getEnchantSlot() const{
	return 16;
}

int WoodKnife::getEnchantValue() const{
	return 1;
}

void WoodKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m) {
	item->hurtAndBreak(1, m);
}

void WoodKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
