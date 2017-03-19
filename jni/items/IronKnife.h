#pragma once

#include "KnifeItem.h"

class IronKnife : public KnifeItem
{
public:
	IronKnife(short id);

	virtual int getAttackDamage();
};

