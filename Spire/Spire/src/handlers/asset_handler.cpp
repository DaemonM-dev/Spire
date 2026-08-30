#include "../handlers/asset_handler.hpp"

AssetHandler::AssetHandler(){
	initializeAllAssetIds();
	assetId.reserve(TOTAL_ASSETS);
	textures.reserve(TOTAL_ASSETS);
	loadAsset("default");
}

const Texture2D& AssetHandler::getTexture(const std::string itemName){
#ifndef DEBUG
	std::cout << "\nFetching asset: " << itemName << "\n";
#endif
	int length = assetId.size();
	for (int i = 0; i < length; i++) {
		if (itemName == assetId[i].name) {
#ifndef DEBUG
			std::cout << "Asset fetched: " << itemName << "\n";
#endif
			return textures[i];
		}
	}
#ifndef DEBUG
	std::cout << "Failed to fetch asset: " << itemName << "\n";
#endif
	return textures[0];
}
void AssetHandler::loadAllAssets()
{
	if (!assetsLoaded) {
		if (loadCount < TOTAL_ASSETS) {
#ifndef DEBUG
			if (loadCount == 1) { std::cout << "\nLoading Assets!\n"; }
#endif
			loadAsset(assetId[loadCount].name);
		}
		else {
#ifndef DEBUG
			std::cout << "\nFinished Loading Assets!\n";
#endif
			assetsLoaded = true;
		}
	}
}
void AssetHandler::unloadAllAssets(){
	int length = textures.size();
	for (int i = 0; i < length; i++) {
		unloadAsset(assetId[i].name);
	}
}
bool AssetHandler::areAssetsLoaded()
{
	return assetsLoaded;
}

void AssetHandler::initializeAllAssetIds(){
	addAssetId("default", "resources/default/default.jpeg");
	addAssetId("citadel", "resources/environment/citadel.png");
	addAssetId("cloud1", "resources/environment/cloud1.png");
	addAssetId("cloud2", "resources/environment/cloud2.png");
	addAssetId("cloud3", "resources/environment/cloud3.png");
	addAssetId("rat", "resources/npc/rat.png");
	addAssetId("player", "resources/player/player.png");
}
void AssetHandler::addAssetId(const std::string itemName, const char* itemFP){
	assetId.emplace_back(itemName, itemFP);
	TOTAL_ASSETS++;
}
void AssetHandler::loadAsset(const std::string itemName){
#ifndef DEBUG
	std::cout << "\nLoading asset: " << itemName << "\n";
#endif
	int length = assetId.size();
	for (int i = 0; i < length; i++) {
		if (itemName == assetId[i].name) {
			textures.emplace_back(LoadTexture(assetId[i].filePath));
			loadCount++;
#ifndef DEBUG
	std::cout << "Asset loaded: " << itemName << "\n";
#endif
			return;
		}
	}
	textures.emplace_back(LoadTexture(assetId[0].filePath));
	loadCount++;
#ifndef DEBUG
	std::cout << "Error - Could not load asset: " << itemName << "\n";
#endif
}
void AssetHandler::unloadAsset(const std::string itemName){
#ifndef DEBUG
	std::cout << "\nUnloading asset: " << itemName << "\n";
#endif
	int length = assetId.size();
	for (int i = 0; i < length; i++) {
		if (itemName == assetId[i].name) {
			UnloadTexture(textures[i]);
#ifndef DEBUG
			std::cout << "Asset unloaded: " << itemName << "\n";
#endif
			return;
		}
	}
#ifndef DEBUG
	std::cout << "Error - Could not unload asset: " << itemName << "\n";
#endif
}
