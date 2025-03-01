// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constans.h"
#include "Game.h"
#include "GameRecords.h"
#include "GameStateGameOver.h"
#include "GameStatePlaying.h"
#include "Player.h"
#include <cstdlib>


using namespace ApplesGame;

int main()
 {
	//struct Game;
	unsigned int seed = (unsigned int)time(nullptr);
	srand(seed);
	
	//Init window
	sf::RenderWindow window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEIGHT), "ApplesGame!");

	// We now use too much memory for stack, so we need to allocate it on heap
	ApplesGame::Game* game = new ApplesGame::Game();
	InitGame(*game);

	//Init Time
	sf::Clock gameClock;
	sf::Time lastTime = gameClock.getElapsedTime();
	//float lastTime = gameClock.getElapsedTime();
		
	while (window.isOpen())
	{
		HandleWindowEvents(*game, window);

		if (!window.isOpen())
		{
			break;
		}
		
		//Reduce framerate to not spawn CPU and GPU
		sf::sleep(sf::milliseconds(16));
	
		//Calculate time delta
		sf::Time  currentTime = gameClock.getElapsedTime();
		float deltaTime = currentTime.asSeconds() - lastTime.asSeconds();
		lastTime = currentTime;

		if (UpdateGame(*game, deltaTime))
		{
			// Draw everything here
		// Clear the window first
			window.clear();

			DrawGame(*game, window);

			// End the current frame, display window contents on screen
			window.display();
		}
		else
		{
			window.close();
		}
						
	}
	ShutdownGame(*game);
	delete game;
	game = nullptr;
		
	return 0;
}
