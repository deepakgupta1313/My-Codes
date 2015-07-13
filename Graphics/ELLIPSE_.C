#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void ellipse_MidPoint(int cx,int cy,int a,int b)
{
 float x=0;
 float y=b;
 float p;

 putpixel(x+cx,y+cy,15);
 //putpixel(a+cx,x+cy,15);
 putpixel(x+cx,-y+cy,15);
 //putpixel(-a+cx,x+cy,15);

 p=b*b-a*a*b+(a*a)/(float)4;

 //Region 1
 while((2*a*a*y)>(2*b*b*x))
 {
  x=x+1;
  if(p<0)
  {
    p=p+2*b*b*x+3*b*b;
  }
  else
  {
   y=y-1;
   p=p+2*b*b*x+b*b-2*a*a*y;
  }
  putpixel(x+cx,y+cy,15);
  putpixel(x+cx,-y+cy,15);
  putpixel(-x+cx,-y+cy,15);
  putpixel(-x+cx,y+cy,15);
 }

 p=b*b*(0+(1/(float)2))*(x+(1/(float)2))+a*a*(b-1)*(b-1)-a*a*b*b;

 //Region 2
 while(y>0)
 {
  y=y-1;
  if(p>0)
  {
   p=p-2*a*a*y+a*a;
  }
  else
  {
   x=x+1;
   p=p+2*b*b*x-2*a*a*y+a*a;
  }
  putpixel(x+cx,y+cy,15);
  putpixel(x+cx,-y+cy,15);
  putpixel(-x+cx,-y+cy,15);
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

   ellipse_MidPoint(200,200,100,60);
   getch();
   closegraph();
   return 0;
}
