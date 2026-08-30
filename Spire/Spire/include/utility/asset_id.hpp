#ifndef ASSET_ID_HPP
#define ASSET_ID_HPP
#include <string>
class AssetID
{
public:

	AssetID(const std::string itemName, const char* itemFilePath);

	const std::string name;
	const char* filePath;
};
#endif