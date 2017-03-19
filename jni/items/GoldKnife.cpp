#include "GoldKnife.h"

GoldKnife::GoldKnife(short id) : KnifeItem(id, "gold", 16)
{}

int GoldKnife::getAttackDamage()
{
	return (Item::mSword_gold->getAttackDamage() / 2);
}

