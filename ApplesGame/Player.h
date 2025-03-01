#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constans.h"



namespace ApplesGame 
{
	struct Game;
	struct GameStatePlayingData;
		
	enum class PlayerDirection
	{
		Right,
		Up,
		Left,
		Down
	};

	struct Player
	{
		//Player Data
		Position2D playerPosition;
		float playerSpeed = iNITIAL_SPEED;
		PlayerDirection playerDirection = PlayerDirection::Right;
		sf::Sprite sprite;
		
	};

	void InitPlayer(Player& player, const Game& game, GameStatePlayingData& data);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
	void SetPlayerDirection(Player& player, PlayerDirection direction);
	Rectangle GetPlayerCollider(const Player& player);

	void SetPlayerSpeed(Player& player, float speed);
	void SetPlayerPosition(Player& player, const Position2D& position);
	void UpdatePlayer(Player& player, float deltaTime);
}
