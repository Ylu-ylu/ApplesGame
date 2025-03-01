#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Player.h"
#include "Rock.h"
#include "Constans.h"
#include "Apple.h"
#include "GameStateGameOver.h"

namespace ApplesGame
{
	struct Game;
	struct Apple;
	struct ApplesGrid;
	struct UIState;
	struct Rock;
	struct GameStateGameOverData;

	struct GameStatePlayingData
	{
		//Game Object
		sf::RectangleShape background;
		sf::Sound appleEatSound;
		sf::Sound gameOverSound;

		//Recourse
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;

		sf::SoundBuffer eatAppleSoundBuffer;
		sf::SoundBuffer gameOverSoundBuffer;

		sf::Font font;
		
		sf::Text inputHintText;

		// Game data
		Player player;
		std::vector < Apple> apples;//change massive to vector
		float deltaTime;

		//Rock rocks[NUM_ROCKS];
		std::vector <Rock> rocks;//change massive to vector

		ApplesGrid applesGrid;
		int numApples = 0;
		int numEatenApples = 0;

	};

	void InitGameStatePlaying(GameStatePlayingData& data, Game& game);
	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game);
	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event);
	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float deltaTime);
	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window);
}