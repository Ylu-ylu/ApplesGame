#include "Player.h"
#include "Game.h"
#include "GameStatePlaying.h"

namespace ApplesGame 
{
	void InitPlayer(Player& player, const Game& game, GameStatePlayingData& data)
	{
		//Init Player State
		player.playerPosition = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.playerSpeed = iNITIAL_SPEED;
		player.playerDirection = PlayerDirection::Right;

		//Init Player Sprite
		player.sprite.setTexture(data.playerTexture);
		SetSpriteSiize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);

	}
	void SetPlayerDirection(Player& player, PlayerDirection playerDirection)
	{
		player.playerDirection = playerDirection;
	}
	Rectangle GetPlayerCollider(const Player& player)
	{
		return { { player.playerPosition.x - PLAYER_SIZE / 2.f, player.playerPosition.y - PLAYER_SIZE / 2.f },
					{ PLAYER_SIZE, PLAYER_SIZE } };
	}
	void SetPlayerSpeed(Player& player, float speed)
	{
		player.playerSpeed = speed;
	}
	void SetPlayerPosition(Player& player, const Position2D& position)
	{
		player.playerPosition = position;
	}
	void UpdatePlayer(Player& player, float deltaTime)
	{		
		switch (player.playerDirection)
		{
		case PlayerDirection::Right:
		{
			player.playerPosition.x += player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			player.playerPosition.y -= player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			player.playerPosition.x -= player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			player.playerPosition.y += player.playerSpeed * deltaTime;
			break;
		}
		}
	}
	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.playerPosition.x, player.playerPosition.y);
		window.draw(player.sprite);

		//Rotation Player sprite according direction
		if (player.playerDirection == PlayerDirection::Left)
		{
			SetSpriteSiize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation(0.f);
		}
		else
		{
			SetSpriteSiize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation((float)player.playerDirection * -90.f);
		}
	}
}




	
	

	

	

	

	

	

	




