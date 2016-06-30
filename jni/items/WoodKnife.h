#pragma once

#include "KnifeItem.h"

class WoodKnife : public KnifeItem
{
public:
	WoodKnife(short itemId);

	virtual int getAttackDamage();
};
