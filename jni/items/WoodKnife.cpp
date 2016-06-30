#include "WoodKnife.h"

WoodKnife::WoodKnife(short itemId) : KnifeItem(itemId, "wood", 0, 30)
{}

int WoodKnife::getAttackDamage()
{
	return (Item::mSword_wood->getAttackDamage() / 2);
}
