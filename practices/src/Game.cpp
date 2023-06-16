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
    this->endGame = false;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
//    this->enemy.setOutlineColor(sf::Color::Green);
//    this->enemy.setOutlineThickness(1.f);
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
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x, this->window->getSize().x)),
        0.f
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
    
    //Moving and updating enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 5.f);

        //Set enemy color to red when mouse hover
        if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            this->enemies[i].setFillColor(sf::Color::Red);
        //Returning enemy color to green when mouse is not hover
        else
            this->enemies[i].setFillColor(sf::Color::Green);

        //If the enemy is past the bottom of the screen, delete them
        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            std::cout << "Health: " << this->health << std::endl;
        }

    }
    //Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!this->mouseHeld)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    //Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    //Gain points
                    this->points += 1;
                    std::cout << "Points: " << this->points << std::endl;
                }

            }
        }
    }
    else
    {
        this->mouseHeld = false;
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
    this->mousePosView   = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::update()
{
    this->pollEvents();

    if (!this->endGame)
    {
        this->updateMousePositions();

        this->updateEnemies();
    }

    if (this->health <= 0)
        this->endGame = true;
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

const bool Game::getEndGame() const
{
    return this->endGame;
}
