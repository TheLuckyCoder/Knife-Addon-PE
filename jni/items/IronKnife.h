#pragma once

#include "KnifeItem.h"

class IronKnife : public KnifeItem
{
public:
	IronKnife(short itemId);

	virtual int getAttackDamage();
};
