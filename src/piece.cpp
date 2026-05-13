/***********************************************************************
 * Source File:
 *    PIECE
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "piece.h" // for all the PIECE class definitions
#include "board.h" // for BOARD
#include "pieceKnight.h"
#include "pieceSpace.h"
#include "position.h" // for POSITION
#include "uiDraw.h"   // for draw*()
#include <cassert>    // because we are paranoid
using namespace std;

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece &Piece::operator=(const Piece &rhs)
{

   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set<Move> &movesSet, const Board &board) const {}
