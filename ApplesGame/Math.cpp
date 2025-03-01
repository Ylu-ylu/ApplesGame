#include "Math.h"
#include <cstdlib>



namespace ApplesGame
{
	
	Vector2Df operator+(const Vector2Df& lhs, const Vector2Df& rhs)
	{
		 Vector2Df result;
		 result.x = lhs.x + rhs.x;
		 result.y = lhs.y+ rhs.y;
		 return result;
	}

	Vector2Df  operator-(const Vector2Df& lhs, const Vector2Df& rhs)
	{
		Vector2Df result;
		result.x = lhs.x - rhs.x;
		result.y = lhs.y - rhs.y;
		return result;
	}

	bool operator==(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
	bool operator==(const Vector2Df& lhs, const Vector2Df& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
	bool DoShapeCollide(const Rectangle& rect1, const Rectangle& rect2)
	{
		return rect1.position.x < rect2.position.x + rect2.size.x &&
		rect1.position.x + rect1.size.x > rect2.position.x &&
		rect1.position.y < rect2.position.y + rect2.size.y &&
		rect1.position.y + rect1.size.y > rect2.position.y;
	}
	bool DoShapeCollide(const Cicle& cicle1, const Cicle& cicle2)
	{
		const float dx = cicle1.position.x - cicle2.position.x;
		const float dy = cicle1.position.y - cicle2.position.y;
		const float distance = sqrt(dx * dx + dy * dy);
		return distance < cicle1.radius + cicle2.radius;
	}

	bool DoShapeCollide(const Rectangle& rect, const Cicle& cicle)
	{
		const float dx = cicle.position.x - std::max(rect.position.x, std::min(cicle.position.x, rect.position.x + rect.size.x));
		const float dy = cicle.position.y - std::max(rect.position.y, std::min(cicle.position.y, rect.position.y + rect.size.y));
		return (dx * dx + dy * dy) < (cicle.radius * cicle.radius);
	}
	
	Position2D GetRandomPositionRectangle(const Rectangle& rectangle)
	{
		Position2D result;
		result.x = rand() / (float)RAND_MAX * rectangle.size.x + rectangle.position.x;
		result.y = rand() / (float)RAND_MAX * rectangle.size.y + rectangle.position.y;
		return result;
	}

	Position2D GetPositionRectangle(const Rectangle& rectangle)
	{
		Position2D result;
		result.x = rectangle.size.x;
		result.y = rectangle.size.y;
		
		return result;
	}
		
	void SetSpriteSiize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect  spriteRect=sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float orignY)
	{
		sf::FloatRect  spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, orignY * spriteRect.height);
	}
		
	sf::Vector2f GetItemOriginSprite(const sf::Sprite& sprite, const  Vector2D& relativePosition)
{
		const sf::Vector2u textureSize = sprite.getTexture()->getSize();

		return { static_cast<float>(relativePosition.x) * textureSize.x,
		 static_cast<float>(relativePosition.y) * textureSize.y };
}

	sf::Vector2f GetItemOrigin(const sf::Text& text, const sf::Vector2f& relativePosition)
	{
		sf::FloatRect textSize = text.getLocalBounds();
		return {
			(textSize.left + textSize.width) * relativePosition.x,
			(textSize.top + textSize.height) * relativePosition.y,
		};
	}	
}

