/******************************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    Everything we need to know about a single chess move
 *****************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

/******************************************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 *****************************************************************************/
Move::Move()
{
   capture = INVALID;
   moveType = MOVE_ERROR;
   promote = INVALID;
   source = Position();
   dest = Position();
   isWhite = false;
}

/******************************************************************************
 * MOVE : CONSTRUCT FROM C STRING
 *****************************************************************************/
Move::Move(const char *str)
{
   size_t len = strnlen(str, 6);
   if (len != 4 && len != 5) // SSDD[M], 4 or 5 long
      throw "invalid initialization string";

   char modifier = (len == 5) ? str[4] : '\0';
   PieceType piece = pieceTypeFromLetter(modifier);
   this->capture = piece == INVALID ? SPACE : piece;

   switch (modifier)
   {
      case 'E':
         this->moveType = ENPASSANT;
         break;
      case 'c':
         this->moveType = CASTLE_KING;
         break;
      case 'C':
         this->moveType = CASTLE_QUEEN;
         break;
      default:
         this->moveType = MOVE;
         if (len == 5 && piece == INVALID)
            this->moveType = MOVE_ERROR;
   }

   this->promote = INVALID;
   this->source = Position(std::string(str, 2));
   this->dest = Position(std::string(str + 2, 2));
   this->isWhite = false;
}

/******************************************************************************
 * MOVE : CONSTRUCT FROM COMPONENTS
 *****************************************************************************/
Move::Move(
   Position source, Position dest, PieceType capture, PieceType promote,
   MoveType moveType, bool white
) :
   source(source),
   dest(dest),
   capture(capture),
   promote(promote),
   moveType(moveType),
   isWhite(white)
{
}

/******************************************************************************
 * Equality for different moves, from all fields
 *****************************************************************************/
bool Move::operator==(const Move &rhs) const
{
   return this->source == rhs.source && this->dest == rhs.dest &&
          this->promote == rhs.promote && this->capture == rhs.capture &&
          this->moveType == rhs.moveType && this->isWhite == rhs.isWhite;
}

/******************************************************************************
 * Conversion to and from text (standard notation)
 *****************************************************************************/
std::string Move::getText() const
{
   std::ostringstream os;
   os << source;
   os << dest;

   switch (moveType)
   {
      case ENPASSANT:
         os << 'E';
         break;

      case CASTLE_KING:
         os << 'c';
         break;

      case CASTLE_QUEEN:
         os << 'C';
         break;

      default:
         if (capture != INVALID && capture != SPACE)
            os << letterFromPieceType(capture);
   }

   return os.str();
}

/******************************************************************************
 * Map a PieceType to a character
 *****************************************************************************/
char Move::letterFromPieceType(PieceType pt)
{
   switch (pt)
   {
      case BISHOP:
         return 'b';
      case PAWN:
         return 'p';
      case ROOK:
         return 'r';
      case QUEEN:
         return 'q';
      case KNIGHT:
         return 'n';
      case KING:
         return 'k';
      case SPACE:
         return ' ';
      case INVALID:
         return '?';
      default:
         assert(false);
   }
}

/******************************************************************************
 * Map a character to a PieceType
 *****************************************************************************/
PieceType Move::pieceTypeFromLetter(char letter)
{
   switch (letter)
   {
      case 'b':
         return BISHOP;
      case 'p':
         return PAWN;
      case 'r':
         return ROOK;
      case 'q':
         return QUEEN;
      case 'n':
         return KNIGHT;
      case 'k':
         return KING;
      case ' ':
         return SPACE;
      default:
         return INVALID;
   }
}