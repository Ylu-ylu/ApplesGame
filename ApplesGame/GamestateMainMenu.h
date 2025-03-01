#pragma once
#include <SFML/Graphics.hpp>
#include"MainMenu.h"


namespace ApplesGame
{
	struct Game;
		
	struct MenuItem;
	struct GameStateMainMenuData
	{
		sf::Font font;

		MenuItem startGameItem;
		MenuItem optionsItem;
		MenuItem optionsInfiniteApplesItem;
		MenuItem optionsWithAccelerationItem;
		MenuItem exitGameItem;
		MenuItem recordsItem;
		MenuItem yesItem;
		MenuItem noItem;
		Menu menu;
		
	};
	void InitGameStatetMainMenu(GameStateMainMenuData& data, Game& game);
	void ShutDownGameStateMainMenu(GameStateMainMenuData& data, Game& game);
	void HandleGameStateMainMenuWindowEvent(GameStateMainMenuData& data, Game& game, const sf::Event& event);
	void UpdateGameStateMainMenu(GameStateMainMenuData& data, Game& game, float deltaTime);
	void DrawGameStateMainMenu(GameStateMainMenuData& data, Game& game, sf::RenderWindow& window);

}