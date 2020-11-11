#ifndef ENEMIES_H
#define ENEMIES_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Main.hpp>


class Enemies
{
private :

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	int type;
	int hp;
	int hpmax;
	int damage;
	int points;
	int speed;

	void initialVariables();
	void initialShape();
	
public :
	Enemies(float posX, float posY);

	virtual ~Enemies();

	// access
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	const int& getDamage() const;

	// functions


	void update();
	void render(sf::RenderTarget& target);
};

#endif // !ENEMIES_H