#include "../handlers/asset_handler.hpp"

AssetHandler::AssetHandler(){
	initializeAllAssetIds();
	assetId.reserve(TOTAL_ASSETS);
	textures.reserve(TOTAL_ASSETS);
	loadAsset("default");
}

const Texture2D& AssetHandler::getTextureRef(const std::string& itemName) const{
	const uint8_t LENGTH = assetId.size();
	for (uint8_t i = 0; i < LENGTH; i++) {
		if (itemName == assetId[i].name) {
			return textures[i];
		}
	}
	return textures[0];
}

void AssetHandler::loadAllAssets()
{
	if (!assetsLoaded) {
		if (loadCount < TOTAL_ASSETS) {
			loadAsset(assetId[loadCount].name);
		}
		else {
			assetsLoaded = true;
		}
	}
}
void AssetHandler::unloadAllAssets(){
	uint8_t length = textures.size();
	for (uint8_t i = 0; i < length; i++) {
		unloadAsset(assetId[i].name);
	}
}
bool AssetHandler::areAssetsLoaded(){
	return assetsLoaded;
}

void AssetHandler::initializeAllAssetIds(){
	addAssetId("default", "resources/default/default.jpeg");
	addAssetId("citadel", "resources/environment/citadel.png");
	addAssetId("cloud1", "resources/environment/cloud1.png");
	addAssetId("cloud2", "resources/environment/cloud2.png");
	addAssetId("cloud3", "resources/environment/cloud3.png");
	addAssetId("sunset", "resources/environment/sunset.png");
	addAssetId("rat", "resources/npc/rat.png");
	addAssetId("player", "resources/player/player.png");
}
void AssetHandler::addAssetId(const std::string& itemName, const char* itemFP){
	assetId.emplace_back(itemName, itemFP);
	TOTAL_ASSETS++;
}
void AssetHandler::loadAsset(const std::string& itemName){
	uint8_t length = assetId.size();
	for (uint8_t i = 0; i < length; i++) {
		if (itemName == assetId[i].name) {
			textures.emplace_back(LoadTexture(assetId[i].filePath));
			loadCount++;
			return;
		}
	}
	textures.emplace_back(LoadTexture(assetId[0].filePath));
	loadCount++;
}
void AssetHandler::unloadAsset(const std::string& itemName){
	uint8_t length = assetId.size();
	for (uint8_t i = 0; i < length; i++) {
		if (itemName == assetId[i].name) {
			UnloadTexture(textures[i]);
			return;
		}
	}
}
