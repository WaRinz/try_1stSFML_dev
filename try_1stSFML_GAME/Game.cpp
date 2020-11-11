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
	if (!this->music.openFromFile("Textures/itzy.ogg"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - ITZY - SOUND" << "\n";
	}
	// initial bg sound
	this->music.play();
	this->music.setVolume(120.f);
	this->music.setLoop(true);
	
}

void Game::initialBGMenu()
{
	if (!this->menuTexture.loadFromFile("Textures/skyy.png"))
	{
		std::cout << "ERROR::Menu Background ::could not load." << "\n";
	}

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

void Game::LobThangMod()
{
	for (auto& enemy : this->enemies)
	{
		// delete enemies
		delete enemy;

	}
	this->enemies.clear();

	this->player->setHP(50);
	this->points = 0;
	for (auto& bull : this->bullets)
	{
		// delete enemies
		delete bull;

	}
	this->bullets.clear();
}

void Game::initialSystem()
{
	this->points = 0;

}


/*GAME WINDOW*/
Game::Game()
{
	this->initialWindow();

	this->initialBGMenu();

	this->initialTextures();

	this->initialGUI();
	this->initialBG();
	this, initialBGSound();
	this->initialHaha();
	this->initialSound();

	this->initialSystem();

	this->initialPlayer();
	this->initialEnemies();

	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	//delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//delete enemies
	for (auto* i : this->enemies)
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
	while (this->window->isOpen()) // Game run
	{

		this->updatePollEvents();
		if (this->player->getHp() > 0) // If player hp > 0
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
			this->isGameStart = true;
			this->music.play();
		}
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::L)
		{
			this->isGameStart = false;
			this->LobThangMod();
		}


		
	}
}

void Game::updateInput() // COMMAND BUTTON
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack()) //press J = attack
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
		ss << "Points: " << this->points;
		this->pointText.setString(ss.str());

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

void Game::updateEnemies()
{
	// enemies spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemies(1700.f, rand() % this->window->getSize().y + 100.f));
		this->spawnTimer = 0.f;
		
	}

	// update
	unsigned counter = 0;
	for (auto* enemies : this->enemies)
	{
		enemies->update();

		// enemies culling (top screen)
		if (enemies->getBounds().left < this->window->getSize().x - 1650.f)
		{
			// delete enemies
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);

		}

		// Enemies & Player colission
		else if (enemies->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			this->player->loseHP(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
	
		}

		++counter;
	}

}

void Game::updateCombat()
{
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
}

void Game::updateCollision()
{
	// left
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	// right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	// top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	// down
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
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

		this->updateBullets();

		this->updateEnemies();

		this->updateCombat();

		this->updateCollision();

		this->updateGUI();

		this->updateBG();

		
		
	}


}

void Game::updateDt()
{
	// update time to run

	this->dt = this->dtClock.restart().asSeconds();


}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::render() //render player
{
	this->window->clear();

	/*draw space*/
	if (!this->isGameStart) // game yang mai start
	{
		this->renderBGMenu(); // BGMenu
		this->music.stop();
	}
	
	else
	{
		this->renderBG();	  // BG
		this->renderPlayer(); // pilot
		this->renderGUI();	  // text health bar


		for (auto* bullet : this->bullets)
		{
			bullet->render(this->window);
		}

		for (auto* enemy : this->enemies)
		{
			enemy->render(*this->window);
		}

		/*display*/

		//game over
		if (this->player->getHp() <= 0)
		{
			this->window->draw(this->gameOverText);
			this->music.stop();
			this->initialHaha();
		}
	}
	this->window->display();
}
