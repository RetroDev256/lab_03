/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h" // for draw*()

/***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream *pgout) const
{
   pgout->drawKnight(this->position, !this->fWhite);
}

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set<Move> &moves, const Board &board) const
{
   // 0 1 2 3 4 5 6 7
   // 1 . . . . . . .
   // 2 . . B . C . .
   // 3 . A . . . D .
   // 4 . . . # . . .
   // 5 . H . . . E .
   // 6 . . G . F . .
   // 7 . . . . . . .

   Delta offsets[] = {
      {-2, -1}, // A
      {-1, -2}, // B
      {+1, -2}, // C
      {+2, -1}, // D
      {+2, +1}, // E
      {+1, +2}, // F
      {-1, +2}, // G
      {-2, +1}, // H
   };

   for (const auto &off : offsets)
   {
      Position target = this->position + off;
      if (board[target] == PieceType::SPACE)
      {
         moves.insert(Move(
            this->position,
            target,
            PieceType::INVALID,
            PieceType::INVALID,
            Move::MoveType::MOVE,
            this->fWhite
         ));
      }
   }
}