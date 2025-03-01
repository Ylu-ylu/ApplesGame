#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Math.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constans.h"
#include <vector>
#include <algorithm>
#include "UI.h"

namespace ApplesGame 
{
	struct GameStateGameOverData;
	struct GameRecordsData;
	struct GameStatePlayingData;
	struct GameStateExitDialogData;
			
		enum  GamStateMask
		{
			IsInfininiteApples = 1<<0, 
			IsWithAcceleration= 1 << 1,

			IsGameOvered = 1 << 2,
			IsGameRestarting= 1<< 3,
			IsGameWinned = 1<< 4,
						
			Default= IsInfininiteApples| IsWithAcceleration,
			Empty=0,				
		};
				
		enum class GameStateType
		{
			None = 0,
			MainMenu,
			Playing,
			GameOver,
			Records,
			PauseMenu,
		};

		struct GameState
		{
			GameStateType gametype = GameStateType::None;
			void* data = nullptr;
			bool isExclusivelyVisible = false;
		};

		enum class GameStateChangeType
		{
			None,
			Push,
			Pop,
			Switch
		};

		struct Game
		{
			std::vector <GameState> gameStateStack;
			GameStateChangeType  gameStateChangeType = GameStateChangeType::None;
			GameStateType  pendingGameStateType = GameStateType::None;
			bool pendingGameStateIsExclusivelyVisible = false;

			GamStateMask optionsMask = GamStateMask::Default;
					
			float timeSinceGameFinish = 0.f;

			//Record Table
			std::unordered_map <std::string, int> recordsTable;

			int MAX_RECORDS_TABLE_SIZE = 6;
			
			short GameMask = 0;//bitmap 0000000000000000*/

			Rectangle screenRect;
			UIState uiState;
						
			//Game Type
			bool isgameFinished = false;
			bool isGameStarting = false;
		};

	void InitGame(Game& game);
	void HandleWindowEvents(Game& game, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);
	
	void UpdateGameState(Game& game, GameState& state, float deltaTime);

	bool UpdateGame(Game& game, float deltaTime);

	void InitGameState(Game& game, GameState& state);

	void ShutdownGameState(Game& game, GameState& state);

	void ShutdownGame(Game& game);

	// Add new game state on top of the stack
	void PushGameState(Game& game, GameStateType stateType, bool isExclusivelyVisible);

	// Remove current game state from the stack
	void PopGameState(Game& game);

	// Remove all game states from the stack and add new one
	void SwitchGameState(Game& game, GameStateType newState);

	void HandleWindowEventGameState(Game& game, GameState& state, sf::Event& event);
	void DrawGameState(Game& game, GameState& state, sf::RenderWindow& window);
}

