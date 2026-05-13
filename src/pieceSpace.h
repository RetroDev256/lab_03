/***********************************************************************
 * Header File:
 *    SPACE
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    The space
 ************************************************************************/

#pragma once

#include "piece.h"

class TestSpace;

/***************************************************
 * SPACES
 * A space is a trivial piece
 ***************************************************/
class Space : public Piece
{
      friend TestSpace;

   public:
      Space(int c, int r) : Piece(c, r) {}
      ~Space() {}
      PieceType getType() const { return PieceType::SPACE; }
      void display(ogstream *pgout) const {}
};