#pragma once
#include <SFML/Graphics.hpp>
class Collisionable {
public:
	virtual sf::FloatRect getBounds() const = 0;
	bool Collision(Collisionable& objeto) const;
};

/*Esta clase permite que dos objetos "colisionen" 
o interactuen entre si.*/