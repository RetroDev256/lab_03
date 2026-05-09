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
Board::Board() : numMoves(0)
{
   for (uint8_t row = 0; row < 8; row++)
      for (uint8_t col = 0; col < 8; col++)
         board[row][col] = nullptr;
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