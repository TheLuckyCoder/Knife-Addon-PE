#pragma once

#include "KnifeItem.h"

class GoldKnife : public KnifeItem
{
public:
	GoldKnife(short itemId);

	virtual int getAttackDamage();
};
