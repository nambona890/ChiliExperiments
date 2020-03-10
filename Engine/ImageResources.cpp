#include "ImageResources.h"

ImageResources::ImageResources()
{
	AddImage("munch1.png", "muncher1");
	AddImage("munch2.png", "muncher2");
	AddImage("buzz.png", "buzz");
}

std::shared_ptr<Image> ImageResources::GetImage(std::string& img)
{
	auto it = images.find(img);
	if (it == images.end())
	{
		return nullptr;
	}
	return it->second;
}

void ImageResources::AddImage(const char* filePath, std::string imgName)
{
	images.emplace(std::make_pair(imgName, std::make_shared<Image>(filePath)));
}
