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
	imgR = new ImageResources;
	player = new Player(imgR);
	enemies.emplace_back(Enemy(imgR, { 200,-50 }));
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
			gfx.PutPixel(x, y, Color(128, 0, 128, 128));
		}
	}
	player->Logic(wnd,globalTimer,bullets);


	for (Bullet& b : bullets)
	{
		b.Logic(wnd, globalTimer);
		b.Draw(gfx);
	}

	std::remove_if(bullets.begin(), bullets.end(), [](Bullet b) {return !b.GetDestroy(); });

	for (Enemy& e : enemies)
	{
		e.Logic(wnd, globalTimer, bullets);
		e.Draw(gfx);
	}

	std::remove_if(enemies.begin(), enemies.end(), [](Enemy e) {return !e.GetDestroy(); });

	player->Draw(gfx);

	imgR->GetImage(std::string("gui"))->draw(0, 0, gfx);

	globalTimer++;
}
