#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

// extern determined here but used somewhere else

extern short redrawScreen;
extern short drawPosP[2];
extern short drawPosC[2];
extern short drawPosF[3];
extern short drawPosB[2];
extern int playerScore;
extern int computerScore;
extern char playerScoreP;
extern char computerScoreP;
void drawDiamond(unsigned x, unsigned y, unsigned color);

  
void update_shape(void);

#endif // draws shapes 
