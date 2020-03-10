#include "Image.h"
#include "lodepng.h"
#include <string>

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

Image::Image(const char* filename)
{
	std::vector<unsigned char> png;
	unsigned w, h;
	unsigned error = lodepng::load_file(png, filename);
	if (!error) error = lodepng::decode(image, w, h, png);
	if (!error)
	{
		width = w; height = h;
	}
	else
	{
		std::string ex;
		ex.append("Decoder Error ");
		ex.append(std::to_string(error));
		ex.append(": ");
		ex.append(lodepng_error_text(error));
		throw Exception(_CRT_WIDE(__FILE__), __LINE__, { ex.begin(),ex.end() });
		image.clear();
	}
}

Image::Image(const unsigned int w, const unsigned int h)
{
	for(int i=0;i<w*h*4;i++)
		image.emplace_back(0);
	width = w;
	height = h;
}

Color Image::getPixel(const int x, const int y)
{
	if (x < width && y < height && x >= 0 && y >= 0)
	{
		const unsigned int pos = (x + (y * width))*4;
		return { image[pos + 3],image[pos],image[pos + 1],image[pos + 2] };
	}
	else
	{
		return { 0,0,0,0 };
	}
}

void Image::setPixel(const int x, const int y, const Color c)
{
	if (x < width && y < height && x >= 0 && y >= 0)
	{
		const unsigned int pos = (x + (y * width))*4;
		image[pos] = c.GetR();
		image[pos + 1] = c.GetG();
		image[pos + 2] = c.GetB();
		image[pos + 3] = c.GetA();
	}
}

void Image::draw(const int x, const int y, Graphics& gfx, const float a)
{
	if (x > -width && y > -height && x < gfx.ScreenWidth + width && y < gfx.ScreenHeight + height)
	{
		unsigned int pos = 0;

		for (int i = y; i < y + height; i++)
		{
			if (i < gfx.ScreenHeight && i >= 0)
			{
				for (int j = x; j < x + width; j++)
				{
					if (j < gfx.ScreenWidth && j >= 0)
					{
						if (pos < image.size())
						{
							Color c = { image[pos + 3], image[pos], image[pos + 1], image[pos + 2] };
							if (a < 1.0f)
								c.SetA(unsigned char(std::round(std::fmaxf(0.0f, std::fminf(c.GetA() * a, 255.0f)))));
							if (c.GetA() > 0)
							{
								gfx.PutPixel(j, i, c);
							}
						}
					}
					pos += 4;
				}
			}
			else
			{
				pos += 4 * width;
			}
		}
	}
}

void Image::drawTransform(const int x, const int y, Transform t, Graphics& gfx, const float a)
{
	Vec2 tlV = t.Forward({ 0,0 });
	Vec2 trV = t.Forward({ (float)width,0 });
	Vec2 blV = t.Forward({ 0,(float)height });
	Vec2 brV = t.Forward({ (float)width,(float)height });
	float minX = std::fminf(tlV.x, std::fminf(trV.x, std::fminf(blV.x, brV.x)));
	float minY = std::fminf(tlV.y, std::fminf(trV.y, std::fminf(blV.y, brV.y)));
	float maxX = std::fmaxf(tlV.x, std::fmaxf(trV.x, std::fmaxf(blV.x, brV.x)));
	float maxY = std::fmaxf(tlV.y, std::fmaxf(trV.y, std::fmaxf(blV.y, brV.y)));
	float angle = t.getAngle();
	Vec2 scale = t.getScale();
	t.Invert();
	if (x > -(maxX - minX) && y > -(maxY - minY) && x < gfx.ScreenWidth + (maxX - minX) && y < gfx.ScreenHeight + (maxY - minY))
	{

		for (int i = (int)minY; i < (int)maxY; i++)
		{
			if (i+y < gfx.ScreenHeight && i+y >= 0)
			{
				for (int j = (int)minX; j < (int)maxX; j++)
				{
					if (j+x < gfx.ScreenWidth && j+x >= 0)
					{
						Vec2 prime = t.Forward({ (float)j,(float)i });
						if (prime.x >= 0.0f && prime.y >= 0.0f && prime.x < width && prime.y < width)
						{
							Color c = getPixel((int)prime.x, (int)prime.y);
							if (c.GetA() > 0)
							{
								if (a < 1.0f)
									c.SetA(unsigned char(std::round(std::fmaxf(0.0f,std::fminf(c.GetA() * a, 255.0f)))));
								gfx.PutPixel(j + x, i + y, c);
							}
						}
					}
				}
			}
		}
	}
}
