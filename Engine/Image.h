#pragma once
#include "Graphics.h"
#include "Colors.h"
#include <vector>
#include "ChiliException.h"
#include "Vector.h"
#include "Transform.h"

class Image
{
private:
	int width = 0, height = 0;
	std::vector<unsigned char> image;
public:
	class Exception : public ChiliException
	{
	public:
		using ChiliException::ChiliException;
		virtual std::wstring GetFullMessage() const override { return GetNote() + L"\nAt: " + GetLocation(); }
		virtual std::wstring GetExceptionType() const override { return L"Image Exception"; }
	};
	int getWidth(), getHeight();
	Image(const char* filename);
	Image(const unsigned int w, const unsigned int h);
	Color getPixel(const int x, const int y);
	void setPixel(const int x, const int y, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		setPixel(x, y, { a,r,g,b });
	}
	void setPixel(const int x, const int y, const unsigned char r, const unsigned char g, const unsigned char b)
	{
		setPixel(x, y, { 255,r,g,b });
	}
	void setPixel(const int x, const int y, const Color c);
	
	void draw(const Vec2 v, Graphics& gfx)
	{
		draw((int)v.x, (int)v.y, gfx);
	}

	void draw(const int x, const int y, Graphics& gfx);

	void drawTransform(const Vec2 v, const Transform t, Graphics& gfx)
	{
		drawTransform((int)v.x, (int)v.y, t, gfx);
	}

	void drawTransform(const int x, const int y, Transform t, Graphics& gfx);
};