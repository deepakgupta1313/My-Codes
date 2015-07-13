#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void dda(int x1,int y1,int x2,int y2)
{
 float x=x1;
 float y=y1;
 int steps;
 float incrementx=0;
 float incrementy=0;

 if(abs(y2-y1)>abs(x2-x1))
 {
  steps=abs(y2-y1);
 }
 else
 {
  steps=abs(x2-x1);
 }

 incrementx=(x2-x1)/(float)steps;
 incrementy=(y2-y1)/(float)steps;
 putpixel((int)x,(int)y,15);
 while(steps>0)
 {
   x=x+incrementx;
   y=y+incrementy;
   putpixel((int)x,(int)y,15);
   steps--;
 }
}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());
   //xmax = getmaxx();
   //ymax = getmaxy();

   /* draw a diagonal line */
  // line(0, 0, xmax, ymax);
    dda(500,400,100,50);
   /* clean up */
   getch();
   closegraph();
   return 0;
}
