// compile and run
// g++ -c src/main.cpp src/Game.cpp -I /home/ryan/Documents/SFML -I ./lib/ && mv Game.o main.o ./obj
// g++ obj/main.o obj/Game.o -o sfml-app -L /home/ryan/Documents/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
// ./sfml-app

#include "Game.h"

int main(){
    //Init game engine
    Game game;

	//Game loop
	while(game.running())
	{
        //Update
        game.update();

        //Render
        game.render();

	}

	//End of application

	return 0;
}