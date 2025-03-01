#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	struct Game;
	
	struct Vector2Df
	{
		float x = 0.f;
		float y = 0.f;

		struct Vector2DfHash 
		{
			size_t operator()(const Vector2Df& v) const noexcept
			{
				// Custom hash function combining x and y values
				return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1);
			}
		};
	};
		
	struct Vector2D 
	{
		int x=0;
		int y=0;

		// Define hash function for Vector2D
		struct Vector2DHash 
		{
			size_t operator()(const Vector2D& v) const noexcept
			{
				// Custom hash function combining x and y values
				return std::hash<int>()(v.x) ^ std::hash<int>()(v.y) << 1;
			}
		};
	};
	bool operator== (const Vector2D& lhs, const Vector2D& rhs);

	typedef Vector2Df Position2D;

	//operator for Vector2Df
	bool operator==(const Vector2Df& lhs, const Vector2Df& rhs);
	
	//Need for +vectors
	Vector2Df operator+(const Vector2Df& lhs, const Vector2Df& rhs);
	Vector2Df operator-(const Vector2Df& lhs, const Vector2Df& rhs);

	struct Rectangle
	{
		Position2D position;
		Vector2Df size;
	};

	struct Cicle
	{
		Position2D position;
		float radius;
	};
	
	//Variation collide
	bool DoShapeCollide(const Rectangle& rect1, const Rectangle& rect2);
	bool DoShapeCollide(const Cicle& cicle1, const Cicle& cicle2);
	bool DoShapeCollide(const Rectangle& rect, const Cicle& cicle);
		
	Position2D GetRandomPositionRectangle(const Rectangle& rectangle);

	//My function
	Position2D GetPositionRectangle(const Rectangle& rectangle);
		
	void SetSpriteSiize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float orignY);
		
	sf::Vector2f GetItemOriginSprite(const sf::Sprite& sprite, const Vector2D& relativePosition);
	
	sf::Vector2f GetItemOrigin(const sf::Text& text, const sf::Vector2f& relativePosition);	

}

