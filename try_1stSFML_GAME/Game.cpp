#include "Game.h"
void Game::initialWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1700, 900), "63010849 Worawich Tangpojthaweeporn", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initialTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initialBG()
{
	if (!this->bgTexture.loadFromFile("Textures/sky.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD BG TEXTURES" << "\n";
	}
	this->background.setTexture(this->bgTexture);
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


/*GAME WINDOW*/
Game::Game()
{
	this->initialWindow();
	this->initialTextures();

	this->initialPlayer();
	this->initialEnemies();

	this->initialBG();
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

/*FUNCTIONS*/
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
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
	}
}

void Game::updateInput() // COMMAND BUTTON
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"],
			this->player->getPos().x + this->player->getBounds().height / 2.f,
			this->player->getPos().y+ this->player->getBounds().height/2.f, 1.f, 0.f, 7.f)
			);
	}
	
}

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
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemies(rand() % 200, rand() % 200));
		this->spawnTimer = 0.f;
		
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

/*CLOSE WINDOW*/
void Game::update()
{
	this->updatePollEvents();
	
	this->updateInput();

	this->player->update();

	this->updateBullets();

	this->updateEnemies();

	this->updateCollision();


}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::render() //render player
{
	this->window->clear();

	/*draw space*/
	this->renderBG();	  // BG
	this->renderPlayer(); // pilot
	

	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	
	for (auto* enemy : this->enemies)
	{
		enemy->render(*this->window);
	}

	/*display*/
	this->window->display();
}
