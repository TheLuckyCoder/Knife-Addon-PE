#include "Knifes.h"

GoldKnife::GoldKnife(short itemId) : Item("goldKnife", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 3);
	this->setMaxStackSize(1);
	this->setMaxDamage(16);
	this->setHandEquipped();
}

bool GoldKnife::canDestroyInCreative() const{
	return false;
}

int GoldKnife::getAttackDamage() {
	return 2.5F;
}

int GoldKnife::getEnchantSlot() const{
	return 16;
}

int GoldKnife::getEnchantValue() const{
	return 1;
}

void GoldKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void GoldKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
