#pragma once
#include <SFML/Graphics.hpp>
#include "Constans.h"
#include "UI.h"

namespace ApplesGame
{
	struct Game;
	struct GameStatePlayingData;
	struct MenuItem;

	

	struct GameStateGameOverData
	{
		float timeSinceGameOver = 0.f;
		
		sf::Text gameOverText;
		sf::Text hintText;
		sf::Font font;

		sf::RectangleShape background;				
		
	};	

	void InitGameStateGameOverEnd(GameStateGameOverData& data, Game& game);
	void DrawGameStateGameOver(GameStateGameOverData& data, GameStatePlayingData& dataPlaying, Game& game, sf::RenderWindow& window);
	void ShutdownGameStateGameOver(GameStateGameOverData& data, Game& game);
	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event);
	void UpdateGameStateGameOver(GameStateGameOverData& data, Game& game, float deltaTime);
}