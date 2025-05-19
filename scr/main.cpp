
#include <iostream>

#include "Game.h"

#include "graphics.h"

int main (){
	SetConsoleOutputCP(CP_UTF8);
    std::cout<<"Hello World"<<std::endl;
	auto game = new Game();
	game->run();
  return 0;

}



