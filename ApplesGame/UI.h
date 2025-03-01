#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constans.h"
#include <sstream> 



namespace ApplesGame
{
	struct Game;
	struct GameStatePlayingData;


	enum class Orientation 
	{ 
		Horizontal, 
		Vertical
	};
	enum class Alignment 
	{
		Left,
		Center,
		Right
	};
	
	struct MenuItem;
	struct Menu; 
	struct GameStateMainMenuData;
	struct GameStatePlayingData;
	struct GameStateGameOverData;
	struct GameStateExitDialogData;

	struct UIState
	{		
		sf::Text scoreText;
		sf::Text controlsHintText;
		sf::Text gameOverText;
		sf::Text hintText;
		sf::Text gameOverScoreText;
		sf::Text restartText;
		sf::Text gameModeChoosingText;
		sf::Text gameModeChoosingTextGameOver;

		//for PauseMenu
		sf::Text pauseMenuText;

		//for MainMenu
		sf::Text mainMenu;
		sf::Text mainMenuhintText; // Visible when child item is selected
		std::vector <sf::Text*> texts;

		//for GameStatePlaying
		sf::Text inputHintText;
		sf::Font font;
	};
	
	void InitUI(UIState& uiState, const sf::Font& font);
	
	//Draw map RecordTable	
	void DrawItemsList2(sf::RenderWindow& window, const std::vector<sf::Text*>& items, float spacing, Orientation orientation, Alignment alignment, const sf::Vector2f& position, const sf::Vector2f& origin);
	//Draw MainMenu
	void SelectMenuItemUI(UIState& uiState,Menu& menu, MenuItem* item);
	//Draw GameStateMainMenu
	void InitGameStateMainMenuUI(GameStateMainMenuData& data, Game& game);
}
