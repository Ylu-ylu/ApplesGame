#include "GameStateGameOver.h"
#include "Game.h"
#include <iostream>
#include <assert.h>
#include <string>


namespace ApplesGame
{ 
	void InitGameStateGameOverEnd(GameStateGameOverData& data, Game& game)
	{
		assert(data.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		data.timeSinceGameOver = 0.f;

		//Background
		sf::Color backgroundColour = sf::Color::Black;
		backgroundColour.a = 100;//alfa opacity
		data.background.setFillColor(backgroundColour);
				
		InitUI(game.uiState, data.font);	
		
	}

	void DrawGameStateGameOver(GameStateGameOverData& data, GameStatePlayingData& dataPlaying, Game& game, sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		game.uiState.gameOverText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f);
		window.draw(game.uiState.gameOverText);

		data.background.setSize(viewSize);
		data.background.setOrigin( 0.f, 0.f);
		window.draw(data.background);
		
		game.uiState.hintText.setPosition(viewSize.x / 2.f, viewSize.y - 10.f);
		window.draw(game.uiState.hintText);
		
	}

	void ShutdownGameStateGameOver(GameStateGameOverData& data, Game& game)
	{
		// We dont need to free resources here, because they will be freed automatically
	}

	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				SwitchGameState(game, GameStateType::Playing);
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				SwitchGameState(game, GameStateType::MainMenu);
			}
		}
	}

	void UpdateGameStateGameOver(GameStateGameOverData& data, Game& game, float deltaTime)
	{
		data.timeSinceGameOver += deltaTime;	
					
	}
}