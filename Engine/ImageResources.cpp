#include "ImageResources.h"

ImageResources::ImageResources()
{
	AddImage("munch1.png", "muncher1");
	AddImage("munch2.png", "muncher2");
	AddImage("buzz.png", "buzz");
}

Image* ImageResources::GetImage(std::string img)
{
	auto it = std::find(imageNames.begin(), imageNames.end(), img);
	if (it == imageNames.end())
	{
		return nullptr;
	}
	return &images[it - imageNames.begin()];
}

void ImageResources::AddImage(const char* filePath, std::string imgName)
{
	images.emplace_back(Image(filePath));
	imageNames.emplace_back(imgName);
}
