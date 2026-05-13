/******************************************************************************
 * Source File:
 *    MAIN
 * Author:
 *    Eric Petersen & Briant Woolley
 * Summary:
 *    Launches the unit tests - that is all!
 *****************************************************************************/

#include "position.h"
#include "test.h"

/******************************************************************************
 * MAIN
 * There can be only one!
 *****************************************************************************/
int main()
{
   // run the test code.
   testRunner();

   // return success
   return 0;
}

// TICKET 1: 10 minutes
// TICKET 2: 20 minutes
// TICKET 3: 30 minutes
// TICKET 4: 10 minutes
// TICKET 5: 30 minutes
// TICKET 6: 5 minutes
// TICKET 7: 5 minutes

// YOUTUBE LINK: https://youtu.be/XYjMBXg1Xv4

// The test instances setXY_invalidXMax and setXY_invalidXMin were modified as
// the assumptions for the behavior of setXY (from the tests) implied that the
// order of evaluation of setting X versus setting Y mattered, or the functions
// to set X or set Y were not the same. In other words, the tests implied wrong
// code.