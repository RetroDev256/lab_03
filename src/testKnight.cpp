/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "board.h"
#include "pieceKnight.h"
#include "uiDraw.h"
#include <cassert>

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3             p   .   3
 * 2           P         2
 * 1              (n)    1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;

   knight.position.colRow = 0x60;
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set<Move> moves;
   Move g1e2p;
   g1e2p.source.colRow = 0x60;
   g1e2p.dest.colRow = 0x41;
   g1e2p.capture = PAWN;
   Move g1h3;
   g1h3.source.colRow = 0x60;
   // This test had an invalid colRow for this move. Originally the colRow for
   // the destination was set to 0x62. This would be G3, instead of H3. **H** is
   // 7, not 6. The test value has been corrected.
   g1h3.dest.colRow = 0x72;
   g1h3.capture = SPACE;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // many possible moves
   assertUnit(moves.find(g1e2p) != moves.end());
   assertUnit(moves.find(g1h3) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, true /*white*/);
   knight.fWhite = false;
   knight.position.colRow = 0x44;
   board.board[4][4] = &knight;
   Black black1(PAWN);

   board.board[2][3] = &black1;
   Black black2(PAWN);
   board.board[2][5] = &black2;
   Black black3(PAWN);
   board.board[3][2] = &black3;
   Black black4(PAWN);
   board.board[3][6] = &black4;
   Black black5(PAWN);
   board.board[5][2] = &black5;
   Black black6(PAWN);
   board.board[5][6] = &black6;
   set<Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY

   // We can move two spaces. these spaces are the positions in which there are
   // no blocking pieces of our own color. The original test was invalid and had
   // this marked as zero, which isn't possible as only 6 of the 8 possible
   // positions were inhabited.
   assertUnit(moves.size() == 2);

   // TEARDOWN
   board.board[4][4] = nullptr; // black knight
   board.board[2][3] = nullptr; // black pawn
   board.board[2][5] = nullptr; // black pawn
   board.board[3][2] = nullptr; // black pawn
   board.board[3][6] = nullptr; // black pawn
   board.board[5][2] = nullptr; // black pawn
   board.board[5][6] = nullptr; // black pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.colRow = 0x44;
   board.board[4][4] = &knight;
   Black black1(PAWN);

   board.board[2][3] = &black1;
   Black black2(PAWN);
   board.board[2][5] = &black2;
   Black black3(PAWN);
   board.board[3][2] = &black3;
   Black black4(PAWN);
   board.board[3][6] = &black4;
   Black black5(PAWN);
   board.board[5][2] = &black5;
   Black black6(PAWN);
   board.board[5][6] = &black6;
   set<Move> moves;
   Move e4d2p;
   e4d2p.source.colRow = 0x44;
   e4d2p.dest.colRow = 0x23;
   e4d2p.capture = PAWN;

   Move e4f2p;
   e4f2p.source.colRow = 0x44;
   e4f2p.dest.colRow = 0x25;
   e4f2p.capture = PAWN;

   Move e4c3p;
   e4c3p.source.colRow = 0x44;
   e4c3p.dest.colRow = 0x32;
   e4c3p.capture = PAWN;

   Move e4g3p;
   e4g3p.source.colRow = 0x44;
   e4g3p.dest.colRow = 0x36;
   e4g3p.capture = PAWN;

   Move e4c5p;
   e4c5p.source.colRow = 0x44;
   e4c5p.dest.colRow = 0x52;
   e4c5p.capture = PAWN;

   Move e4g5p;
   e4g5p.source.colRow = 0x44;
   e4g5p.dest.colRow = 0x56;
   e4g5p.capture = PAWN;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY

   // The original test incorrectly assumed that we could only make 6 moves in
   // this position. We can in fact make all 8 moves, as we can either A)
   // capture any of the pieces of the other color, or B) move to the empty
   // spaces where pieces have not been placed. The test has accordingly been
   // corrected.
   assertUnit(moves.size() == 8); // many possible moves
   assertUnit(moves.find(e4d2p) != moves.end());
   assertUnit(moves.find(e4f2p) != moves.end());
   assertUnit(moves.find(e4c3p) != moves.end());
   assertUnit(moves.find(e4g3p) != moves.end());
   assertUnit(moves.find(e4c5p) != moves.end());
   assertUnit(moves.find(e4g5p) != moves.end());
   // TEARDOWN
   board.board[4][4] = nullptr; // black knight
   board.board[2][3] = nullptr; // black pawn
   board.board[2][5] = nullptr; // black pawn
   board.board[3][2] = nullptr; // black pawn
   board.board[3][6] = nullptr; // black pawn
   board.board[5][2] = nullptr; // black pawn
   board.board[5][6] = nullptr; // black pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;

   knight.position.colRow = 0x44;
   board.board[4][4] = &knight;
   set<Move> moves;
   Move e4d2;
   e4d2.source.colRow = 0x44;
   e4d2.dest.colRow = 0x23;
   e4d2.capture = SPACE;
   Move e4f2;
   e4f2.source.colRow = 0x44;
   e4f2.dest.colRow = 0x25;
   e4f2.capture = SPACE;
   Move e4c3;
   e4c3.source.colRow = 0x44;
   e4c3.dest.colRow = 0x32;
   e4c3.capture = SPACE;
   Move e4g3;
   e4g3.source.colRow = 0x44;
   e4g3.dest.colRow = 0x36;
   e4g3.capture = SPACE;
   Move e4c5;
   e4c5.source.colRow = 0x44;
   e4c5.dest.colRow = 0x52;
   e4c5.capture = SPACE;
   Move e4g5;
   e4g5.source.colRow = 0x44;
   e4g5.dest.colRow = 0x56;
   e4g5.capture = SPACE;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY

   // The original test incorrectly assumed that we could only make 6 moves in
   // this position. We can in fact make all 8 moves, as there are **8**
   // available spaces on our sides, not just 6.
   assertUnit(moves.size() == 8); // many possible moves

   assertUnit(moves.find(e4d2) != moves.end());
   assertUnit(moves.find(e4f2) != moves.end());
   assertUnit(moves.find(e4c3) != moves.end());
   assertUnit(moves.find(e4g3) != moves.end());
   assertUnit(moves.find(e4c5) != moves.end());
   assertUnit(moves.find(e4g5) != moves.end());
   // TEARDOWN
   board.board[4][4] = nullptr; // black knight
}

/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP
   const Knight knight(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = knight.getType();

   // VERIFY
   assertUnit(pt == KNIGHT);
} // TEARDOWN
