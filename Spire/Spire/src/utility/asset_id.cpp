#include "../utility/asset_id.hpp"

AssetID::AssetID(const std::string itemName, const char* itemFilePath) :
	name(itemName), filePath(itemFilePath){
}
