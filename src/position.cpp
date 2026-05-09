/******************************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 *****************************************************************************/

#include "position.h"
#include <cassert>
#include <cstring>
#include <iostream>

/******************************************************************************
 * Constructor for textual coordinates, such as "d4"
 * - asserts that the input string is valid
 *****************************************************************************/
Position::Position(const char *str)
{
   // Find the length of the C string, up to 3 bytes into the string -
   // the length of these textual coordinates must always be 2.
   size_t len = strnlen(str, 3);
   assert(len == 2);

   // The "C" in "CR" is the column in range [a, h]
   int col = str[0] - 'a';
   assert(col >= 0 && col <= 7);

   // "R" is the row in range [1, 8]
   int row = str[1] - '1';
   assert(row >= 0 && row <= 7);

   set(col, row);
}

/******************************************************************************
 * Get position column -1 | [0, 8)
 * - returns -1 on an invalid position
 *****************************************************************************/
int Position::getCol() const
{
   if (isInvalid())
      return -1;

   return colRow >> 4;
}

/******************************************************************************
 * Get position row -1 | [0, 8)
 * - returns -1 on an invalid position
 *****************************************************************************/
int Position::getRow() const
{
   if (isInvalid())
      return -1;

   return colRow & 15;
}

/******************************************************************************
 * Get flat index into chessboard -1 | [0, 64)
 * - returns -1 on an invalid position
 *****************************************************************************/
int Position::getLocation() const
{
   if (isInvalid())
      return -1;

   int row = colRow & 15;
   int col = colRow >> 4;
   return row * 8 + col;
}

/******************************************************************************
 * Set the position row [0, 8)
 * - if the input is out of bounds, the position is set to be invalid
 *****************************************************************************/
void Position::setRow(int row)
{
   if (row < 0 || row > 7)
      set((colRow & 0xF0) | 0xF);
   else
      set((colRow & 0xF0) | row);
}

/******************************************************************************
 * Set the position column [0, 8)
 * - if the input is out of bounds, the position is set to be invalid
 *****************************************************************************/
void Position::setCol(int col)
{
   if (col < 0 || col > 7)
      set((0xF << 4) | (colRow & 0xF));
   else
      set((col << 4) | (colRow & 0xF));
}

/******************************************************************************
 * Set both the column and row of a position
 * - the position is invalid if either col or row are out of bounds
 *****************************************************************************/
void Position::set(int col, int row)
{
   setRow(row);
   setCol(col);
}

/******************************************************************************
 * Set the position with a flat chessboard index [0, 64)
 * - if the input is out of bounds, the position is set to be invalid
 *****************************************************************************/
void Position::setLocation(int location)
{
   if (location < 0 || location >= 64)
      return setInvalid();

   int row = location / 8;
   int col = location % 8;
   set(col, row);
}

/******************************************************************************
 * Add to the row of a position
 *****************************************************************************/
void Position::adjustRow(int dRow)
{
   if (isInvalid())
      return;

   int new_row = getRow() + dRow;
   if (new_row < 0 || new_row > 7)
      setInvalid();
   else
      setRow(new_row);
}

/******************************************************************************
 * Add to the column of a position
 *****************************************************************************/
void Position::adjustCol(int dCol)
{
   if (isInvalid())
      return;

   int new_col = getCol() + dCol;
   if (new_col < 0 || new_col > 7)
      setInvalid();
   else
      setCol(new_col);
}

/******************************************************************************
 * Addition operator for Position & Delta
 * - if the position is already in an invalid state, nothing changes
 * - the position is set invalid if adding rhs would be out of bounds
 *****************************************************************************/
Position Position::operator+(const Delta &rhs) const
{
   Position pos = *this;
   pos.adjustCol(rhs.dCol);
   pos.adjustRow(rhs.dRow);
   return pos;
}

/******************************************************************************
 * Assignment & addition operator for Position & Delta
 * - if the position is already in an invalid state, nothing changes
 * - the position is set invalid if adding rhs would be out of bounds
 *****************************************************************************/
const Position &Position::operator+=(const Delta &rhs)
{
   *this = *this + rhs;
   return *this;
}

/******************************************************************************
 * Assignment operator for a position
 *****************************************************************************/
const Position &Position::operator=(const Position &rhs)
{
   set(rhs.colRow);
   return *this;
}

/******************************************************************************
 * Assignment operator for a C string
 *****************************************************************************/
const Position &Position::operator=(const char *rhs)
{
   return *this = Position(rhs);
}

/******************************************************************************
 * Assignment operator for a C++ string
 *****************************************************************************/
const Position &Position::operator=(const string &rhs)
{
   return *this = Position(rhs.c_str());
}

/******************************************************************************
 * Set the X and Y position (screen coordinates) in number of pixels
 *****************************************************************************/
void Position::setXY(double x, double y)
{
   int newX = int(x / squareWidth) - 1;
   int newY = 8 - int(y / squareHeight);
   set(newX, newY);
}

/******************************************************************************
 *  Set the screen resolution of a board square in pixels
 *****************************************************************************/
void Position::setBoardWidthHeight(int widthBoard, int heightBoard)
{
   if (widthBoard < 0 || heightBoard < 0)
      return;

   // 8 squares + 2 spaces
   squareWidth = double(widthBoard) / 10.0;
   squareHeight = double(heightBoard) / 10.0;
}

/******************************************************************************
 * POSITION INSERTION OPERATOR
 *****************************************************************************/
ostream &operator<<(ostream &out, const Position &rhs)
{
   if (rhs.isInvalid())
      return out << "ERROR";

   out << char('a' + rhs.getCol());
   out << char('1' + rhs.getRow());
   return out;
}

/******************************************************************************
 * POSITION EXTRACTION OPERATOR
 *****************************************************************************/
istream &operator>>(istream &in, Position &rhs)
{
   char pos[2];
   in >> pos;
   rhs = Position(pos);
   return in;
}