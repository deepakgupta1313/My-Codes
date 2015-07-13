#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void floodFill(int px,int py,int oldColor,int newColor)
{
 int x=px;
 int y=py;
 if(getpixel(x,y)==oldColor && x>=0 && y>=0 && x<=getmaxx() && y<=getmaxy())
 {
  putpixel(x,y,newColor);
  floodFill(x+1,y,oldColor,newColor);
  floodFill(x,y+1,oldColor,newColor);
  floodFill(x-1,y,oldColor,newColor);
  floodFill(x,y-1,oldColor,newColor);
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
  // ymax = getmaxy();
   line(50,50,100,50);
   line(100,50,100,100);
   line(100,100,50,100);
   line(50,50,50,100);
   //printf("%d",getpixel(70,70));
   floodFill(70,70,getpixel(70,70),5);
   getch();
   closegraph();
   return 0;
}
