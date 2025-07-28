#include <iostream>
#include "../include/game.hpp"
#include "../include/cell.hpp"

int main() {
    std::cout << "Hello World!\n";
    Cell c = Cell();

    Game jeu = Game();

    jeu.addCell(0, 0);
    jeu.addCell(0, 1);
    jeu.addCell(1, 0);
    jeu.addCell(1,1 );

    jeu.launch();



    jeu.afficherTerrain();

	return 0;
}
