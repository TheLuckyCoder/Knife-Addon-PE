#pragma once

#include "KnifeItem.h"

class DiamondKnife : public KnifeItem
{
public:
	DiamondKnife(short itemId);

	virtual int getAttackDamage();
};
