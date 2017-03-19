#pragma once

#include "KnifeItem.h"

class WoodKnife : public KnifeItem
{
public:
	WoodKnife(short id);

	virtual int getAttackDamage();
};

