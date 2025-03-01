#include "Rock.h"
#include "Game.h"
#include "GameStatePlaying.h"

namespace ApplesGame
{
	void InitRock(Rock& rock, const Game& game, GameStatePlayingData& data)
	{
		//Initial Rocks
		rock.sprite.setTexture(data.rockTexture);
		SetSpriteSiize(rock.sprite, ROCK_SIZE, ROCK_SIZE);
		SetSpriteRelativeOrigin(rock.sprite, 0.5f, 0.5f);
	}

	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(rock.rocksPosition.x, rock.rocksPosition.y);
		window.draw(rock.sprite);
	}

	Rectangle GetRockCollider(const Rock& rock)
	{
		return { { rock.rocksPosition.x - ROCK_SIZE / 2.f, rock.rocksPosition.y - ROCK_SIZE / 2.f },
					{ ROCK_SIZE, ROCK_SIZE } }; 
	}

	void SetRockPosition(Rock& rock, const Position2D& position)
	{
		rock.rocksPosition = position;
	}
}


