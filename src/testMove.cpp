/******************************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    test the Move class
 *****************************************************************************/

#include "testMove.h"
#include "move.h"
#include <cassert>

/******************************************************************************
 * Constructor : default
 * Input:
 * Output: source=INVALID
 *         dest  =INVALID
 *****************************************************************************/
void TestMove::constructor_default()
{
   // SETUP
   // EXERCISE
   Move m;
   // VERIFY
   assertUnit(m.source.isInvalid());
   assertUnit(m.dest.isInvalid());
   // TEARDOWN
}

/******************************************************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *****************************************************************************/
void TestMove::constructString_simple()
{
   // SETUP
   // EXERCISE
   Move m("e5e6");
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(4, 5));
   assertUnit(m.moveType == Move::MOVE);
   // TEARDOWN
}

/******************************************************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *****************************************************************************/
void TestMove::read_simple()
{
   // SETUP
   Move m;
   // EXERCISE
   m.set("e5e6");
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(4, 5));
   assertUnit(m.moveType == Move::MOVE);
   // TEARDOWN
}

/******************************************************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 *****************************************************************************/
void TestMove::read_capture()
{
   // SETUP
   Move m;
   // EXERCISE
   m.set("e5d6r");
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(3, 5));
   assertUnit(m.capture == PieceType::ROOK);
   // TEARDOWN
}

/******************************************************************************
 * READ enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *****************************************************************************/
void TestMove::read_enpassant()
{
   // SETUP
   Move m;
   // EXERCISE
   m.set("e5f6E");
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(5, 5));
   assertUnit(m.moveType == Move::ENPASSANT);
   // TEARDOWN
}

/******************************************************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 *****************************************************************************/
void TestMove::read_castleKing()
{
   // SETUP
   Move m;
   // EXERCISE
   m.set("e1g1c");
   // VERIFY
   assertUnit(m.source == Position(4, 0));
   assertUnit(m.dest == Position(6, 0));
   assertUnit(m.moveType == Move::CASTLE_KING);
   // TEARDOWN
}

/******************************************************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 *****************************************************************************/
void TestMove::read_castleQueen()
{
   // SETUP
   Move m;
   // EXERCISE
   m.set("e1c1C");
   // VERIFY
   assertUnit(m.source == Position(4, 0));
   assertUnit(m.dest == Position(2, 0));
   assertUnit(m.moveType == Move::CASTLE_QUEEN);
   // TEARDOWN
}

/******************************************************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *****************************************************************************/
void TestMove::assign_simple()
{
   // SETUP
   Move m;
   // EXERCISE
   m = "e5e6";
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(4, 5));
   assertUnit(m.moveType == Move::MOVE);
   // TEARDOWN
}

/******************************************************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 *****************************************************************************/
void TestMove::assign_capture()
{
   // SETUP
   Move m;
   // EXERCISE
   m = "e5d6r";
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(3, 5));
   assertUnit(m.moveType == Move::MOVE);
   assertUnit(m.capture == PieceType::ROOK);
   // TEARDOWN
}

/******************************************************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *****************************************************************************/
void TestMove::assign_enpassant()
{
   // SETUP
   Move m;
   // EXERCISE
   m = "e5f6E";
   // VERIFY
   assertUnit(m.source == Position(4, 4));
   assertUnit(m.dest == Position(5, 5));
   assertUnit(m.moveType == Move::ENPASSANT);
   // TEARDOWN
}

/******************************************************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 *****************************************************************************/
void TestMove::assign_castleKing()
{
   // SETUP
   Move m;
   // EXERCISE
   m = "e1g1c";
   // VERIFY
   assertUnit(m.source == Position(4, 0));
   assertUnit(m.dest == Position(6, 0));
   assertUnit(m.moveType == Move::CASTLE_KING);
   // TEARDOWN
}

/******************************************************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 *****************************************************************************/
void TestMove::assign_castleQueen()
{
   // SETUP
   Move m;
   // EXERCISE
   m = "e1c1C";
   // VERIFY
   assertUnit(m.source == Position(4, 0));
   assertUnit(m.dest == Position(2, 0));
   assertUnit(m.moveType == Move::CASTLE_QUEEN);
   // TEARDOWN
}

/******************************************************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 *****************************************************************************/
void TestMove::getText_simple()
{
   // SETUP
   Move m;
   m.source = Position(4, 4);
   m.dest = Position(4, 5);
   m.moveType = Move::MOVE;
   // EXERCISE
   std::string text = m.getText();
   // VERIFY
   assertUnit(strcmp("e5e6", text.c_str()) == 0);
   // TEARDOWN
}

/******************************************************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 *****************************************************************************/
void TestMove::getText_capture()
{
   // SETUP
   Move m;
   m.source = Position(4, 4);
   m.dest = Position(4, 5);
   m.moveType = Move::MOVE;
   m.capture = PieceType::ROOK;
   // EXERCISE
   std::string text = m.getText();
   // VERIFY
   assertUnit(strcmp("e5e6r", text.c_str()) == 0);
   // TEARDOWN
}

/******************************************************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 *****************************************************************************/
void TestMove::getText_enpassant()
{
   // SETUP
   Move m;
   m.source = Position(4, 4);
   m.dest = Position(5, 5);
   m.moveType = Move::ENPASSANT;
   m.capture = PieceType::PAWN;
   // EXERCISE
   std::string text = m.getText();
   // VERIFY
   assertUnit(strcmp("e5f6E", text.c_str()) == 0);
   // TEARDOWN
}

/******************************************************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 *****************************************************************************/
void TestMove::getText_castleKing()
{
   // SETUP
   Move m;
   m.source = Position(4, 0);
   m.dest = Position(6, 0);
   m.moveType = Move::CASTLE_KING;
   // EXERCISE
   std::string text = m.getText();
   // VERIFY
   assertUnit(strcmp("e1g1c", text.c_str()) == 0);
   // TEARDOWN
}

/******************************************************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 *****************************************************************************/
void TestMove::getText_castleQueen()
{
   // SETUP
   Move m;
   m.source = Position(4, 0);
   m.dest = Position(2, 0);
   m.moveType = Move::CASTLE_QUEEN;
   // EXERCISE
   std::string text = m.getText();
   // VERIFY
   assertUnit(strcmp("e1c1C", text.c_str()) == 0);
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 *****************************************************************************/
void TestMove::letterFromPieceType_space()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::SPACE);
   // VERIFY
   assertUnit(p == ' ');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 *****************************************************************************/
void TestMove::letterFromPieceType_pawn()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::PAWN);
   // VERIFY
   assertUnit(p == 'p');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 *****************************************************************************/
void TestMove::letterFromPieceType_bishop()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::BISHOP);
   // VERIFY
   assertUnit(p == 'b');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 *****************************************************************************/
void TestMove::letterFromPieceType_knight()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::KNIGHT);
   // VERIFY
   assertUnit(p == 'n');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 *****************************************************************************/
void TestMove::letterFromPieceType_rook()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::ROOK);
   // VERIFY
   assertUnit(p == 'r');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 *****************************************************************************/
void TestMove::letterFromPieceType_queen()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::QUEEN);
   // VERIFY
   assertUnit(p == 'q');
   // TEARDOWN
}

/******************************************************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 *****************************************************************************/
void TestMove::letterFromPieceType_king()
{
   // SETUP
   // EXERCISE
   char p = Move::letterFromPieceType(PieceType::KING);
   // VERIFY
   assertUnit(p == 'k');
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('p');
   // VERIFY
   assertUnit(p == PieceType::PAWN);
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('b');
   // VERIFY
   assertUnit(p == PieceType::BISHOP);
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output:  KNIGHT
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('n');
   // VERIFY
   assertUnit(p == PieceType::KNIGHT);
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output:  ROOK
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('r');
   // VERIFY
   assertUnit(p == PieceType::ROOK);
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output:  QUEEN
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('q');
   // VERIFY
   assertUnit(p == PieceType::QUEEN);
   // TEARDOWN
}

/******************************************************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output:  KING
 *****************************************************************************/
void TestMove::pieceTypeFromLetter_king()
{
   // SETUP
   // EXERCISE
   char p = Move::pieceTypeFromLetter('k');
   // VERIFY
   assertUnit(p == PieceType::KING);
   // TEARDOWN
}

/******************************************************************************
 * EQUAL - NOT
 * Input : b2b4 == b2b5
 * Output: false
 *****************************************************************************/
void TestMove::equal_not()
{
   // SETUP
   Move a("b2b4");
   Move b("b2b5");
   // EXERCISE
   bool e = a == b;
   // VERIFY
   assertUnit(!e);
   // TEARDOWN
}

/******************************************************************************
 * EQUAL - EQUALS
 * Input : b2b4 == b2b4
 * Output: true
 *****************************************************************************/
void TestMove::equal_equals()
{
   // SETUP
   Move a("b2b4");
   Move b("b2b4");
   // EXERCISE
   bool e = a == b;
   // VERIFY
   assertUnit(e);
   // TEARDOWN
}

/******************************************************************************
 * LESS THAN - LESS THAN
 * Input : b2b2 < b2b4
 * Output: false
 *    Note that the less-than operator is needed
 *    so std::set<T> can sort the elements. Thus,
 *    any T in a set must define less-than. In this
 *    case, I defined it according to the
 *     destination's Position's location.
 *****************************************************************************/
void TestMove::lessthan_lessthan()
{
   // SETUP
   Move a("b2b2");
   Move b("b2b4");
   // EXERCISE
   bool lt = a < b;
   // VERIFY
   assertUnit(!lt);
   // TEARDOWN
}

/******************************************************************************
 * LESS THAN - EQUALS
 * Input : b2b4 < b2b4
 * Output: false
 *****************************************************************************/
void TestMove::lessthan_equals()
{
   // SETUP
   Move a("b2b4");
   Move b("b2b4");
   // EXERCISE
   bool lt = a < b;
   // VERIFY
   assertUnit(!lt);
   // TEARDOWN
}

/******************************************************************************
 * LESS THAN - GREATER THAN
 * Input : b2b4 < b2b2
 * Output: true
 *****************************************************************************/
void TestMove::lessthan_greaterthan()
{
   // SETUP
   Move a("b2b4");
   Move b("b2b2");
   // EXERCISE
   bool lt = a < b;
   // VERIFY
   assertUnit(lt);
   // TEARDOWN
}
