#include "StoneKnife.h"

StoneKnife::StoneKnife(short itemId) : Item("knifeStone", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 1);
	this->setMaxStackSize(1);
	this->setMaxDamage(66);
	this->setHandEquipped();
	this->setStackedByData(true);
}

bool StoneKnife::canDestroyInCreative() const{
	return false;
}

int StoneKnife::getAttackDamage() {
	return 3.0F;
}

int StoneKnife::getEnchantSlot() const{
	return 16;
}

int StoneKnife::getEnchantValue() const{
	return 1;
}

void StoneKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void StoneKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
