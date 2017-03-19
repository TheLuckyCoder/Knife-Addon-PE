#include <jni.h>
#include <stdlib.h>
#include <substrate.h>

#include "minecraftpe/client/locale/I18n.h"

#include "items/WoodKnife.h"
#include "items/StoneKnife.h"
#include "items/IronKnife.h"
#include "items/GoldKnife.h"
#include "items/DiamondKnife.h"

void (*_Item$initItems)();
void Item$initItems()
{
	_Item$initItems();
	
	new WoodKnife(500);
	new StoneKnife(501);
	new IronKnife(502);
	new GoldKnife(503);
	new DiamondKnife(504);
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() 
{
	_Item$initCreativeItems();

	for (short id = 500; id <= 504; ++id)
		Item::addCreativeItem(id, 0);
}

static std::string (*_I18n$get)(const std::string&);
static std::string I18n$get(const std::string &key) 
{
	if (key == "item.woodKnife.name") return "Wooden Knife";
	if (key == "item.stoneKnife.name") return "Stone Knife";
	if (key == "item.ironKnife.name") return "Iron Knife";
	if (key == "item.goldKnife.name") return "Gold Knife";
	if (key == "item.diamondKnife.name") return "Diamond Knife";
	
	return _I18n$get(key);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	
	return JNI_VERSION_1_6;
}

