/***********************************************************************
 * Source File:
 *    PIECE
 * Author:
 *    Eric Petersen & Briant Woolley
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

   // We don't know, and don't want to know how to handle assignment logic for
   // child types. So we will just copy the parent type fields and let children
   // types add their own assignment operator, calling this operator for the
   // parent data.

   this->fWhite = rhs.fWhite;
   this->lastMove = rhs.lastMove;
   this->nMoves = rhs.nMoves;
   this->position = rhs.position;

   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set<Move> &movesSet, const Board &board) const {}
