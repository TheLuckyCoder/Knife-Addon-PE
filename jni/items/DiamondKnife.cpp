#include "DiamondKnife.h"

DiamondKnife::DiamondKnife(short itemId) : KnifeItem(itemId, "diamond", 4, 781)
{}

int DiamondKnife::getAttackDamage()
{
	return (Item::mSword_diamond->getAttackDamage() / 2);
}
