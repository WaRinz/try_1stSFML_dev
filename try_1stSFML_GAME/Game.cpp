#include "Game.h"
void Game::initialWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1700, 900), "63010849 Worawich Tangpojthaweeporn", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	

	// ICON
	if (!this->icon.loadFromFile("Textures/icon.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD GAME ICON" << "\n";
	}
	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
}
void Game::initialTextures()
{
	// Bullet
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");

	// Menu
	this->menuSprite.setTexture(&this->menuTexture);


}

void Game::initialGUI()  // text health bar
{
	// load font
	if (!this->font.loadFromFile("Text/Opun-Regular.ttf"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD FONT TEXT" << "\n";
	}
	
	// initial point text
	this->pointText.setPosition(sf::Vector2f(10.f, 10.f));
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(40);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setString("- for point -");
	this->pointText.setStyle(sf::Text::Bold);

	// gameOver Text
	this->gameOverText.setPosition(sf::Vector2f(650.f, 350.f));
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(50);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("!!! GAME OVER !!!");
	this->gameOverText.setStyle(sf::Text::Bold);

	// Show results ---> SCORE
	this->results.setPosition(sf::Vector2f(650.f, 500.f));
	this->results.setFont(this->font);
	this->results.setCharacterSize(60);
	this->results.setFillColor(sf::Color::Magenta);
	this->results.setString("Your Score : ");
	this->results.setStyle(sf::Text::Bold);

	// initial HP
	this->playerHpBar.setSize(sf::Vector2f(500.f, 30.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(1150.f, 20.f));
	this->playerHpBar.setOutlineColor(sf::Color::Yellow);
	this->playerHpBar.setOutlineThickness(2.f);

	this, playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::initialBG()
{
	if (!this->bgTexture.loadFromFile("Textures/skyy2.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD BG TEXTURES" << "\n";
	}
	this->background.setTexture(this->bgTexture);
}

void Game::initialBGSound()
{
	if (!this->music.openFromFile("Textures/cuphead.ogg"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - cuphead - SOUND" << "\n";
	}
	// initial bg sound
	this->music.play();
	this->music.setVolume(30.f);
	this->music.setLoop(true);
	
}

void Game::initialBGMenu()
{
	if (!this->menuTexture.loadFromFile("Textures/menuART001.png"))
	{
		std::cout << "ERROR::Menu Background ::could not load." << "\n";
	}

	//this->menuSprite.setTexture(&menuTexture);
	this->menuSprite.setSize(sf::Vector2f (
								static_cast<float>(this->window->getSize().x), 
								static_cast<float>(this->window->getSize().y)
								)
								);
}

/* --- PILOT --- */
void Game::initialPlayer()
{
	this->player = new Player();

}

void Game::initialEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initialRedEnemy()
{
	this->RedspawnTimerMax = 8.f;
	this->RedspawnTimer = this->RedspawnTimerMax;
}

void Game::initialBlueEnemy()
{
	this->BluespawnTimerMax = 10.f;
	this->BluespawnTimer = this->BluespawnTimerMax;
}

void Game::initialPotion()
{
	this->PospawnTimerMax = 150.f;
	this->PospawnTimer = this->PospawnTimerMax;
}

void Game::initialShield()
{
	this->ShspawnTimerMax = 400.f;
	this->ShspawnTimer= this->ShspawnTimerMax;
}

void Game::initialSound()
{
	if (!this->buffer.loadFromFile("Textures/pop.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - pop - SOUND" << "\n";
	}
	// initial pew sound
	this->sound.setBuffer(this->buffer);

	this->sound.play();
	this->sound.setVolume(80.f);
}

void Game::initialHaha()
{
	if (!this->bufflol.loadFromFile("Textures/lol.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - gam over haha - SOUND" << "\n";
	}
	// initial HAHA
	this->haha.setBuffer(this->bufflol);

	this->haha.play();
	this->haha.setVolume(200.f);
}

void Game::initialHPsound()
{
	if (!this->buffHP.loadFromFile("Textures/glass.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - potion break - SOUND" << "\n";
	}
	// initial HAHA
	this->soundHP.setBuffer(this->buffHP);

	this->soundHP.play();
	this->soundHP.setVolume(250.f);
}

void Game::initialShieldSound()
{
	if (!this->buffShield.loadFromFile("Textures/hitShield.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - soudShield - SOUND" << "\n";
	}
	// initial HAHA
	this->soundShield.setBuffer(this->buffShield);

	this->soundShield.play();
	this->soundShield.setVolume(200.f);
}

void Game::LobThangMod()
{
	// yellow flappy
	for (auto& enem : this->enemies)
	{
		// delete enemies
		delete enem;

	}
	this->enemies.clear();		// flappy
	
	// red bird
	for (auto& redene : this->redenemy)
	{
		// delete red enemies
		delete redene;

	}
	this->redenemy.clear();		// red bird

	// blue bird
	for (auto* blueene : this->blueenemy)
	{
		// delete blue enemies
		delete blueene;
	}
	this->blueenemy.clear();	// blue bird

	// potion
	for (auto& po : this->potion)
	{
		// delete potion
		delete po;
	}
	this->potion.clear();		// potion
	
								
	// shield
	for (auto& sh : this->shield)
	{
		// delete shield
		delete sh;
	}
	this->shield.clear();		// shield


	// player HP start set to 100
	this->player->setHP(100);
	// point begin = 0
	this->points = 0;

	// bullet
	for (auto& bull : this->bullets)
	{
		// delete enemies
		delete bull;

	}
	this->bullets.clear();		// bullet
}

void Game::initialSystem()
{
	this->points = 0;

}

void Game::writeFileScore()
{
	std::ofstream writer;

	writer.open("Score.txt", std::fstream::app);
	if (writer.is_open())
	{
		writer << "" << this->points << std::endl;

		std::cout << "Open File Success!";

	}
	else
	{
		std::cout << "Cannot Open File!";
	}
}

void Game::readFileScore()
{
	std::ifstream reader;
	char a;
	reader.open("Score.txt", std::fstream::app);
	if (reader.is_open())
	{
		//reader >> a;
		reader >> this->points;

		std::cout << "Read File Success!";
		std::cout << "" << this->points << std::endl;

	}
	else
	{
		std::cout << "Cannot Read File!";
	}
}


/*GAME WINDOW*/
Game::Game()
{
	// DISPLAY WINDOW;
	this->initialWindow();

	// MENU;
	this->initialBGMenu();

	this->initialTextures();

	// FONT & SCORE;
	this->initialGUI();

	// BACKGROUND;
	this->initialBG();
	this, initialBGSound();
	this->initialSound();

	this->initialSystem();

	// PLAYER;
	this->initialPlayer();

	// ENEMIES;
	this->initialEnemies();
	this->initialRedEnemy();
	this->initialBlueEnemy();

	// ITEM;
	this->initialPotion();
	this->initialShield();

	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	//delete textures;
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//delete bullets;
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//delete enemies yellow flappy;
	for (auto* i : this->enemies)
	{
		delete i;
	}
	//delete red bird;
	for (auto* i : this->redenemy)
	{
		delete i;
	}
	//delete blue bird;
	for (auto* i : this->blueenemy)
	{
		delete i;
	}
	//delete potion;
	for (auto* i : this->potion)
	{
		delete i;
	}
	//delete shield;
	for (auto* i : this->shield)
	{
		delete i;
	}
}

void Game::checkStart()
{
	this->isGameStart = false; // Game hasn't start yet!


}

/*FUNCTIONS*/
void Game::run()
{
	while (this->window->isOpen()) // Game run;
	{

		this->updatePollEvents();
		if (this->player->getHp() > 0) // If player hp > 0;
		{
			this->updateDt();
			this->update();
			this->render();
		}
	}
}



void Game::updatePollEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
		if (event.Event::KeyPressed&& event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::K)
		{
			this->isGameStart = true;  // check game --- start;
			this->music.play();
		}
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::U)
		{
			this->isGameStart = false; // check game --- close;
			this->player->gotShield = false;
			this->LobThangMod();
			this->player->setPosition(0.f, 450.f);
		}

		
	}
}

void Game::updateInput() // COMMAND BUTTON;
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack()) //press J = attack;
	{
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"],
			this->player->getPos().x + this->player->getBounds().height / 2.f,
			this->player->getPos().y+ this->player->getBounds().height/2.f, 1.f, 0.f, 7.f)
			);
		this->initialSound();
		
	}
	
}

void Game::updateGUI() // text or can change
{
	// TEXT
		std::stringstream ss;
		std::stringstream sc;
		ss << "Points: " << this->points;
		this->pointText.setString(ss.str());

		sc << "Your Score :" << this->points;
		this->results.setString(sc.str());

	// HP
		float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
		this->playerHpBar.setSize(sf::Vector2f(500.f * hpPercent, this->playerHpBar.getSize().y));
	
}


void Game::updateBG() // no need to update
{

}

void Game::updateBGSound()
{

}

/*void Game::updateMousePos()
{
	this->mouseScreen = sf::Mouse::getPosition();
	this->mouseWindow = sf::Mouse::getPosition(*this->window);
	this->mouseView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}*/

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bulet culling (top screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateEnemies() // yellow flappy
{
	// enemies spawning
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemies(1700.f, rand() % this->window->getSize().y + 100.f));
		this->spawnTimer = 0.f;
		
	}

	// update
	unsigned Fcounter = 0;
	for (auto* enemie : this->enemies)
	{
		enemie->update();

		// enemies culling (top screen)
		if (enemie->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->enemies.at(Fcounter);
			this->enemies.erase(this->enemies.begin() + Fcounter);

		}

		// Enemies & Player colission
		else if (enemie->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->player->loseHP(this->enemies.at(Fcounter)->getDamage());
				delete this->enemies.at(Fcounter);
				this->enemies.erase(this->enemies.begin() + Fcounter);
			}

			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -= 1;
				delete this->enemies.at(Fcounter);
				this->enemies.erase(this->enemies.begin() + Fcounter);
			}
		}

		++Fcounter;
	}

}

void Game::updateRedEnemy() // red bird
{
	// redenemy spawning
	this->RedspawnTimer += 0.1f;
	if (this->RedspawnTimer >= this->RedspawnTimerMax)
	{
		this->redenemy.push_back(new RedEnemy(1700.f, rand() % this->window->getSize().y + 100.f));
		this->RedspawnTimer = 0.f;

	}

	// update
	unsigned Rcounter = 0;
	for (auto* redenem : this->redenemy)
	{
		redenem->update();

		// enemies culling (top screen)
		if (redenem->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->redenemy.at(Rcounter);
			this->redenemy.erase(this->redenemy.begin() + Rcounter);

		}

		// Enemies & Player colission
		else if (redenem->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->player->loseHP(this->redenemy.at(Rcounter)->getDamage());
				delete this->redenemy.at(Rcounter);
				this->redenemy.erase(this->redenemy.begin() + Rcounter);
			}

			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -= 1;
				delete this->redenemy.at(Rcounter);
				this->redenemy.erase(this->redenemy.begin() + Rcounter);
			}
		}

		++Rcounter;
	}
}

void Game::updateBlueEnemy()
{
	// blueenemy spawning
	this->BluespawnTimer += 0.1f;
	if (this->BluespawnTimer >= this->BluespawnTimerMax)
	{
		this->blueenemy.push_back(new BlueEnemy(1700.f, rand() % this->window->getSize().y + 100.f));
		this->BluespawnTimer = 0.f;

	}

	// update
	unsigned Bcounter = 0;
	for (auto* blueenem : this->blueenemy)
	{
		blueenem->update();

		// enemies culling (top screen)
		if (blueenem->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->blueenemy.at(Bcounter);
			this->blueenemy.erase(this->blueenemy.begin() + Bcounter);

		}

		// Enemies & Player colission
		else if (blueenem->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->player->loseHP(this->blueenemy.at(Bcounter)->getDamage());
				delete this->blueenemy.at(Bcounter);
				this->blueenemy.erase(this->blueenemy.begin() + Bcounter);
			}
			
			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -=1;
				delete this->blueenemy.at(Bcounter);
				this->blueenemy.erase(this->blueenemy.begin() + Bcounter);
			}
		}

		++Bcounter;
	}
}

void Game::updatePotion() // potion
{
	// potion spawning
	this->PospawnTimer += 0.1f;
	if (this->PospawnTimer >= this->PospawnTimerMax)
	{
		this->potion.push_back(new Potion(1700.f, rand() % this->window->getSize().y + 100.f));
		this->PospawnTimer = 0.f;

	}

	// update
	unsigned Pcounter = 0;
	for (auto* pot : this->potion)
	{
		pot->update();

		// enemies culling (top screen)
		if (pot->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->potion.at(Pcounter);
			this->potion.erase(this->potion.begin() + Pcounter);

		}

		// Enemies & Player colission
		else if (pot->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			this->player->loseHP(this->potion.at(Pcounter)->getDamage());
			delete this->potion.at(Pcounter);
			this->potion.erase(this->potion.begin() + Pcounter);

		}

		++Pcounter;
	}
}

void Game::updateShield()
{
	// shield spawning
	this->ShspawnTimer += 0.1f;
	if (this->ShspawnTimer >= this->ShspawnTimerMax)
	{
		this->shield.push_back(new Shield(1700.f, rand() % this->window->getSize().y + 100.f));
		this->ShspawnTimer = 0.f;

	}

	// update
	unsigned Scounter = 0;
	for (auto* shi : this->shield)
	{
		shi->update();

		// Item culling (top screen)
		if (shi->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete shield
			delete this->shield.at(Scounter);
			this->shield.erase(this->shield.begin() + Scounter);

		}

		// Item & Player colission
		else if (shi->getBounds().intersects(this->player->getBounds()))
		{
			this->haveShield = true;
			this->numShield = 3;
			// delete shield W H I L E   H I T   T H E   P L A Y E R 
			this->player->loseHP(this->shield.at(Scounter)->getDamage());
			this->player->getShield(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);

			delete this->shield.at(Scounter);
			this->shield.erase(this->shield.begin() + Scounter);

		}

		++Scounter;
	}
}

void Game::checkShield()
{
	if (this->numShield <= 0)
	{
		// return
		this->numShield = 3;

		this->player->getShield(false, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->haveShield = false;
	}
}

void Game::updateCombat() // Shooting & Get Points ----- After shooting diaapear
{
	// Yellow Flappy
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();

		for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) // has been shot
		{

			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) // IF bullet touch the enemies
			{
				this->points += this->enemies[i]->getPoints();

				this->bullets.erase(this->bullets.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);

				enemy_removed = true;
			}
		}
	}

	// Red Bird
	for (int Ri = 0; Ri < this->redenemy.size(); ++Ri)
	{
		bool Renemy_removed = false;
		this->redenemy[Ri]->update();

		for (size_t Rk = 0; Rk < this->bullets.size() && !Renemy_removed; Rk++) // has been shot
		{

			if (this->bullets[Rk]->getBounds().intersects(this->redenemy[Ri]->getBounds())) // IF bullet touch the enemies
			{
				this->points += this->redenemy[Ri]->getPoints();

				this->bullets.erase(this->bullets.begin() + Rk);
				this->redenemy.erase(this->redenemy.begin() + Ri);

				Renemy_removed = true;
			}
		}
	}

	// Blue Bird
	for (int Bi = 0; Bi < this->blueenemy.size(); ++Bi)
	{
		bool Benemy_removed = false;
		this->blueenemy[Bi]->update();

		for (size_t Bk = 0; Bk < this->bullets.size() && !Benemy_removed; Bk++) // has been shot
		{

			if (this->bullets[Bk]->getBounds().intersects(this->blueenemy[Bi]->getBounds())) // IF bullet touch the enemies
			{
				this->points += this->blueenemy[Bi]->getPoints();

				this->bullets.erase(this->bullets.begin() + Bk);
				this->blueenemy.erase(this->blueenemy.begin() + Bi);

				Benemy_removed = true;
			}
		}
	}

	// Potion
	for (int Pi = 0; Pi < this->potion.size(); ++Pi)
	{
		bool Penemy_removed = false;
		this->potion[Pi]->update();

		for (size_t Pk = 0; Pk < this->bullets.size() && !Penemy_removed; Pk++) // has been shot
		{

			if (this->bullets[Pk]->getBounds().intersects(this->potion[Pi]->getBounds())) // IF bullet touch the enemies
			{
				this->initialHPsound();
				this->points += this->potion[Pi]->getPoints();

				this->bullets.erase(this->bullets.begin() + Pk);
				this->potion.erase(this->potion.begin() + Pi);

				Penemy_removed = true;
			}
		}
	}
	// Shield
	/*for (int Si = 0; Si < this->shield.size(); ++Si)
	{
		bool Senemy_removed = false;
		this->shield[Si]->update();

		for (size_t Sk = 0; Sk < this->bullets.size() && !Senemy_removed; Sk++) // has been shot
		{

			if (this->bullets[Sk]->getBounds().intersects(this->shield[Si]->getBounds())) // IF bullet touch the enemies
			{
				this->points += this->shield[Si]->getPoints();

				this->bullets.erase(this->bullets.begin() + Sk);
				this->shield.erase(this->shield.begin() + Si);

				Senemy_removed = true;
			}
		}
	}*/

}


void Game::updateCollision()
{
	// left
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
		this->player->updateShield(+70.f, this->player->getBounds().top);
	}
	// right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
		this->player->updateShield(this->window->getSize().x - this->player->getBounds().width +70.f, this->player->getBounds().top);
	}
	// top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
		this->player->updateShield(this->player->getBounds().left +75.f, 0.f);
	}
	// down
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
		this->player->updateShield(this->player->getBounds().left +75.f, this->window->getSize().y - this->player->getBounds().height);
	}
}



void Game::renderBG()
{
	this->window->draw(this->background);
}

void Game::renderGUI()
{
	// TEXT
	this->window->draw(this->pointText);

	//HP
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	

}

void Game::renderBGMenu()
{
	this->window->draw(this->menuSprite);
}

/*CLOSE WINDOW*/
void Game::update()
{
	//std::cout << this->mouseView.x << " " << this->mouseView.y << "\n";
	//this->updateMousePos();

	if (this->isGameStart) // yang mai start
	{
		this->updateInput();

		this->player->update();

		// UPDATE OBJECT

		this->updateBullets();
		this->updateEnemies();
		this->updateRedEnemy();
		this->updateBlueEnemy();

		this->updatePotion();
		this->updateShield();
		this->checkShield();


		this->updateCombat();


		this->updateCollision();

		this->updateGUI();

		this->updateBG();

		
		
	}


}

void Game::updateDt()
{
	// update time to run

	this->dt = this->dtClock.getElapsedTime().asSeconds();
	
	//printf("\n Time : %f", this->dt);


}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::render() //render player
{
	this->window->clear();

	/*draw space*/
	if (!this->isGameStart) // game start
	{
		this->renderBGMenu(); // BGMenu
		this->music.stop();
	}
	
	else
	{
		this->renderBG();	  // BG
		this->renderPlayer(); // pilot
		this->renderGUI();	  // text health bar


		for (auto* bullet : this->bullets)		// bullets
		{
			bullet->render(this->window);
		}

		for (auto* enemie : this->enemies)		// yellow flappy
		{
			enemie->render(*this->window);
		}
		for (auto* redenem : this->redenemy)	// red bird
		{
			redenem->render(*this->window);
		}
		for (auto* blueenem : this->blueenemy)	// blue bird
		{
			blueenem->render(*this->window);
		}
		for (auto* pot : this->potion)
		{
			pot->render(*this->window);			// potion
		}
		for (auto* shi : this->shield)
		{
			shi->render(*this->window);			// shield
		}

		/*display*/

		//game over
		if (this->player->getHp() <= 0)
		{

			this->window->draw(this->gameOverText);
			this->window->draw(this->results);
			this->writeFileScore();
			this->readFileScore();

			this->music.stop();
			this->initialHaha();

		}


	}
	this->window->display();
}
