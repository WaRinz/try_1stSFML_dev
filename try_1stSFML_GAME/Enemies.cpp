#include "Enemies.h"

void Enemies::initialShape()
{
	this->shape.setRadius(rand() % 10 + 20);
	this->shape.setPointCount(rand() % 10 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Enemies::initialVariables()
{
	this->type		= 0;
	this->hpmax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->point		= 100;
}


Enemies::Enemies(float posX, float posY)
{
	this->initialShape();
	this->initialVariables();
	this->shape.setPosition(posX, posY);
}

Enemies::~Enemies()
{

}



// function
void Enemies::update()
{

}

void Enemies::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
