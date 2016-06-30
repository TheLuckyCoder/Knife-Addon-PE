#include "GoldKnife.h"

GoldKnife::GoldKnife(short itemId) : KnifeItem(itemId, "gold", 3, 16)
{}

int GoldKnife::getAttackDamage()
{
	return (Item::mSword_gold->getAttackDamage() / 2);
}
