/******************************************************************************
 * Source File:
 *    MAIN
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    Launches the unit tests - that is all!
 *****************************************************************************/

#include "board.h"
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

   // create the interface
   Interface interface("Chess");

   // create the board
   ogstream pgout;
   Board board(&pgout);

   // Start the rendering loop
   interface.run(callback, &board);

   // return success
   return 0;
}
