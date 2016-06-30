#pragma once

#include "KnifeItem.h"

class StoneKnife : public KnifeItem
{
public:
	StoneKnife(short itemId);

	virtual int getAttackDamage();
};
