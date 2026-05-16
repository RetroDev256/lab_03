/******************************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    Everything we need to know about a single chess move
 *****************************************************************************/

#pragma once

#include "pieceType.h" // A piece type
#include "position.h"  // Every move has two Positions as attributes
#include <cassert>
#include <cstring>
#include <sstream> // for ostringstream
#include <string>

/******************************************************************************
 * MOVE
 * One move across the board
 *****************************************************************************/
class Move
{
   public:
      enum MoveType
      {
         MOVE,
         ENPASSANT,
         CASTLE_KING,
         CASTLE_QUEEN,
         MOVE_ERROR
      };

      friend class TestMove;
      friend class TestBoard;
      friend class TestKnight;

      // Default constructor
      Move();
      // Constructor from C string
      Move(const char *str);
      // Constructor from C++ string
      Move(std::string str) { *this = Move(str.c_str()); }
      // Constructor from components
      Move(
         Position source, Position dest, PieceType capture, PieceType promote,
         MoveType moveType, bool white
      );

      // Transitivity for different moves based on destination index
      bool operator<(const Move &rhs) const { return rhs.dest < this->dest; }
      // Equality for different moves, from all fields
      bool operator==(const Move &rhs) const;
      // Conversion to and from text (standard notation)
      std::string getText() const;
      // Get the source position
      Position getSource() const { return source; }
      // Get the destination position
      Position getDestination() const { return dest; }

      // Assignment operator from C string
      const Move &operator=(const char *rhs) { return *this = Move(rhs); }
      // Assignment operator from C++ string
      const Move &operator=(std::string rhs) { return *this = Move(rhs); }
      // Function to copy from another Move
      void set(const Move &rhs) { *this = Move(rhs); }

   private:
      // Map a PieceType to a character
      static char letterFromPieceType(PieceType pt);
      // Map a character to a PieceType
      static PieceType pieceTypeFromLetter(char letter);

      Position source;   // where the move originated from
      Position dest;     // where the move finished
      PieceType promote; // piece to be promoted to
      PieceType capture; // did a capture happen this move?
      MoveType moveType; // what type of move is this?
      bool isWhite;      // whose turn is it anyway?
};
