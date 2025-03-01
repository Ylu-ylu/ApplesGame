#pragma once
#include <string>




namespace ApplesGame
{
	const std::string RESOURCES_PATH = "Resources/";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float iNITIAL_SPEED = 100.f;//Pixel per second
	const float PLAYER_SIZE = 30.f;
	const float ACCERATION = 20.f;// Pixel per second per second
	const int NUM_APPLES = 20;
	const float APPLE_SIZE = 30.f;
	const float PAUSE = 5.f;
	const int NUM_ROCKS = 5;
	const float ROCK_SIZE = 35.f;
	//int MAX_RECORDS_TABLE_SIZE = 6;

	//Apple Grid
	const unsigned APPLES_GRID_CELLS_HORIZONTAL = unsigned (SCREEN_WIDTH / (APPLE_SIZE * 4));
	const unsigned APPLES_GRID_CELLS_VERTICAL = unsigned (SCREEN_HEIGHT / (APPLE_SIZE * 4));

	extern const char* PLAYER_NAME;//Needto defie this constant in SPP;
}
