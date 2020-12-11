#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>


#include<map>
#include<string>
#include<sstream>
#include<vector>

// PLAYER PART
#include"Player.h"
#include"Bullet.h"

// ENEMIES PART
#include"Enemies.h"
#include"RedEnemy.h"
#include"BlueEnemy.h"

// ITEM PART
#include"Potion.h"
#include"Shield.h"


class Game
{
private:
	/* WINDOW */
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	sf::Clock dtClock;
	sf::Time time = sf::seconds(1.f);
	float dt;

	// ICON
	sf::Image icon;
	// GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameOverText;
	
	// SOUND hit
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::SoundBuffer bufflol;
	sf::Sound haha;

	// BG music
	sf::Music music;

	// BG
	sf::Texture bgTexture;
	sf::Sprite background;

	// --- MENU ----
		// Menu BG
		sf::Texture menuTexture;
		sf::RectangleShape menuSprite;
		bool isGameStart;
		
		// Menu Button
		sf::Vector2i mouseScreen;
		sf::Vector2i mouseWindow;
		sf::Vector2f mouseView;


	// S Y S T E M
	unsigned points;


	/* PILOT */
	Player* player;

	sf::RectangleShape playerHpBar;			//MAX
	sf::RectangleShape playerHpBarBack;		//DECREASE

	/* ENEMIES --- FLAPPY */
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemies*> enemies;

	/* ENEMIES --- RED BIRD */
	float RedspawnTimer;
	float RedspawnTimerMax;
	std::vector<RedEnemy*> redenemy;

	/* ENEMIES --- BLUE BIRD */
	float BluespawnTimer;
	float BluespawnTimerMax;
	std::vector<BlueEnemy*> blueenemy;
	

	/* POTION --- HEALTH */
	float PospawnTimer;
	float PospawnTimerMax;
	std::vector<Potion*> potion;

	/* SHIELD --- PROTECT */
	float ShspawnTimer;
	float ShspawnTimerMax;
	std::vector<Shield*> shield;



	void initialWindow();
	void initialTextures();

	void initialGUI();
	void initialBG();
	void initialBGSound();
	void initialBGMenu();

	void initialSystem();

	// OBJECT
	void initialPlayer();
	void initialEnemies();
	void initialRedEnemy();
	void initialBlueEnemy();
	void initialPotion();
	void initialShield();

	void initialSound();
	void initialHaha();

	// CLEAN ALL
	void LobThangMod();

	


public:
	Game();
	virtual ~Game();
	
	/*FUNCTIONS*/

	

	void checkStart();

	void run();

	void updatePollEvents();
	void updateInput();

	// UPDATE OBJECT
	void updateBullets();
	void updateEnemies();
	void updateRedEnemy();
	void updateBlueEnemy();
	void updatePotion();
	void updateShield();

	void updateCombat();

	void updateCollision();
	void updateGUI();

	void updateBG();// no need
	void updateBGSound();


	// --- MENU ---
	//void updateMousePos();



	void updateDt();

	// import player
	void renderPlayer();

	// import bg textures
	void renderBG();

	// import font text & health bar
	void renderGUI();

	// import menu
	void renderBGMenu();


	void update(); // Game update(ME); = update player(You)
	
			/*	this->updatePollEvents();
		this->updateInput();

		this->player->update();// updatePlayer

		this->updateBullets();	*/


	void render();
};

