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
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(1.f, 0.5f));
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
    this->window->draw(this->enemy);

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
