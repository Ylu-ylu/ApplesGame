#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "UI.h"
#include "Constans.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <functional>

using namespace std;

namespace ApplesGame
{
	struct Game;
	struct GameStatePlayingData;
	struct Player;
	
	struct Apple
	{
		Position2D applesPosition;
		sf::Sprite sprite;

		bool isEaten = false;		
	};
	struct ApplePointerHash 
	{
		std::size_t operator()(const Apple* apple) const 
		{
			return Vector2Df::Vector2DfHash{}(apple->applesPosition);
		}
	};

	struct ApplePointerEqual 
	{
		bool operator()(const Apple* lhs, const Apple* rhs) const 
		{
			return lhs->applesPosition == rhs->applesPosition;			
		}
	};
	
	using ApplesSet = std::unordered_set<Apple*, ApplePointerHash, ApplePointerEqual>;
	//using ApplesSet = std::unordered_set<Apple*>;

	struct ApplesGrid
	{
		std::unordered_map<Vector2D, ApplesSet, Vector2D::Vector2DHash> cells;
		std::unordered_multimap<Apple*, Vector2D>	appleCells;
	};
		
	void InitApple(Apple& apple, const Game & game, GameStatePlayingData& data);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
	Cicle GetAppleCollide(const Apple& apples);
	void SetApplePosition(Apple& apple, const Position2D& position);

	void ResetAppleState(Apple& apples);///??????
	void MarkAppleAsEaten(Apple& apples);
	//For Apples Cells
	void ClearAppleGrid(ApplesGrid& appleGrid);
	void AddAppleToGrid(ApplesGrid& appleGrid, Apple& apples);
	void RemoveAppleFromGrid(ApplesGrid& applesGrid, Apple& apple);
	bool FindPlayerCollisionWhithApples(const Vector2Df & playerPosition, const ApplesGrid& grid_in, ApplesSet&result);

}

