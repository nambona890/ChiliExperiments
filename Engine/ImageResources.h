#pragma once
#include "Image.h"
#include <unordered_map>

class ImageResources
{
public:
	std::unordered_map<std::string,std::shared_ptr<Image>> images;
	ImageResources();
	std::shared_ptr<Image> GetImage(std::string& img);
	std::shared_ptr<Image> AddImage(const char* filePath, std::string imgName);
};