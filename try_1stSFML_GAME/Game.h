#pragma once
#include<map>

#include"Player.h"
#include"Bullet.h"
#include"Enemies.h"

class Game
{
private:
	/* WINDOW */
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	/* GUI */
	sf::Font font;
	sf::Text pointText;

	// BG
	sf::Texture bgTexture;
	sf::Sprite background;

	/* PILOT */
	Player* player;

	/* ENEMIES */
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemies*> enemies;

	void initialWindow();
	void initialTextures();
	void initialGUI();
	void initialBG();

	void initialPlayer();
	void initialEnemies();


public:
	Game();
	virtual ~Game();
	
	/*FUNCTIONS*/
	void run();

	void updatePollEvents();
	void updateInput();

	void updateBullets();
	void updateEnemies();

	void updateCollision();

	// import player
	void renderPlayer();

	// import bg textures
	void renderBG();
	void update(); // Game update(ME); = update player(You)
	
			/*	this->updatePollEvents();
		this->updateInput();

		this->player->update();// updatePlayer

		this->updateBullets();	*/


	void render();
};

