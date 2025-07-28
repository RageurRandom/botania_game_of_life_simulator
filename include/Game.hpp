#ifndef __GAME__

	#define __GAME__

	#include "cell.hpp"

	#include <vector>

	class Game
	{
	public:
		static const int BOARD_SIZE_Y = 25;
		static const int BOARD_SIZE_X = 25;

		Game();
		~Game();
		void launch();
		void addCell(int x, int y);
		void afficherTerrain();

	private:
		Cell* board[BOARD_SIZE_Y][BOARD_SIZE_X];

		void nextState();
		int celluleDansCentre();
		std::vector<Cell> getNeighborCells(int lig, int col);
		bool isValidPosition(int lig, int col);
	};


#endif




