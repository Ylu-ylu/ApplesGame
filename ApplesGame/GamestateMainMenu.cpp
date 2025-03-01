#include "GameStateMainMenu.h"
#include "Game.h"
#include <assert.h>
#include"UI.h"

namespace ApplesGame
{
	void InitGameStatetMainMenu(GameStateMainMenuData& data, Game& game)
	{
		assert(data.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		InitGameStateMainMenuUI(data, game);

		InitMenuItem(data.menu.rootItem);
		SelectMenuItem(data.menu, &data.startGameItem);
	}

	void ShutDownGameStateMainMenu(GameStateMainMenuData& data, Game& game)
	{
		// No need to do anything here

	}
	void HandleGameStateMainMenuWindowEvent(GameStateMainMenuData& data, Game& game, const sf::Event& event)
	{
		if (!data.menu.selectedItem)
		{
			return;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				CollapseSelectedItem(data.menu);
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (data.menu.selectedItem == &data.startGameItem)
				{
					SwitchGameState(game, GameStateType::Playing);
				}
				else if (data.menu.selectedItem == &data.optionsItem)
				{
					ExpandSelectedItem(data.menu);
				}
				else if (data.menu.selectedItem == &data.optionsInfiniteApplesItem)
				{
				    game.optionsMask = (GamStateMask)(game.optionsMask^GamStateMask::IsInfininiteApples);
				}
				else if (data.menu.selectedItem == &data.optionsWithAccelerationItem)
				{
					game.optionsMask = (GamStateMask)(game.optionsMask ^ GamStateMask::IsWithAcceleration);
				}
				else if (data.menu.selectedItem == &data.recordsItem)
				{
					PushGameState(game, GameStateType::Records, true);
				}
				else if (data.menu.selectedItem == &data.exitGameItem)
				{
					ExpandSelectedItem(data.menu);
				}
				else if (data.menu.selectedItem == &data.yesItem)
				{
					SwitchGameState(game, GameStateType::None);
				}
				else if (data.menu.selectedItem == &data.noItem)
				{
					CollapseSelectedItem(data.menu);
				}
				else
				{
					ExpandSelectedItem(data.menu);
				}
				

			}
			Orientation orientation = data.menu.selectedItem->parent->childrenOrientation;
			if (orientation  == Orientation::Vertical && event.key.code == sf::Keyboard::Up ||
				orientation  == Orientation::Horizontal && event.key.code == sf::Keyboard::Left)
			{
				SelectPreviousMenuItem(data.menu);
			}
			else if (orientation  == Orientation::Vertical && event.key.code == sf::Keyboard::Down ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Right)
			{
				SelectNextMenuItem(data.menu);
			}
		}
	}

	void UpdateGameStateMainMenu(GameStateMainMenuData& data, Game& game, float deltaTime)
	{
		bool isInfiniteApples = ((game.optionsMask) & (GamStateMask::IsInfininiteApples)) != GamStateMask::Empty;
		data.optionsInfiniteApplesItem.mainMenu.setString("Infinite Apples: " + std::string(isInfiniteApples ? "On" : "Off"));

		bool isWithAcceleration = ((game.optionsMask) & GamStateMask::IsWithAcceleration) != GamStateMask::Empty;
		data.optionsWithAccelerationItem.mainMenu.setString("With Acceleration: " + std::string(isWithAcceleration ? "On" : "Off"));
	}

	void DrawGameStateMainMenu(GameStateMainMenuData& data, Game& game, sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = (sf::Vector2f)window.getSize();

		sf::Text* hintText = &GetCurrentMenuContext(data.menu)->mainMenuhintText;
		hintText->setOrigin(GetItemOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(viewSize.x / 2.f, 150.f);
		window.draw(*hintText);

		
		DrawMenu(game.uiState, data.menu, window, viewSize / 2.f, { 0.5f, 0.f });
	}

}
