#include "ImageResources.h"

ImageResources::ImageResources()
{
	AddImage("gui.png", "gui");
	
	AddImage("bullet2.png", "bullet2");
	AddImage("bullet3.png", "bullet3");
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

std::shared_ptr<Image> ImageResources::AddImage(const char* filePath, std::string imgName)
{
	auto it = images.find(imgName);
	if (it == images.end()||it->second==nullptr)
	{
		auto tmpImage = std::make_shared<Image>(Image(filePath));
		images.emplace(std::make_pair(imgName, tmpImage));
		return tmpImage;
	}
	return it->second;

}
