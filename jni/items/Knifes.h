#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/ItemInstance.h"

class WoodKnife : public Item
{
public:
	WoodKnife(short itemId);

public:
    WoodKnife(std::string);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

class StoneKnife : public Item
{
public:
	StoneKnife(short itemId);

public:
    StoneKnife(std::string);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

class IronKnife : public Item
{
public:
	IronKnife(short itemId);

public:
    IronKnife(std::string);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

class GoldKnife : public Item
{
public:
	GoldKnife(short itemId);

public:
    GoldKnife(std::string);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

class DiamondKnife : public Item
{
public:
	DiamondKnife(short itemId);

public:
    DiamondKnife(std::string);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
