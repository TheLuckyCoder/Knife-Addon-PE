#pragma once

#include "KnifeItem.h"

class GoldKnife : public KnifeItem
{
public:
	GoldKnife(short id);

	virtual int getAttackDamage();
};

