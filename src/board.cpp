/******************************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    A collection of pieces and the state of the board
 *****************************************************************************/

#include "board.h"
#include "position.h"
#include <cassert>
#include <iostream>
using namespace std;

/******************************************************************************
 * Default constructor for board
 * - sets each piece pointer to null
 *****************************************************************************/
Board::Board(ogstream *pgout, bool noreset) : numMoves(0)
{
   this->pgout = pgout;
   (void)noreset; // unused.

   for (uint8_t row = 0; row < 8; row++)
      for (uint8_t col = 0; col < 8; col++)
         board[row][col] = nullptr;
}

/******************************************************************************
 * Execute a move on two different pieces
 * - The piece in the destination position is NOT deleted by this function
 * ^ Memory management must be performed by the caller.
 *****************************************************************************/
void Board::move(const Move &move)
{
   const Position src = move.getSource();
   const Position dest = move.getDestination();

   // Move the piece pointer
   board[dest.getCol()][dest.getRow()] = board[src.getCol()][src.getRow()];
   // Replace source with an empty space
   board[src.getCol()][src.getRow()] = new Space(src.getCol(), src.getRow());
   // Mark the piece as having moved
   board[dest.getCol()][dest.getRow()]->setLastMove(numMoves);

   // Not implemented yet: castling logic, promotions.

   numMoves++;
}

/******************************************************************************
 * BOARD : GET (constant reference)
 *         Get a piece from a given position.
 *         - asserts that the position is valid
 *****************************************************************************/
const Piece &Board::operator[](const Position &pos) const
{
   assert(pos.isValid());
   return *(board[pos.getCol()][pos.getRow()]);
}

/******************************************************************************
 * BOARD : GET (mutable reference)
 *         Get a piece from a given position.
 *         - asserts that the position is valid
 *****************************************************************************/
Piece &Board::operator[](const Position &pos)
{
   assert(pos.isValid());
   return *(board[pos.getCol()][pos.getRow()]);
}

/******************************************************************************
 * Display the board
 * - each piece must display themselves using the provided ogstream
 *****************************************************************************/
void Board::display(const Position &hover, const Position &select) const
{
   pgout->drawBoard();
   pgout->drawHover(hover);
   pgout->drawSelected(select);

   for (uint8_t row = 0; row < 8; row++)
      for (uint8_t col = 0; col < 8; col++)
         if (board[row][col] != nullptr)
            board[row][col]->display(pgout);
}
