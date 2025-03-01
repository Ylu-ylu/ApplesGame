#include "Apple.h"
#include "Game.h"
#include <string>
#include "GameStatePlaying.h"
#include <cstdlib>
#include <assert.h>
#include "Player.h"


namespace ApplesGame
{
	
	void InitApple(Apple& apple, const Game& game, GameStatePlayingData& data)
	{
		//Initial Apple
		apple.sprite.setTexture(data.appleTexture);
		SetSpriteSiize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
		
	}
	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		if (apple.isEaten)
		{
			return;
		}
		
		apple.sprite.setPosition(apple.applesPosition.x, apple.applesPosition.y);
		window.draw(apple.sprite);
	}
	Cicle GetAppleCollide(const Apple& apples)
	{
		return { apples.applesPosition, APPLE_SIZE / 2.f };
	}
	
	void SetApplePosition(Apple& apple, const Position2D& position)
	{
		apple.applesPosition = position;	
	}
	void ResetAppleState(Apple& apples)
	{
		// init apple state
		apples.applesPosition.x = (float)(rand() % SCREEN_WIDTH);
		apples.applesPosition.y = (float)(rand() % SCREEN_HEIGHT);
		apples.isEaten = false;		
	}
	void MarkAppleAsEaten(Apple& apples)
	{
		apples.isEaten = true;
	}
	void ClearAppleGrid(ApplesGrid& appleGrid)
	{
		appleGrid.appleCells.clear();
		appleGrid.cells.clear();
	}
	void AddAppleToGrid(ApplesGrid& appleGrid, Apple& apple)
	{
		// Remove the apple from its old position in the grid
		RemoveAppleFromGrid(appleGrid, apple);

		// Calculate grid cell size
		const float cellSizeX = static_cast<float>(SCREEN_WIDTH) / APPLES_GRID_CELLS_HORIZONTAL;
		const float cellSizeY = static_cast<float>(SCREEN_HEIGHT) / APPLES_GRID_CELLS_VERTICAL;
		// Debug: Print cell size
	
		// Ensure apple is within screen bounds
		if (apple.applesPosition.x < 0 || apple.applesPosition.x >= SCREEN_WIDTH ||
			apple.applesPosition.y < 0 || apple.applesPosition.y >= SCREEN_HEIGHT)
		{
			return;
		}
				
		// Calculate apple's bounding box
			
		const float halfAppleSize = APPLE_SIZE / 2.0f;
		Vector2Df appleCornerTL = { apple.applesPosition.x - halfAppleSize, apple.applesPosition.y - halfAppleSize };
		Vector2Df appleCornerBR = { apple.applesPosition.x + halfAppleSize, apple.applesPosition.y + halfAppleSize };

		// Determine grid cells the apple overlaps
		int minCellX = std::max(static_cast<int>(appleCornerTL.x / cellSizeX), 0);
		int maxCellX = std::min(static_cast<int>(appleCornerBR.x / cellSizeX),(int)(APPLES_GRID_CELLS_HORIZONTAL - 1));
		int minCellY = std::max(static_cast<int>(appleCornerTL.y / cellSizeY), 0);
		int maxCellY = std::min(static_cast<int>(appleCornerBR.y / cellSizeY),(int)(APPLES_GRID_CELLS_VERTICAL - 1));

		// Add apple to new cells
		for (int cellX = minCellX; cellX <= maxCellX; ++cellX)
		{
			for (int cellY = minCellY; cellY <= maxCellY; ++cellY)
			{
				Vector2D cellCoord = { cellX, cellY };
				appleGrid.cells[cellCoord].insert(&apple);
						
				appleGrid.appleCells.insert({ &apple, cellCoord });				
			}

		}
		
	}
	void RemoveAppleFromGrid(ApplesGrid& applesGrid, Apple& apple)
	{		
		auto range = applesGrid.appleCells.equal_range(&apple);
		for (auto it = range.first; it != range.second; ++it)
		{
			applesGrid.cells[it->second].erase(&apple);

		}
		applesGrid.appleCells.erase(range.first, range.second);				
	}
	bool FindPlayerCollisionWhithApples(const Vector2Df& playerPosition, const ApplesGrid& grid_in, ApplesSet& result)
	{
		result.clear();  // Clear the result set before starting

		
		const float cellSizeX = static_cast<float>(SCREEN_WIDTH) / APPLES_GRID_CELLS_HORIZONTAL;
		const float cellSizeY = static_cast<float>(SCREEN_HEIGHT) / APPLES_GRID_CELLS_VERTICAL;

		const float playerHalfSize = PLAYER_SIZE / 2.0f;
		const Vector2Df appleCornerTL = {playerPosition.x - playerHalfSize,playerPosition.y - playerHalfSize};
		const Vector2Df appleCornerBR = {playerPosition.x + playerHalfSize,	playerPosition.y + playerHalfSize};

		const int minCellX = std::max(static_cast<int>(appleCornerTL.x / cellSizeX), 0);
		const int maxCellX = std::min(static_cast<int>(appleCornerBR.x / cellSizeX), (int)(APPLES_GRID_CELLS_HORIZONTAL - 1));
		const int minCellY = std::max(static_cast<int>(appleCornerTL.y / cellSizeY), 0);
		const int maxCellY = std::min(static_cast<int>(appleCornerBR.y / cellSizeY), (int)(APPLES_GRID_CELLS_VERTICAL - 1));

		const float collisionDistanceSquared = (PLAYER_SIZE / 2 + APPLE_SIZE / 2);
				
		for (int x = minCellX; x <= maxCellX; ++x)
		{
			for (int y = minCellY; y <= maxCellY; ++y)
			{
				Vector2D cellCoord = { x, y };
				const auto it = grid_in.cells.find(cellCoord);
				if (it != grid_in.cells.cend())
				{

					for (Apple* apple : it->second)
					{
						const float dx = playerPosition.x - apple->applesPosition.x;
						const float dy = playerPosition.y - apple->applesPosition.y;

						const float distanceSquared = sqrt(dx * dx + dy * dy);

						if (distanceSquared < collisionDistanceSquared)
						{
							result.insert(apple);

						}
					}
				}
			}
				
		}
				
		return !result.empty();
	}
}

 