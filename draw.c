#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
//for origin at lower-left corner
void octant1(int x0, int y0, int x1, int y1, screen s, color c);
void octant2(int x0, int y0, int x1, int y1, screen s, color c);
void octant7(int x0, int y0, int x1, int y1, screen s, color c);
void octant8(int x0, int y0, int x1, int y1, screen s, color c);

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	if (x1<x0) {
		draw_line(x1,y1,x0,x1,s,c);
		return;	
	}

	int dy = y1-y0;
	int dx = x1-x0;

	if (dy>=dx) {octant2(x0,y0,x1,y1,s,c);}
	else if (dx>dy && dy>=0) {octant1(x0,y0,x1,y1,s,c);}
	else if (dy*-1<dx && dy<0) {octant8(x0,y0,x1,y1,s,c);}
	else {octant7(x0,y0,x1,y1,s,c);}
}
void octant1(int x0, int y0, int x1, int y1, screen s, color c) {
	int A = y1-y0;
	int B = x0-x1;
	
	int x = x0;
	int y = y0;

	int d = 2*A + B;
	while (x<=x1){
		plot(s,c,x,y);
		if (d>0) {
			y++;
			d+=2*B;
		}
		x++;
		d+=2*A;
	}
}
void octant2(int x0, int y0, int x1, int y1, screen s, color c) {

	int A = y1-y0;
	int B = x0-x1;
	
	int x = x0;
	int y = y0;

	int d = A + 2*B;
	while (y <= y1){
		plot(s,c,x,y);
		if (d<0) {
			x++;
			d+=2*A;
		}
		y++;
		d+=2*B;
	}

}
void octant8(int x0, int y0, int x1, int y1, screen s, color c) {

	int A = y1-y0;
	int B = x0-x1;
	
	int x = x0;
	int y = y0;

	int d = 2*A - B;
	while (x<=x1){
		plot(s,c,x,y);
		if (d<0) {
			y--;
			d-=2*B;
		}
		x++;
		d+=2*A;
	}
}
void octant7(int x0, int y0, int x1, int y1, screen s, color c) {
	
	int A = y1-y0;
	int B = x0-x1;
	
	int x = x0;
	int y = y0;

	int d = A - 2*B;
	while (y>=y1){
		plot(s,c,x,y);
		if (d>0) {
			x++;
			d+=2*A;
		}
		y--;
		d-=2*B;
	}
}

