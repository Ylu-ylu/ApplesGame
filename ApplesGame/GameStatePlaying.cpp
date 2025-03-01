#include "GameStatePlaying.h"
#include <assert.h>
#include "UI.h"
#include "Game.h"

namespace ApplesGame
{	
	void InitGameStatePlaying(GameStatePlayingData& data,Game& game)
	{
		assert(data.playerTexture.loadFromFile(RESOURCES_PATH + "Player.png"));
		assert(data.appleTexture.loadFromFile(RESOURCES_PATH + "Apple.png"));
		assert(data.rockTexture.loadFromFile(RESOURCES_PATH + "Rock.png"));

		assert(data.eatAppleSoundBuffer.loadFromFile(RESOURCES_PATH + "AppleEat.wav"));
		assert(data.gameOverSoundBuffer.loadFromFile(RESOURCES_PATH + "Death.wav"));
		assert(data.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Regular.ttf"));

		data.apples.resize(NUM_APPLES);
		data.rocks.resize(NUM_ROCKS);

		// Init game objects
		game.screenRect = { 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT };

		InitPlayer(data.player, game, data);

		//for appleGrid
		ClearAppleGrid(data.applesGrid);

		data.numApples = NUM_APPLES + rand() / (float)RAND_MAX;
	
		data.numEatenApples = 0;
		// Init apples
		//for (int i = 0; i < NUM_APPLES; ++i)
		for (auto& elementApples : data.apples)
		{
			InitApple(elementApples, game, data);
			ResetAppleState(elementApples);
			AddAppleToGrid(data.applesGrid, elementApples);
		}

		// Init rocks
		//for (int i = 0; i < NUM_ROCKS; ++i)
		for (auto& elementRocks : data.rocks)
		{
			InitRock(elementRocks, game, data);
			SetRockPosition(elementRocks, GetRandomPositionRectangle(game.screenRect));
		}

		//Inicialisation UI
		InitUI(game.uiState, data.font);

		//Init background
		data.background.setSize(sf::Vector2f(game.screenRect.size.x, game.screenRect.size.y));
		data.background.setFillColor(sf::Color::Black);
		data.background.setOrigin(0.f, 0.f);

		//Init Sound
		data.appleEatSound.setBuffer(data.eatAppleSoundBuffer);
		data.gameOverSound.setBuffer(data.gameOverSoundBuffer);				
	}

	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game)
	{
		// We dont need to free resources here, because they will be freed automatically
	}

	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				PushGameState(game, GameStateType::PauseMenu, false);
			}
		}
	}

	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float deltaTime)
	{
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			data.player.playerDirection = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			data.player.playerDirection = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			data.player.playerDirection = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			data.player.playerDirection = PlayerDirection::Down;
		}
		//Update Player State
		UpdatePlayer(data.player, deltaTime);

		ApplesSet collidingApples;
		
		//New find player collision in gridcells
		if (FindPlayerCollisionWhithApples(data.player.playerPosition, data.applesGrid, collidingApples))
		{
			for (Apple* apple : collidingApples)
			{
				data.appleEatSound.play();
				if (game.optionsMask & (GamStateMask::IsWithAcceleration))
				{
					data.player.playerSpeed += ACCERATION;
				}
									
				if (game.optionsMask & (GamStateMask::IsInfininiteApples))
				{
					//Move apples to random position
					ResetAppleState(*apple);
					AddAppleToGrid(data.applesGrid, *apple);
					data.numEatenApples++;
				}
				else 
				{
					!(game.optionsMask & (GamStateMask::IsInfininiteApples));
					MarkAppleAsEaten(*apple);
					RemoveAppleFromGrid(data.applesGrid, *apple);
					data.numEatenApples++;					
				}								
			}					
		}
				bool isGameFinished = (data.numEatenApples == data.apples.size())
				&& !(game.optionsMask & GamStateMask::IsInfininiteApples);

			// Find player collisions with rocks
			const char* PLAYER_NAME = "Player";

			for (auto& elementRocks : data.rocks)
			{
				if (isGameFinished || DoShapeCollide(GetPlayerCollider(data.player), GetRockCollider(elementRocks)))
				{
					// Activate Table Records
					game.recordsTable[PLAYER_NAME] = std::max(game.recordsTable[PLAYER_NAME], data.numEatenApples);

					PushGameState(game, GameStateType::GameOver, false);
					data.gameOverSound.play();
				}
				
			}
			// Check screen borders collision
			
			if (isGameFinished || !DoShapeCollide(GetPlayerCollider(data.player), game.screenRect))
			{											
				// Activate Table Records
				game.recordsTable[PLAYER_NAME] = std::max(game.recordsTable[PLAYER_NAME], data.numEatenApples);

				PushGameState(game, GameStateType::GameOver, false);
				data.gameOverSound.play();
			}
									
			game.uiState.scoreText.setString("Apples eaten:" + std::to_string(data.numEatenApples));		
	}
		
	void DrawGameStatePlaying (GameStatePlayingData& data, Game& game, sf::RenderWindow& window)
	{
		//Draw Player
		DrawPlayer(data.player, window);

		//Draw Apples
		for (auto& elementApples : data.apples)
		{
			DrawApple(elementApples, window);
		}
		//Draw Rocks
		for (auto& elementRocks : data.rocks)
		{
			DrawRock(elementRocks, window);
		}
		
		game.uiState.scoreText.setOrigin(GetItemOrigin(game.uiState.scoreText, { 0.f,0.f }));
		game.uiState.scoreText.setPosition(10.f, 10.f);
		window.draw(game.uiState.scoreText);

		sf::Vector2f viewSize = window.getView().getSize();
		data.inputHintText.setPosition(viewSize.x - 10.f, 10.f);
		window.draw(data.inputHintText);
	}
}