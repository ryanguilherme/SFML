//
// Created by ryan on 06/06/23.
//
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
 * Class that acts as the game engine
 * Wrapper class
*/


#ifndef GAME_H
#define GAME_H

class Game
{
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;

    //Game objects
    sf::RectangleShape enemy;

    //Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void updateMousePositions();
    void update();
    void render();
};


#endif //GAME_H
