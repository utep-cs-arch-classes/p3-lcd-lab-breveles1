#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "buzzer.h"

int loop = 1;

void gameSetup()
{
  clearScreen(COLOR_BLACK);  // draw black background
  drawString5x7(3, 152, "Player1: " , COLOR_ORANGE_RED, COLOR_BLACK);  // draw player 1 score box
  drawChar5x7(50, 152, playerScoreP, COLOR_WHITE, COLOR_BLACK);   // draw player 2 score
  drawString5x7(65, 152, "CPU: " , COLOR_ORANGE_RED, COLOR_BLACK);     // draw CPU score box
  drawChar5x7(118, 152, computerScoreP, COLOR_WHITE, COLOR_BLACK); // draw CPU score
  drawRectOutline(2, 2, drawPosF[0], drawPosF[1], COLOR_BLUE);   // draw field online
  drawRectOutline(2, drawPosF[2], drawPosF[0], .5, COLOR_WHITE);   // draw half court line
  fillRectangle(drawPosC[0], drawPosC[1], 30, 3, COLOR_WHITE);    // draw top pad
  fillRectangle(drawPosP[0], drawPosP[1], 30, 3, COLOR_WHITE);    // draw bottom pad
  drawDiamond(drawPosB[0], drawPosB[1], COLOR_WHITE);          // draw ball
}

void endGameMessage()
{
  clearScreen(COLOR_BLACK);  // black background
  if(playerScore == 6)       // score limit == 6
    {  // player 1 winner msg print
     drawString5x7(3, screenWidth/2, "PLAYER 1 IS THE WINNER!", COLOR_WHITE, COLOR_SKY_BLUE);      
     buzzer_init();  // set buzzer
     buzzer_set_period(1000);   // buzzer will go off
    }
   else if (computerScore == 6)
     {  // CPU winner msg print
      drawString5x7(3, screenWidth/2, "CPU IS THE WINNER", COLOR_WHITE, COLOR_RED);
      buzzer_init();
      buzzer_set_period(3000);  // buzzer will go off in a different frequency
    }
}

int main(void)
{
  P1DIR |= LED;    // LED will be on when the CPU is on
  P1OUT |= LED;
  
  configureClocks();
  lcd_init();         // LCD board
  switch_init();      // switches
  //buzzer_init(); --->  buzzer set at endGameMessage
  enableWDTInterrupts();         /** < enable periodic interrupt */

  or_sr(0x8);                   /**< GIE (enable interrupts) */

  // sets up court and score board
  gameSetup();
   while (loop)  // this loop will continue until someone is declared winner
    {
      if(redrawScreen)
	{
	  redrawScreen = 0;
	  update_shape();
	}
      if (playerScore == 6 || computerScore == 6)
	{
	  loop = 0;
	}
      P1OUT &= ~LED;    // LED off
      or_sr(0x10);      // CPU off
      P1OUT |= LED;     // CPU on
    }
  endGameMessage();
}
