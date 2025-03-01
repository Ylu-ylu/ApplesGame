#include "MenuSetting.h"
#include "Game.h"

namespace ApplesGame
{
	void SetGameMenuSettings(GameState& gameState, sf::RenderWindow& window)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			gameState.gameStateMask |= (GameState::GamStateMask::IsInfininiteApples | GameState::GamStateMask::IsWithAcceleration);//for mask

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))

		{
			gameState.gameStateMask |= GameState::GamStateMask::IsInfininiteApples;//for mask
			gameState.gameStateMask &= ~(GameState::GamStateMask::IsWithAcceleration);//for mask

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))

		{
			gameState.gameStateMask |= GameState::GamStateMask::IsWithAcceleration;//for mask
			gameState.gameStateMask &= ~(GameState::GamStateMask::IsInfininiteApples);//for mask


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))

		{
			gameState.gameStateMask &= ~(GameState::GamStateMask::IsInfininiteApples | GameState::GamStateMask::IsWithAcceleration);//for mask


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			gameState.gameStateMask |= GameState::GamStateMask::IsGameRestarting;//for mask
		}


	}
}