#include "DiamondKnife.h"

DiamondKnife::DiamondKnife(short id) : KnifeItem(id, "diamond", 781)
{}

int DiamondKnife::getAttackDamage()
{
	return (Item::mSword_diamond->getAttackDamage() / 2);
}

