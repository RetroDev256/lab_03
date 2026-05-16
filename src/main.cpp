/******************************************************************************
 * Source File:
 *    MAIN
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    Launches the unit tests - that is all!
 *****************************************************************************/

#include "board.h"
#include "pieceKnight.h"
#include "position.h"
#include "test.h"
#include "uiDraw.h"
#include "uiInteract.h"

/******************************************************************************
 * Rendering callback function
 *****************************************************************************/
void callback(Interface *interface, void *context)
{
   const Position hover = interface->getHoverPosition();
   const Position select = interface->getSelectPosition();

   Board *board = (Board *)context;
   board->display(hover, select);
}

/******************************************************************************
 * MAIN
 * There can be only one!
 *****************************************************************************/
int main()
{
   // run the test code.
   testRunner();

   // create the interface & increase framerate
   Interface interface("Chess");
   interface.setFramesPerSecond(60);

   // create the board
   ogstream pgout;
   Board board(&pgout);

   const Position knight_pos_a = Position(1, 0);
   Knight *k_a = new Knight(knight_pos_a, true);
   board.setPiece(knight_pos_a, k_a);

   const Position knight_pos_b = Position(6, 0);
   Knight *k_b = new Knight(knight_pos_b, true);
   board.setPiece(knight_pos_b, k_b);

   const Position knight_pos_c = Position(1, 7);
   Knight *k_c = new Knight(knight_pos_c, false);
   board.setPiece(knight_pos_c, k_c);

   const Position knight_pos_d = Position(6, 7);
   Knight *k_d = new Knight(knight_pos_d, false);
   board.setPiece(knight_pos_d, k_d);

   // Start the rendering loop
   interface.run(callback, &board);

   // return success
   return 0;
}
