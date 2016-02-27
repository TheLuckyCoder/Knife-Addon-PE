#include "EmeraldKnife.h"

EmeraldKnife::EmeraldKnife(short itemId) : Item("knifeEmerald", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("knife", 5);
	this->setMaxStackSize(1);
	this->setMaxDamage(1000);
	this->setHandEquipped();
	this->setStackedByData(true);
}

bool EmeraldKnife::canDestroyInCreative() const{
	return false;
}

int EmeraldKnife::getAttackDamage() {
	return 4.0F;
}

int EmeraldKnife::getEnchantSlot() const{
	return 16;
}

int EmeraldKnife::getEnchantValue() const{
	return 1;
}

void EmeraldKnife::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void EmeraldKnife::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}
