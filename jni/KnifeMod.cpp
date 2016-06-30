#include <jni.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include <substrate.h>

#include "mcpe/locale/I18n.h"
#include "mcpe/world/item/Item.h"

#include "items/WoodKnife.h"
#include "items/StoneKnife.h"
#include "items/IronKnife.h"
#include "items/GoldKnife.h"
#include "items/DiamondKnife.h"

#define LOG_TAG "Knife-Mod"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

void (*_Item$initItems)();
void Item$initItems()
{
	new WoodKnife(470);
	new StoneKnife(471);
	new IronKnife(472);
	new GoldKnife(473);
	new DiamondKnife(474);
	
	_Item$initItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() 
{
	_Item$initCreativeItems();

	for(itemId = 470; itemId <=474; itemId++)
		Item::addCreativeItem(itemId, 0);
}

std::string (*_I18n$get)(const std::string&, std::vector<std::string>&);
std::string I18n$get(const std::string &key, const std::vector<std::string> &a) 
{
	if(key == "item.knifeWood.name") return "Wooden Knife";
	if(key == "item.knifeStone.name") return "Stone Knife";
	if(key == "item.knifeIron.name") return "Iron Knife";
	if(key == "item.knifeGold.name") return "Gold Knife";
	if(key == "item.knifeDiamond.name") return "Diamond Knife";
	
	return _I18n$get(key, a);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	
	return JNI_VERSION_1_2;
}
