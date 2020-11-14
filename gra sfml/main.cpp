#include <iostream>
#include "game.h" // all the sfml files included in game.h


int main()
{
    //window init
    // window is initialized in game.cpp

    game myGame; 




    //window loop
    while (myGame.checkIfWindowIsOpen()) { // this is my custom function that returns the same boolean as isOpen() function
        
        //update game
        myGame.update();


        //render game into the screen

        myGame.render();

    }



    return 0;
}