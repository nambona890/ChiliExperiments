/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Transform.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	muncher = new Image("munchie.png");
	cumulativeBuf = new Image(gfx.ScreenWidth, gfx.ScreenHeight);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	for (int x = 0; x < gfx.ScreenWidth; x++)
	{
		for (int y = 0; y < gfx.ScreenHeight; y++)
		{
			gfx.PutPixel(x, y, 0, 128, 128);
		}
	}

	//for (int i = 0; i < 20; i++)
	//{
		angle += 0.02f;

		Vec2 pos = { 0,150 };
		pos.Rotate(angle);
		Vec2 munchPos = pos + Vec2{ float(gfx.ScreenWidth / 2) - float(muncher->getWidth() / 2), float(gfx.ScreenHeight / 2) - float(muncher->getHeight() / 2) };
		Vec2 linePos = pos + Vec2{ float(gfx.ScreenWidth / 2),float(gfx.ScreenHeight / 2) };
		Transform t;
		t.Rotate(angle);
		t.Scale({ 8.5f,8.5f });
		t.center = { float(muncher->getWidth()) / 2.0f,float(muncher->getHeight()) / 2.0f };
		muncher->drawTransform(munchPos, t, gfx);

		gfx.DrawLine({ float(gfx.ScreenWidth / 2),float(gfx.ScreenHeight / 2) }, linePos, { 255,255,255,255 });
		//cumulativeBuf->setPixel((int)munchPos.x, (int)munchPos.y, 255, 255, 255, 255);
	//}
	//cumulativeBuf->draw(0, 0, gfx);
}
