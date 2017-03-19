#include "StoneKnife.h"

StoneKnife::StoneKnife(short id) : KnifeItem(id, "stone", 66)
{}

int StoneKnife::getAttackDamage()
{
	return (Item::mSword_stone->getAttackDamage() / 2);
}

