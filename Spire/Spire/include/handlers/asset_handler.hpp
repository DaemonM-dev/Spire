#ifndef ASSET_HANDLER_HPP
#define ASSET_HANDLER_HPP
#include <raylib.h>
#include <vector>
#include <iostream>
#include "../utility/asset_id.hpp"
#include "../globals/globals.hpp"

class AssetHandler
{
public:

	AssetHandler();

	uint8_t TOTAL_ASSETS = 0;
	uint8_t loadCount = 0;
	bool assetsLoaded = false;
	std::vector<AssetID> assetId;
	std::vector<Texture2D> textures;

	const Texture2D& getTexture(const std::string itemName);

	void loadAllAssets();
	void unloadAllAssets();

	bool areAssetsLoaded();

private:
	void initializeAllAssetIds();
	void addAssetId(const std::string itemName, const char* itemFP);
	void loadAsset(const std::string itemName);
	void unloadAsset(const std::string itemName);
};
#endif