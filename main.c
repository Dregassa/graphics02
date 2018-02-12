#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

	screen s;
	color c;

	c.red = 0;
	c.green = MAX_COLOR;
	c.blue = 0;
	clear_screen(s);
	
	draw_line(0,0,300,200,s,c); //octant1
	draw_line(0,0,300,400,s,c); //octant2
	draw_line(300,0,0,200,s,c); //octant8
	draw_line(0,400,300,0,s,c); //octant7


	draw_line(10,0,10,450,s,c);//vertical
	draw_line(0,10,450,10,s,c);//horizontal
	draw_line(10,10,400,400,s,c);//m=1
	draw_line(20,400,400,20,s,c);//m=-1

	display(s);
	save_extension(s, "lines.png");
}
