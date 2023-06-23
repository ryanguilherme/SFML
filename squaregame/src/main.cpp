// compile and run
// g++ -c src/main.cpp src/Game.cpp -I ./lib/ && mv Game.o main.o ./obj
// g++ obj/main.o obj/Game.o -o app -L ./lib/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
// ./app

#include "Game.h"

int main(){
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));

    //Init game engine
    Game game;

	//Game loop
	while(game.running() && !game.getEndGame())
	{
        //Update
        game.update();

        //Render
        game.render();

	}

	//End of application

	return 0;
}