#pragma once

#include "KnifeItem.h"

class DiamondKnife : public KnifeItem
{
public:
	DiamondKnife(short id);

	virtual int getAttackDamage();
};

