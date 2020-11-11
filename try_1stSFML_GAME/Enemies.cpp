#include "Enemies.h"

void Enemies::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type		= 0;
	this->hpmax		= static_cast<int>(this->pointCount);
	this->hp		= this->hpmax;
	this->damage	= this->pointCount;
	this->points		= this->pointCount;

	this->speed		= static_cast<float>(this->pointCount / 2);
}

void Enemies::initialShape()
{
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 300 + 1, rand() % 30 + 1, 400)); //R, G, B color
}

Enemies::Enemies(float posX, float posY)
{
	
	this->initialVariables();
	this->initialShape();
	this->shape.setPosition(posX, posY);
}

Enemies::~Enemies()
{

}

const sf::FloatRect Enemies::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemies::getPoints() const
{
	return this->points;
}

const int& Enemies::getDamage() const
{
	return this->damage;
}



// function
void Enemies::update()
{
	this->shape.move(-this->speed, 0.f);
}

void Enemies::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
