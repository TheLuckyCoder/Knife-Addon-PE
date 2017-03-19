#include "IronKnife.h"

IronKnife::IronKnife(short id) : KnifeItem(id, "iron", 125)
{}

int IronKnife::getAttackDamage()
{
	return (Item::mSword_iron->getAttackDamage() / 2);
}

