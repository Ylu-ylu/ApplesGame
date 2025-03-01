#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>


namespace ApplesGame
{
	struct Game;
	
	struct GameStateRecordsData
	{
		//Resource
		sf::Font font;

		sf::Text titleText;
		std::vector <sf::Text> tableTexts;
		sf::Text hintText;

	};

	void InitStateGameStateRecords(GameStateRecordsData& data, Game& game);
	void HandleGameStateRecordsWindowEvent(GameStateRecordsData& data, sf::Event& event, Game& game);

	void DrawGameStateRecords(GameStateRecordsData& data, Game& game, sf::RenderWindow& window);

	void ShutdownGameStateRecords(GameStateRecordsData& data, Game& game);

	void UpdateGameStateRecords(GameStateRecordsData& data, Game& game, float deltaTime);
	

}

