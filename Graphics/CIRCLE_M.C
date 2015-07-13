#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void circle_MidPoint(int cx,int cy,int r)
{
 float x=0;
 float y=r;
 int steps;
 float d;

 putpixel(x+cx,y+cy,15);
 putpixel(y+cx,x+cy,15);
 putpixel(x+cx,-y+cy,15);
 putpixel(-y+cx,x+cy,15);

 d=((float)5/4)-r;
 while(x<=y)
 {
  x=x+1;
  if(d<0)
  {
    d=d+2*x+1;
  }
  else
  {
   y=y-1;
   d=d+2*(x-y)+1;
  }
  putpixel(x+cx,y+cy,15);
  putpixel(y+cx,x+cy,15);
  putpixel(y+cx,-x+cy,15);
  putpixel(x+cx,-y+cy,15);
  putpixel(-x+cx,-y+cy,15);
  putpixel(-y+cx,-x+cy,15);
  putpixel(-y+cx,x+cy,15);
  putpixel(-x+cx,y+cy,15);
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

   circle_MidPoint(100,100,100);
   circle(100,100,100);
   getch();
   closegraph();
   return 0;
}
