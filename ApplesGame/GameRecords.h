#pragma once
#include "Game.h"

using namespace std;

namespace ApplesGame
{
	struct GameState;

	struct UIState;

	struct GameRecordsData
	{
		vector<sf::Text> tableTexts;
		
	};

	void InitGameStateRecords(GameRecordsData& data, GameState& gameState);
	void DrawGameStateRecords(GameRecordsData& data, GameState& gameState, sf::RenderWindow& window);







}

