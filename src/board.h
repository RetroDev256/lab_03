/******************************************************************************
 * Header File:
 *    BOARD
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    A collection of pieces and the state of the board
 *****************************************************************************/

#pragma once

#include "move.h"  // Because we return a set of Move
#include "piece.h" // For Piece
#include <cassert>

class ogstream;
class TestPawn;
class TestKnight;
class TestBishop;
class TestRook;
class TestQueen;
class TestKing;
class TestBoard;
class Position;
class Piece;

/******************************************************************************
 * BOARD
 * The game board
 *****************************************************************************/
class Board
{
      friend TestPawn;
      friend TestKnight;
      friend TestBishop;
      friend TestRook;
      friend TestQueen;
      friend TestKing;
      friend TestBoard;

   public:
      // Default constructor for board
      Board(ogstream *pgout = nullptr, bool noreset = true);

      // Get the current move
      virtual int getCurrentMove() const { return numMoves; }
      // Get whether it is white's turn
      virtual bool whiteTurn() const { return (numMoves & 1) == 0; }
      // Index the board with a Position to get a constant piece reference
      virtual const Piece &operator[](const Position &pos) const;
      // Display the board [not yet implemented]
      virtual void display(const Position &hover, const Position &select) const
      {
      }

      // Execute a move on different pieces [not yet fully implemented]
      virtual void move(const Move &move) { numMoves++; }
      // Index the board with a Position to get a piece reference
      virtual Piece &operator[](const Position &pos);

      virtual void free() { assert(false); }           // ???
      virtual void reset(bool free) { assert(false); } // ???

   protected:
      // the number of moves since the game began
      int numMoves;
      // a two dimentional array of pointers to each piece
      Piece *board[8][8];
};

/******************************************************************************
 * BOARD DUMMY BOARD
 * A board double that does nothing but assert. Will need this for unit tests.
 *****************************************************************************/
class BoardDummy : public Board
{
      friend TestBoard;

   public:
      BoardDummy() : Board(nullptr, true) {}
      ~BoardDummy() {}

      void display(const Position &hover, const Position &select) const
      {
         assert(false);
      }
      void move(const Move &move) { assert(false); }
      int getCurrentMove() const { assert(false); }
      bool whiteTurn() const { assert(false); }
      Piece &operator[](const Position &pos) { assert(false); }
      const Piece &operator[](const Position &pos) const { assert(false); }
      void free() { assert(false); }
      void reset(bool free = true) { assert(false); }
};

/******************************************************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *****************************************************************************/
class BoardEmpty : public BoardDummy
{
      friend TestBoard;

   public:
      Piece *pSpace;

      BoardEmpty() : BoardDummy() {}
      ~BoardEmpty() { delete pSpace; }

      // TODO: might need to add getCurrentMove() -> 0 ???

      const Piece &operator[](const Position &pos) const
      {
         assert(pos.isValid());
         if (board[pos.getCol()][pos.getRow()])
            return *(board[pos.getCol()][pos.getRow()]);
         else
            return *pSpace;
      }
};
