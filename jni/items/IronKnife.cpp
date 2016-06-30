#include "IronKnife.h"

IronKnife::IronKnife(short itemId) : KnifeItem(itemId, "iron", 2, 125)
{}

int IronKnife::getAttackDamage()
{
	return (Item::mSword_iron->getAttackDamage() / 2);
}
