#pragma once

#include<vector>
#include<iostream>
#include<stdlib.h>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Main.hpp>

class State
{
private:
	std::vector<sf::Texture> textures;

public:
	State();
	virtual ~State();

	// virtual + void = pure virtual --> can't create any object
	virtual void update() = 0;
	virtual void render() = 0;
};

