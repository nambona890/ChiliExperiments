#pragma once
#include "Image.h"
#include <unordered_map>

class ImageResources
{
public:
	std::unordered_map<std::string,std::shared_ptr<Image>> images;
	ImageResources();
	std::shared_ptr<Image> GetImage(std::string& img);
	void AddImage(const char* filePath, std::string imgName);
};