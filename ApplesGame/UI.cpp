#include "UI.h"
#include <string>
#include "Game.h"
#include "GameStateGameOver.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include "MainMenu.h"
#include "GamestateMainMenu.h"
#include "GameStatePlaying.h"
#include "Math.h"
#include "GameStateExitDialog.h"


namespace ApplesGame
{
	
	void InitUI(UIState& uiState, const sf::Font& font)
	{
		//ScoreText
		uiState.scoreText.setFont(font);
		uiState.scoreText.setCharacterSize(20);
		uiState.scoreText.setFillColor(sf::Color::Yellow);
		
		//Text init
		uiState.controlsHintText.setFont(font);
		uiState.controlsHintText.setCharacterSize(20);
		uiState.controlsHintText.setFillColor(sf::Color::Yellow);
		uiState.controlsHintText.setPosition(SCREEN_WIDTH - uiState.controlsHintText.getGlobalBounds().width - 300.f, 10.f);
		uiState.controlsHintText.setString("Use arrows to move, ESC to exit");

		//Game Over Text		
		uiState.gameOverText.setFont(font);
		uiState.gameOverText.setCharacterSize(64);
		uiState.gameOverText.setStyle(sf::Text::Bold);
		uiState.gameOverText.setFillColor(sf::Color::Red);
		uiState.gameOverText.setString("GAME OVER");
		uiState.gameOverText.setOrigin(GetItemOrigin(uiState.gameOverText, { 0.5f, 0.5f }));

		uiState.hintText.setFont(font);
		uiState.hintText.setCharacterSize(24);
		uiState.hintText.setFillColor(sf::Color::White);
		uiState.hintText.setString("Press Space to restart\n Press Esc to exit");
		uiState.hintText.setOrigin(GetItemOrigin(uiState.hintText, { 0.5f, 1.f }));

		//Game Over score text
		uiState.gameOverScoreText.setFont(font);
		uiState.gameOverScoreText.setCharacterSize(25);
		uiState.gameOverScoreText.setFillColor(sf::Color::Green);
		uiState.gameOverScoreText.setPosition(SCREEN_WIDTH / 2.f - uiState.controlsHintText.getGlobalBounds().width / 4.f, SCREEN_HEIGHT / 2.f + 50.f);

		//Init Game Restart text
		uiState.restartText.setFont(font);
		uiState.restartText.setCharacterSize(20);
		uiState.restartText.setFillColor(sf::Color::Yellow);
		
		//For MainMenu
		uiState.mainMenu.setFont(font);
		uiState.mainMenu.setCharacterSize(30);

		uiState.mainMenuhintText.setFont(font);
		uiState.mainMenuhintText.setCharacterSize(30);

		//for GameStatePlaying
		uiState.inputHintText.setFont(font);
		uiState.inputHintText.setCharacterSize(24);
		uiState.inputHintText.setFillColor(sf::Color::White);
		uiState.inputHintText.setString("Use arrow keys to move, ESC to pause");
		uiState.inputHintText.setOrigin(GetItemOrigin(uiState.inputHintText, { 1.f, 0.f }));	

		//For PauseMenu
			//TitleText
		uiState.pauseMenuText.setString("Pause");
		uiState.pauseMenuText.setFont(font);
		uiState.pauseMenuText.setCharacterSize(48);
		uiState.pauseMenuText.setFillColor(sf::Color::Red);

		uiState.pauseMenuText.setOrigin(GetItemOrigin(uiState.pauseMenuText, { 0.5f, 0.5f }));

	}
		
	//For Draw MainMenu:choose Colour
	void SelectMenuItemUI(UIState& uiState, Menu& menu, MenuItem* item)
	{
		if (menu.selectedItem)
		{
			menu.selectedItem->mainMenu.setFillColor(menu.selectedItem->deselectedColor);
		}

		menu.selectedItem = item;

		if (menu.selectedItem)
		{
			menu.selectedItem->mainMenu.setFillColor(menu.selectedItem->selectedColor);
		}
	}

	void InitGameStateMainMenuUI(GameStateMainMenuData& data, Game& game)
	{
		data.menu.rootItem.mainMenuhintText.setString("Apple Game");
		data.menu.rootItem.mainMenuhintText.setFont(data.font);
		data.menu.rootItem.mainMenuhintText.setCharacterSize(48);
		data.menu.rootItem.mainMenuhintText.setFillColor(sf::Color::Red);
		data.menu.rootItem.childrenOrientation = Orientation::Vertical;
		data.menu.rootItem.childrenAlignment = Alignment::Center;
		data.menu.rootItem.childrenSpacing = 15.f;

		data.menu.rootItem.children.push_back(&data.startGameItem);
		data.menu.rootItem.children.push_back(&data.optionsItem);
		data.menu.rootItem.children.push_back(&data.exitGameItem);
		data.menu.rootItem.children.push_back(&data.recordsItem);

		data.startGameItem.mainMenu.setString("Start Game");
		data.startGameItem.mainMenu.setFont(data.font);
		data.startGameItem.mainMenu.setCharacterSize(24);

		data.optionsItem.mainMenu.setString("Options");
		data.optionsItem.mainMenu.setFont(data.font);
		data.optionsItem.mainMenu.setCharacterSize(24);
		data.optionsItem.mainMenuhintText.setString("Options");
		data.optionsItem.mainMenuhintText.setFont(data.font);
		data.optionsItem.mainMenuhintText.setCharacterSize(48);
		data.optionsItem.mainMenuhintText.setFillColor(sf::Color::Red);
		data.optionsItem.childrenOrientation = Orientation::Vertical;
		data.optionsItem.childrenAlignment = Alignment::Center;
		data.optionsItem.childrenSpacing = 15.f;

		
		data.optionsItem.children.push_back(&data.optionsInfiniteApplesItem);
		data.optionsItem.children.push_back(&data.optionsWithAccelerationItem);

		data.optionsInfiniteApplesItem.mainMenu.setString("Infinite Apples: On/Off");
		data.optionsInfiniteApplesItem.mainMenu.setFont(data.font);
		data.optionsInfiniteApplesItem.mainMenu.setCharacterSize(24);

		data.optionsWithAccelerationItem.mainMenu.setString("With Acceleration: On/Off");
		data.optionsWithAccelerationItem.mainMenu.setFont(data.font);
		data.optionsWithAccelerationItem.mainMenu.setCharacterSize(24);

		data.recordsItem.mainMenu.setString("Records");
		data.recordsItem.mainMenu.setFont(data.font);
		data.recordsItem.mainMenu.setCharacterSize(24);

		data.exitGameItem.mainMenu.setString("Exit Game");
		data.exitGameItem.mainMenu.setFont(data.font);
		data.exitGameItem.mainMenu.setCharacterSize(24);
		data.exitGameItem.mainMenuhintText.setString("Are you sure?");
		data.exitGameItem.mainMenuhintText.setFont(data.font);
		data.exitGameItem.mainMenuhintText.setCharacterSize(48);
		data.exitGameItem.mainMenuhintText.setFillColor(sf::Color::Red);
		data.exitGameItem.childrenOrientation = Orientation::Horizontal;
		data.exitGameItem.childrenAlignment = Alignment::Center;
		data.exitGameItem.childrenSpacing = 15.f;
		
		data.exitGameItem.children.push_back(&data.yesItem);
		data.exitGameItem.children.push_back(&data.noItem);

		data.yesItem.mainMenu.setString("Yes");
		data.yesItem.mainMenu.setFont(data.font);
		data.yesItem.mainMenu.setCharacterSize(24);

		data.noItem.mainMenu.setString("No");
		data.noItem.mainMenu.setFont(data.font);
		data.noItem.mainMenu.setCharacterSize(24);
	}
	
	void DrawItemsList2(sf::RenderWindow& window, const std::vector<sf::Text*>& items, float spacing, Orientation orientation, Alignment alignment, const sf::Vector2f& position, const sf::Vector2f& origin)
	{
				
		sf::FloatRect totalRect;
		// Calculate total height/width of all texts
		for (auto it = items.begin(); it != items.end(); ++it)
		{
			sf::FloatRect itemRect = (*it)->getGlobalBounds();

			if (orientation == Orientation::Horizontal)
			{
				totalRect.width += itemRect.width + (it != items.end() - 1 ? spacing : 0.f);
				totalRect.height = std::max(totalRect.height, itemRect.height);
			}
			else
			{
				totalRect.width = std::max(totalRect.width, itemRect.width);
				totalRect.height += itemRect.height + (it != items.end() - 1 ? spacing : 0.f);
			}
		}

		totalRect.left = position.x - origin.x * totalRect.width;
		totalRect.top = position.y - origin.y * totalRect.height;
		sf::Vector2f currentPos = { totalRect.left, totalRect.top };

		for (auto it = items.begin(); it != items.end(); ++it)
		{
			sf::FloatRect itemRect = (*it)->getGlobalBounds();
			sf::Vector2f itemOrigin;

			if (orientation == Orientation::Horizontal)
			{
				itemOrigin.y = alignment == Alignment::Left ? 0.f : alignment == Alignment::Center ? 0.5f : 1.f;
				itemOrigin.x = 0.f;
				currentPos.y = totalRect.top + itemOrigin.y * totalRect.height;
			}
			else
			{
				itemOrigin.y = 0.f;
				itemOrigin.x = alignment == Alignment::Left ? 0.f : alignment == Alignment::Center ? 0.5f : 1.f;
				currentPos.x = totalRect.left + itemOrigin.x * totalRect.width;
			}

			(*it)->setOrigin(GetItemOrigin(**it, itemOrigin));
			(*it)->setPosition(currentPos);
			window.draw(**it);

			if (orientation == Orientation::Horizontal)
			{
				currentPos.x += itemRect.width + spacing;
			}
			else
			{
				currentPos.y += itemRect.height + spacing;
			}
		}
	}
}