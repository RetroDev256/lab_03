/******************************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 *****************************************************************************/

#pragma once

#include <cstdint>
#include <string>
using std::istream;
using std::ostream;
using std::string;

// number of pixels in a square by default
const int SIZE_SQUARE = 32;

/******************************************************************************
 * DELTA - Movement in a direction (dRow and dCol)
 * The Position class can work with deltas, which are offsets from
 * a given location. This helps pieces move on the chess board.
 *****************************************************************************/
struct Delta
{
      int dRow;
      int dCol;
};

const Delta ADD_R = {1, 0};
const Delta ADD_C = {0, 1};
const Delta SUB_R = {-1, 0};
const Delta SUB_C = {0, -1};

class PositionTest;

/******************************************************************************
 * POSITION
 * The location of a piece on the board
 *****************************************************************************/
class Position
{
      friend class PositionTest;

   public:
      // Default constructor - position is invalid by default
      Position() : colRow(0xFF) {}
      // Copy constructor from another position
      Position(const Position &rhs) : colRow(rhs.colRow) {}
      // Constructor from column and row integers
      Position(int c, int r) { set(c, r); }
      // Constructor for textual coordinates, such as "d4"
      Position(const char *str);
      // Constructor for coordinates, such as "d4", from C++ string
      Position(std::string str) { *this = Position(str.c_str()); }
      // Constructor from flat index into chessboard [0, 64)
      Position(int location) { set(location % 8, location / 8); }
      // Constructor from a position and offset
      Position(const Position &rhs, const Delta &delta) { *this = rhs + delta; }

      // Get position column -1 | [0, 8)
      virtual int getCol() const;
      // Get position row -1 | [0, 8)
      virtual int getRow() const;
      // Get flat index into chessboard -1 | [0, 64)
      int getLocation() const;

      // Get the X position (screen coordinates) in number of pixels
      int getX() const { return int(double(getCol() + 1) * squareWidth); }
      // Get the Y position (screen coordinates) in number of pixels
      int getY() const { return int(double(getRow() + 1) * squareHeight); }
      // Get the width (in pixels) of a board square on-screen
      double getSquareWidth() const { return squareWidth; }
      // Get the height (in pixels) of a board square on-screen
      double getSquareHeight() const { return squareHeight; }

      // Get whether the position is invalid
      virtual bool isInvalid() const { return (colRow & 0x88) != 0; }
      // Get whether the position is valid
      bool isValid() const { return !isInvalid(); }

      // Transitivity between positions
      bool operator<(const Position &rhs) const { return get() < rhs.get(); }
      // Inequality between positions
      bool operator!=(const Position &rhs) const { return get() != rhs.get(); }
      // Equality between positions
      bool operator==(const Position &rhs) const { return get() == rhs.get(); }

      // Set the position row [0, 8)
      void setRow(int r);
      // Set the position column [0, 8)
      void setCol(int c);
      // Set both the column and row of a position
      void set(int col, int row);
      // Set the position with a flat chessboard index [0, 64)
      void setLocation(int location);
      // Set the position to an invalid state
      void setInvalid() { set(0xFF); }

      // Add to the row of a position
      void adjustRow(int dRow);
      // Add to the column of a position
      void adjustCol(int dCol);

      // Addition operator for Position & Delta
      Position operator+(const Delta &rhs) const;
      // Assignment & addition operator for Position & Delta
      const Position &operator+=(const Delta &rhs);

      // Assignment operator for a position
      const Position &operator=(const Position &rhs);
      // Assignment operator for a C string
      const Position &operator=(const char *rhs);
      // Assignment operator for a C++ string
      const Position &operator=(const string &rhs);

      // Set the X and Y position (screen coordinates) in number of pixels
      void setXY(double x, double y);

      // Set the screen resolution of a board square in pixels
      void setBoardWidthHeight(int widthBoard, int heightBoard);

   private:
      // Set the value of colRow (sugar)
      void set(uint8_t colRowNew) { colRow = colRowNew; }
      // Get the value of colRow (sugar)
      uint8_t get() const { return colRow; }

      // binary-coded decimal position on a chessboard
      uint8_t colRow;
      // display width of each square in pixels
      static double squareWidth;
      // display height of each square in pixels
      static double squareHeight;
};

ostream &operator<<(ostream &out, const Position &pos);
istream &operator>>(istream &in, Position &pos);