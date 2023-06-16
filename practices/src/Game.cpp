//
// Created by ryan on 06/06/23.
//

#include "Game.h"

//Constructors and destructors

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}

//Private Functions

void Game::initVariables()
{
    this->window = nullptr;

    //Game logic
    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}



//Accessors

const bool Game::running() const {
    return this->window->isOpen();
}


//Functions
void Game::spawnEnemy()
{
    /*
     * @return void
     * Spawns enemies and sets their color and positions.
     *      Sets a random position
     *      Sets a random color
     *      Adds enemy to the vector
     */
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x, this->enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y, this->enemy.getSize().y))
    );

    this->enemy.setFillColor(sf::Color::Green);

    //Spawn the enemy
    this->enemies.push_back(this->enemy);

}

void Game::renderEnemies()
{
    //Rendering all the enemies on the enemies list
    for (auto &e : this->enemies) {
        this->window->draw(e);
    }
}

void Game::updateEnemies()
{
    /*
     * @return void
     * Updates the enemy spawn timer and spawn enemies when the total
     * amount of enemies is less than the maximum.
     * Moves the enemies downwards.
     * Removes the enemies at the edge of the screen. TODO
     */

    //Updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }
    
    //Move the enemies
    for (auto &e : this->enemies) {
        e.move(0.f, 5.f);
    }
}

void Game::render()
{
    /*
     * @return void
     * - clear old frame
     * - render objects
     * - display frame in window
     *
     *   Render the game objects
    */
    this->window->clear();

    //Draw game objects
    this->renderEnemies();

    this->window->display();

}

void Game::updateMousePositions()
{
    /*
     * @return void
     * Update the mouse positions:
     *      Mouse position relative to window (Vector2i)
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update()
{
    this->pollEvents();

    this->updateMousePositions();

    this->updateEnemies();
}

void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }

}
