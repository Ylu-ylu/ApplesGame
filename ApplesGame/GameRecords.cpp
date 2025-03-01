#include "GameRecords.h"
#include <vector>
#include <assert.h>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;


namespace ApplesGame
{
	void InitGameStateRecords(GameRecordsData& data, GameState& gameState)
	{
		assert(gameState.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Regular.ttf"));


		data.tableTexts.reserve(gameState.MAX_RECORDS_TABLE_SIZE);

		map<int, string> sortedRecordTable;
		for (const auto& item : gameState.recordsTable)
		{
			sortedRecordTable[item.second] = item.first;
		}

		auto it = sortedRecordTable.begin();
		for (int i = 0; i < gameState.MAX_RECORDS_TABLE_SIZE && it != sortedRecordTable.end(); ++i, ++it)
		{
			data.tableTexts.emplace_back();//create object in end vector
			sf::Text& text= data.tableTexts.back();

			stringstream sstream;
			sstream << i + 1 << "." << it->second << ":" << it->first;
			text.setString(sstream.str());
			text.setFont(gameState.font);
			text.setFillColor(sf::Color::White);
			text.setCharacterSize(25);


		}


	}

	
	void DrawGameStateRecords(GameRecordsData& data, GameState& gameState, sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		vector<sf::Text> textList;
		textList.reserve(data.tableTexts.size());
		for (auto& text : data.tableTexts)
		{
			textList.push_back(text);

		}
		
	}

	



}


