#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "UI.h"


namespace ApplesGame
{

	struct Game;
	struct GameStatePlayingData;
	struct UIState;

	struct GameStateExitDialogData
	{
		
		sf::Font font;

		sf::RectangleShape background;
		//sf::Text hintText;
		
		
	};

	void InitGameStateExitDialog(GameStateExitDialogData& data, Game& game);
	void ShutdownGameStateExitDialog(GameStateExitDialogData& data, Game& game);
	void HandleGameStateExitDialogWindowEvent(GameStateExitDialogData& data, Game& game, const sf::Event& event);
	void UpdateGameStateExitDialog(GameStateExitDialogData& data, Game& game, float deltaTime);
	void DrawGameStateExitDialog(UIState& uiState,GameStateExitDialogData& data, Game& game, GameStatePlayingData& dataPlaying, sf::RenderWindow& window);
}













