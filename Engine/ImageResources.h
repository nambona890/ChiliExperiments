#pragma once
#include "Image.h"

class ImageResources
{
public:
	std::vector<Image> images;
	std::vector<std::string> imageNames;
	ImageResources();
	Image* GetImage(std::string img);
	void AddImage(const char* filePath, std::string imgName);
};