#include "draw_shapes.h"
#include "switches.h"

// global var
// 0 -> col ; 1 -> row

short drawPosP[2] = {(screenWidth / 2)-15, screenHeight-16};
short drawPosC[2] = {(screenWidth / 2)-15, 5};
short drawPosF[3] = {screenWidth-5, screenHeight-13, (screenHeight-15)/2};  // will draw court
short drawPosB[2] = {(screenWidth/2)-6, ((screenHeight-15)/2)-5}; // vertical | horizontal
short redrawScreen = 1;
int playerScore = 0, computerScore = 0;
char playerScoreP = 48, computerScoreP = 48;

//local var
short velocity[3] = {6, 10, 15};
short limits[4] = {3, screenWidth-4, 8, screenHeight-17}; // left | right | top | bottom.
int directionC = 0;           // 0 = left ; 1 = right
int directionB[2] = {0, 0};  // up | down ; left | right ; 0 -> left | down ; 1 -> right | up.
short drawPosBN[2] = {(screenWidth/2)-6, ((screenHeight-15)/2)-5};  // vertical | horizontal

void drawDiamond(unsigned x, unsigned y, unsigned color)
{
  fillRectangle(x,y,5,5,color);
}
void
update_shape(void)
{
  drawDiamond(drawPosB[0], drawPosB[1],  COLOR_BLACK);   // will draw ball
  drawPosB[1] = drawPosB[1] + velocity[2];
  drawDiamond(drawPosB[0], drawPosB[1],  COLOR_WHITE);    // will draw ball
  drawRectOutline(2, drawPosF[2], drawPosF[0], .5, COLOR_WHITE);  // will draw half court line    
  if(directionB[0] = 0)
    {
      drawPosBN[1] = drawPosB[1] + velocity[2];
      if (drawPosBN[1] >= drawPosP[0] && drawPosBN[1] <= drawPosP[0] +30)
	{
	  directionB[0] = 1;
	  drawDiamond(drawPosB[0], drawPosB[1], COLOR_BLACK);      // will draw ball
	  drawPosB[1] = drawPosB[1] - velocity[2];    // should produce sound?
	  drawDiamond(drawPosB[0], drawPosB[1], COLOR_WHITE);  // Draw ball white
	}
      else
	{
	  // DELETE THIS: did not hit paddle
	}
    }

  if(directionC == 0)                //will check to see if CPU paddle goes left
    {
  if(drawPosC[0] - velocity[1] <= limits[0])  //if the ball is out, print out the change of dic
	{
	directionC =1;
	}
  else
    {
      fillRectangle(drawPosC[0], drawPosC[1], 30, 3, COLOR_BLACK);
      drawPosC[0] = drawPosC[0] - velocity[1];
      fillRectangle(drawPosC[0], drawPosC[1], 30, 3, COLOR_WHITE);
    }
    }
  else if (directionC == 1)           // will check if CPU paddle goes right
    {
      if(drawPosC[0] + velocity[1] + 30 >= limits[1])  // if the ball is out, print over screen chg
	{
	  directionC = 0;
	}
      else
	{
	  fillRectangle(drawPosC[0], drawPosC[1], 30, 3, COLOR_BLACK);
	  drawPosC[0] = drawPosC[0] + velocity[1];
	  fillRectangle(drawPosC[0], drawPosC[1], 30, 3, COLOR_WHITE);
	}
    }
  if(switch4_down && (drawPosP[0] + velocity[0] + 30) <= limits[1]) //will check if player can go R
    {
      fillRectangle(drawPosP[0], drawPosP[1], 30, 3, COLOR_BLACK);
      drawPosP[0] = drawPosP[0] + velocity[0];
      fillRectangle(drawPosP[0], drawPosP[1], 30, 3, COLOR_WHITE);
    }
  if(switch3_down && (drawPosP[0] - velocity[0]) >= limits[0]) //will check if player can go L
    {
      fillRectangle(drawPosP[0], drawPosP[1], 30, 3, COLOR_BLACK);
      drawPosP[0] = drawPosP[0] - velocity[0];
      fillRectangle(drawPosP[0], drawPosP[1], 30, 3, COLOR_WHITE);
    }
  if(switch1_down){                             // will increment the score for the player
                                                // to automatcilly win 
    playerScore++;
    playerScoreP++;
    drawChar5x7(50, 152, playerScoreP, COLOR_WHITE, COLOR_BLACK);

    if(switch2_down){
    computerScore++;
    computerScoreP++;
    drawChar5x7(50, 152, playerScoreP, COLOR_WHITE, COLOR_BLACK);
    }
  }
}
