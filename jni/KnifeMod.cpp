#include <stdlib.h>
#include <string>
#include <memory>
#include <jni.h>
#include <substrate.h>

#include "mcpe/locale/I18n.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/recipes/Recipes.h"

#include "items/WoodKnife.h"
#include "items/StoneKnife.h"
#include "items/IronKnife.h"
#include "items/GoldKnife.h"
#include "items/DiamondKnife.h"
#include "items/EmeraldKnife.h"

#define LOG_TAG "Knife-Mod"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))


void (*_Item$initItems)();
void Item$initItems()
{
	Item::mItems[470] = new WoodKnife(470 - 0x100);
	Item::mItems[471] = new StoneKnife(471 - 0x100);
	Item::mItems[472] = new IronKnife(472 - 0x100);
	Item::mItems[473] = new GoldKnife(473 - 0x100);
	Item::mItems[474] = new DiamondKnife(474 - 0x100);
	Item::mItems[475] = new EmeraldKnife(475 - 0x100);
	
	_Item$initItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() 
{
	_Item$initCreativeItems();

	Item::addCreativeItem(470, 0);
	Item::addCreativeItem(471, 0);
	Item::addCreativeItem(472, 0);
	Item::addCreativeItem(473, 0);
	Item::addCreativeItem(474, 0);
	Item::addCreativeItem(475, 0);
}

/*void (*_SurvivalInventoryScreen$_updateCraftableItems)(SurvivalInventoryScreen*);
void SurvivalInventoryScreen$_updateCraftableItems(SurvivalInventoryScreen* screen)
{
	_SurvivalInventoryScreen$_updateCraftableItems(screen);

	static bool registered = false;
	if(registered)
		return;
	//Knifes
	Recipes::getInstance()->addShapedRecipe(ItemInstance(470, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[5], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(471, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[4], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(472, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[256], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(473, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[266], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(474, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[264], 'm'),Recipes::Type(Item::mItems[280], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(475, 1, 0), Recipes::Shape("   ", " m ", " s "), { Recipes::Type(Item::mItems[388], 'm'),Recipes::Type(Item::mItems[280], 's')});
	//Upgrade
	Recipes::getInstance()->addShapedRecipe(ItemInstance(268, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[5], 'm'),Recipes::Type(Item::mItems[470], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(272, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[4], 'm'),Recipes::Type(Item::mItems[471], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(267, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[256], 'm'),Recipes::Type(Item::mItems[472], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(283, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[266], 'm'),Recipes::Type(Item::mItems[473], 's')});
	Recipes::getInstance()->addShapedRecipe(ItemInstance(276, 1, 0), Recipes::Shape("m", "s"), { Recipes::Type(Item::mItems[264], 'm'),Recipes::Type(Item::mItems[474], 's')});

	registered = true;
}*/

std::string (*_I18n$get)(std::string const&, std::vector<std::string> const&);
std::string I18n$get(std::string const& key, std::vector<std::string> const& a) 
{
	if(key == "item.knifeWood.name") return "Wooden Knife";
	if(key == "item.knifeStone.name") return "Stone Knife";
	if(key == "item.knifeIron.name") return "Iron Knife";
	if(key == "item.knifeGold.name") return "Gold Knife";
	if(key == "item.knifeDiamond.name") return "Diamond Knife";
	if(key == "item.knifeEmerald.name") return "Emerald Knife";
	return _I18n$get(key, a);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	return JNI_VERSION_1_2;
}
