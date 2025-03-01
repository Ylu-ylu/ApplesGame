#include "GameStateExitDialog.h"
#include "Game.h"
#include <assert.h>
#include "GameStatePlaying.h"



namespace ApplesGame
{
	void InitGameStateExitDialog(GameStateExitDialogData& data, Game& game)
	{
		assert(data.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Regular.ttf"));
		
		data.background.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
		InitGameStateExitDialogUI(game.uiState, data, game);
	}

	void ShutdownGameStateExitDialog(GameStateExitDialogData& data, Game& game)
	{
		// We dont need to free resources here, because they will be freed automatically

	}

	void HandleGameStateExitDialogWindowEvent(GameStateExitDialogData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				PopGameState(game);
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				SwitchGameState(game, GameStateType::MainMenu);
			}
		}
	}

	void UpdateGameStateExitDialog(GameStateExitDialogData& data, Game& game, float deltaTime)
	{


	}

	void DrawGameStateExitDialog(UIState& uiState, GameStateExitDialogData& data, Game& game, GameStatePlayingData& dataPlaying, sf::RenderWindow& window)
	{
		sf::Vector2f windowSize = (sf::Vector2f)window.getSize();

		data.background.setSize(windowSize);
		uiState.exitDialoghintText.setPosition(windowSize / 2.f);
		
		DrawGameStateExitDialogUI(game.uiState, window, game,dataPlaying);
		
	}




}
