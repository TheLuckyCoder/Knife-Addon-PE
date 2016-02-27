#include "DiamondKnife.h"

DiamondKnife::DiamondKnife(short itemId) : Item("knifeDiamond", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 4);
	this->setMaxStackSize(1);
	this->setMaxDamage(781);
	this->setHandEquipped();
	this->setStackedByData(true);
}

bool DiamondKnife::canDestroyInCreative() const{
	return false;
}

int DiamondKnife::getAttackDamage() {
	return 4.0F;
}

int DiamondKnife::getEnchantSlot() const{
	return 16;
}

int DiamondKnife::getEnchantValue() const{
	return 1;
}

void DiamondKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void DiamondKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
