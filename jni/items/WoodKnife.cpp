#include "WoodKnife.h"

WoodKnife::WoodKnife(short id) : KnifeItem(id, "wood", 30)
{}

int WoodKnife::getAttackDamage()
{
	return (Item::mSword_wood->getAttackDamage() / 2);
}

