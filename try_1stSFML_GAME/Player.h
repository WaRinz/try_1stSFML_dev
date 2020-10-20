#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

class Player
{
private:
	sf::Sprite  sprite;
	sf::Texture texture;
	

	// attack & max speed
	float attackCooldown;
	float attackCooldownMax;
	
	// time
	sf::Clock animationTimer;
	
	// animations
	short animationState;
	sf::IntRect currentFrame;

	// physics -> movement speed
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float deceleration; //drag

	/*private function*/
	void initialVariables();
	void initialTexture();
	void initialSprite();
	void initialAnimations();
	void initialPhysics();

public:

	Player();
	virtual ~Player();

	// Access

	const sf::Vector2f& getPos() const;
	sf::FloatRect getBounds() const;

	// modify
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, float y);

	//move
	
	void move(const float dirX, const float dirY);
	
	/* FUNCTIONS */
	const bool canAttack();
	

	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void updateAttack();
	void update();
	void render(sf::RenderTarget&target);
	
};

