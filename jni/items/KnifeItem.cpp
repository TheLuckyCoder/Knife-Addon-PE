#include "KnifeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

KnifeItem::KnifeItem(short id, const std::string &name, short damage) : Item((name + "Knife"), id - 256)
{
	Item::mItems[itemId] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("knife_" + name, 0);
	setMaxStackSize(1);
	setMaxDamage(damage);
	setHandEquipped();
}

bool KnifeItem::canDestroyInCreative() const
{
	return false;
}

int KnifeItem::getEnchantSlot() const
{
	return 16;
}

int KnifeItem::getEnchantValue() const
{
	return 1;
}

void KnifeItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool KnifeItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
	return true;
}

