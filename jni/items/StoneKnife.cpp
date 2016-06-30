#include "StoneKnife.h"

StoneKnife::StoneKnife(short itemId) : KnifeItem(itemId, "stone", 1, 66)
{}

int StoneKnife::getAttackDamage()
{
	return (Item::mSword_stone->getAttackDamage() / 2);
}
