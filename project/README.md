### Project 3: LCD Game/Toy
## LCD Board:
In this lab, I will be using the LCD Board. The LCD board is a seprate
attachment to the MSP430 device in which you can attach the LCD board on to
the MSP430 in which it will be able to provide a little screen where colors, shapes, texts, and
buttons can all be used and displayed on the LCD screen. On the LCD screen we are required to
move shapes, write a text, change and utilize the colors that are provided in
lcdutils.h, and change the state of the LCD screen. In addition this lab also
requires at least one function in assmebly.

## Instructions:
Furhtermore, to properly use the LCD screen I decided to make a simple game
that anyone can perhaps understand without any difficulty and is easy to catch
on. Additionally the video game consist of a simple virtual ping pong
game. The user will be able to move the ping pong paddle with the SW3 button
to move LEFT and the SW4 button to move to the RIGHT. The game consist of a
score up to six pointds. At the bottom of the left you can see the user's
score and the CPU score. Since this game is just practice for me, I have
decided to implement the SW1 buttom to purposley increment the user's score in
which the LCD screen can change stages.

## How does it run: This lab will consist
of one file being implemented by another file, these files also aquire information
about the LCD screen, such as 'h' files in which many of the sources that are being
used to draw shapes or change color of a text are already preset and ready to
be used. In more defined terms, this lab does utilize a state machine, the
state machine is used to keep an eye on the state of the LCD board and when it
changes. This lab has conisit of the following files: Makefile, buzzer.c/h,
draw_shapes.c/h, main.c, p2_interrupt_handler.c/h, switches.c/h,
wdt_c_handler.c, wdt_handler.s. The simplest way that I can explain how this
lab runs is by explaining how the code needs the users interaction in order to
proceed with the buttons and the stage of the state machine. In conclusion
once one or the other reach the score limit it will clear the screen and get
rid of the paddles, court, ball, scores, and just display a blank black screen
with the text in the middle determining who the winner is.

## Mistakes and errors:
Unfortunelty my code is not perfected, it is doing what the lab is asking for
such as the requirments and so on, however I am having a little hard time with
the buzzer and the ball hitting and bouncing back from the paddle. I am
currently still working on my code, I have tried implementing the buzzer files
but have had 0 success on the buzzer providing sounds. As to the ball just
continusely running from top to bottom without having any sort of bounce back
from the bottom paddle.
