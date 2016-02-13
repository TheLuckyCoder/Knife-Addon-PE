#include <stdlib.h>
#include <string>
#include <memory>
#include <jni.h>
#include <substrate.h>

#include "mcpe/locale/I18n.h"
#include "mcpe/world/item/Item.h"
#include "items/Knifes.h"

#define LOG_TAG "Knife-Mod"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))


void (*_Item$initItems)();
void Item$initItems()
{
	Item::mItems[1800] = new WoodKnife(1800 - 0x100);
	Item::mItems[1801] = new StoneKnife(1801 - 0x100);
	Item::mItems[1802] = new IronKnife(1802 - 0x100);
	Item::mItems[1803] = new GoldKnife(1803 - 0x100);
	Item::mItems[1804] = new DiamondKnife(1804 - 0x100);
	
	_Item$initItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() 
{
	_Item$initCreativeItems();

	Item::addCreativeItem(1800, 0);
	Item::addCreativeItem(1801, 0);
	Item::addCreativeItem(1802, 0);
	Item::addCreativeItem(1803, 0);
	Item::addCreativeItem(1804, 0);
}

/*void (*_SurvivalInventoryScreen$_updateCraftableItems)(SurvivalInventoryScreen*);
void SurvivalInventoryScreen$_updateCraftableItems(SurvivalInventoryScreen* screen)
{
	_SurvivalInventoryScreen$_updateCraftableItems(screen);

	static bool registered = false;
	if(registered)
		return;
	//Knifes
	Recipes::getInstance()->addShapedRecipe(ItemInstance(1820, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[5], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(1821, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[4], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(1822, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[256], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(1823, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[266], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(1824, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[264], 'm'),Recipes::Type(Item::mItems[280], 's')});
	//Upgrade
	Recipes::getInstance()->addShapedRecipe(ItemInstance(268, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[5], 'm'),Recipes::Type(Item::mItems[1820], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(272, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[4], 'm'),Recipes::Type(Item::mItems[1821], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(267, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[256], 'm'),Recipes::Type(Item::mItems[1822], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(283, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[266], 'm'),Recipes::Type(Item::mItems[1823], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(276, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[264], 'm'),Recipes::Type(Item::mItems[1824], 's')});
	
	registered = true;
}*/

std::string (*_I18n$get)(std::string const&, std::vector<std::string> const&);
std::string I18n$get(std::string const& key, std::vector<std::string> const& a) 
{
	if(key == "item.woodKnife.name") return "Wooden Knife";
	if(key == "item.stoneKnife.name") return "Stone Knife";
	if(key == "item.ironKnife.name") return "Iron Knife";
	if(key == "item.goldKnife.name") return "Gold Knife";
	if(key == "item.diamondKnife.name") return "Diamond Knife";
	return _I18n$get(key, a);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	//MSHookFunction((void*) &SurvivalInventoryScreen::_updateCraftableItems, (void*) &SurvivalInventoryScreen$_updateCraftableItems, (void**) &_SurvivalInventoryScreen$_updateCraftableItems);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

	return JNI_VERSION_1_2;
}
