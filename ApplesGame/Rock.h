#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constans.h"


namespace ApplesGame 
{
	struct Game;
	struct GameStatePlayingData;

	struct Rock
	{
		//Rocks Data
		Position2D rocksPosition;
		sf::Sprite sprite;
	};
	
	void InitRock(Rock& rock, const Game& game, GameStatePlayingData& data);
	void DrawRock(Rock& rock, sf::RenderWindow& window);
	Rectangle GetRockCollider(const Rock& rock);
	void SetRockPosition(Rock& rock, const Position2D& position);

}
