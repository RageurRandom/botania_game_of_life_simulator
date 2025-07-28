#include "../include/cell.hpp"
#include "../include/game.hpp"
#include <iostream>


Game::Game() {
    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        for (int x = 0; x < BOARD_SIZE_X; x++) {
            board[y][x] = nullptr;
        }
    }
}

void Game::addCell(int x, int y) {
    if (isValidPosition(y, x)) {
        Cell cell = Cell();
        board[y][x] = &cell;
    }
}

void Game::launch() {
    nextState();
}

void Game::nextState() {
    Cell *next_state[BOARD_SIZE_Y][BOARD_SIZE_X] = {nullptr};


    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        for (int x = 0; x < BOARD_SIZE_X; x++) {
            std::vector<Cell> neighborCells = getNeighborCells(y, x);

            Cell *cell = board[y][x];

            if (cell == nullptr) {
                if (neighborCells.size() == 3) {
                    //TODO cr�er cellule avec le bon age
                }

                //sinon la cellule reste morte
            } else {
                if (neighborCells.size() == 2 || neighborCells.size() == 3) {
                    //cellule vivante
                    cell->grow();
                } else {
                    //cellule morte

                    //cellule->~Cellule(); //peut peut-etre poser probl�me (on d�truit la cellule avant d'avoir fini le scan) donc je testerais apr�s
                    board[y][x] = nullptr;
                }
            }
        }
    }
}

bool Game::isValidPosition(int y, int x) {
    return (y >= 0 && y < BOARD_SIZE_Y) && (x >= 0 && x < BOARD_SIZE_X);
}


std::vector<Cell> Game::getNeighborCells(int y, int x) {
    //TODO refactor pour que ca soit une list (linkedList ? mais on priorise le type abstrait de tte fa�on)
    std::vector<Cell> cellVect = std::vector<Cell>();;

    for (int y = -1; y < 2; y++) {
        for (int x = -1; x < 2; x++) {
            if (x != 0 || y != 0) {
                // �vite de compter la cellule dont on veut connaitre le nb de voisines
                int current_x = x + x;
                int current_y = y + y;

                if (isValidPosition(current_y, current_x)) {
                    if (board[current_y][current_x] != nullptr) {
                        const Cell *neighborCell = board[current_y][current_x];
                        cellVect.push_back(*neighborCell);
                    }
                }
            }
        }
    }

    return cellVect;
}


int Game::celluleDansCentre() {
    /*
        renvoie -1 si le jeu n'est pas fini, l'�ge de la cellule la plus vieille dans le centre du terrain sinon
    */

    std::vector<Cell> cellVect = getNeighborCells(BOARD_SIZE_Y / 2, BOARD_SIZE_X / 2);
    if (cellVect.empty()) {
        return -1;
    }
    std::cout << "fin du jeu\n";

    Cell oldest = cellVect.at(0);

    for (Cell c: cellVect) {
        if (c.getAge() > oldest.getAge()) {
            oldest = c;
        }
    }

    std::cout << "R�sultats : " + oldest.getAge();

    return oldest.getAge();
}


void Game::afficherTerrain() {
    for (int y = 0; y < BOARD_SIZE_Y; y++) {
        for (int x = 0; x < BOARD_SIZE_X; x++) {
            if (board[y][x] != nullptr) {
                std::cout << "|" + board[y][x]->getAge();
                std::cout << "|";
            } else {
                std::cout << " X ";
            }
        }

        std::cout << '\n';
    }
}

Game::~Game() = default;
