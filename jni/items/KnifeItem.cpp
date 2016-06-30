#include "KnifeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"

KnifeItem::KnifeItem(short itemId, const std::string &name, int type, int damage) : Item((name + "Knife"), itemId - 256)
{
	Item::mItems[itemId] = this;
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("knife", type);
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

void KnifeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

void KnifeItem::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	item->hurtAndBreak(2, mob);
}
