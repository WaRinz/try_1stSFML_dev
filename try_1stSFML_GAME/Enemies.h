#ifndef ENEMIES_H
#define ENEMIES_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


class Enemies
{
private :
	sf::CircleShape shape;

	int type;
	int hp;
	int hpmax;
	int damage;
	int point;

	void initialShape();
	void initialVariables();
	
public :
	
	Enemies(float posX, float posY);

	virtual ~Enemies();


	// functions
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !ENEMIES_H