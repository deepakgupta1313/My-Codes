#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void ltwo(int x0,int y0,int x1,int y1,int x2,int y2,int t)
{
 float x=x0;
 float y=y0;
 int steps=t;
 float incrementx=0;
 float incrementy=0;
 float dx=x2-x1;
 float dy=y2-y1;
 float adx=abs(dx);
 float ady=abs(dy);
 float p;

 putpixel((int)x,(int)y,15);

 if(dx!=0)
 {
  incrementx=dx/(float)adx;
 }
 if(dy!=0)
 {
  incrementy=dy/(float)ady;
 }

 if(dx<0)
  {
   dx=-dx;
  }
  if(dy<0)
  {
   dy=-dy;
  }

 if(adx>ady)
 {
  p=2*dy-dx;

  while(steps>0)
  {
   x=x+incrementx;
   if(p>0)
   {
    y=y+incrementy;
    p=p+2*(dy-dx);
   }
   else
   {
    p=p+2*dy;
   }

    putpixel((int)x,(int)y,15);

   steps--;
  }
 }
 else
 {
  p=2*dx-dy;
  while(steps>0)
  {
   y=y+incrementy;
   if(p>0)
   {
    x=x+incrementx;
    p=p+2*(dx-dy);
   }
   else
   {
    p=p+2*dx;
   }
    putpixel((int)x,(int)y,15);
    steps--;
  }
 }
}



void line_Bresenham(int x1,int y1,int x2,int y2,int solids, int blanks,int t)
{
 float x=x1;
 float y=y1;
 int steps;
 float incrementx=0;
 float incrementy=0;
 float dx=x2-x1;
 float dy=y2-y1;
 float adx=abs(dx);
 float ady=abs(dy);
 float p;
 int sl=solids;
 int bl=0;
 int l,r;

 --t;
 l=t/2;
 r=t-l;
 putpixel((int)x,(int)y,15);
 --sl;
 if(sl==0)
 {
  bl=blanks;
 }

 if(dx!=0)
 {
  incrementx=dx/(float)adx;
 }
 if(dy!=0)
 {
  incrementy=dy/(float)ady;
 }

 if(dx<0)
  {
   dx=-dx;
  }
  if(dy<0)
  {
   dy=-dy;
  }

 if(adx>ady)
 {
  steps=adx;
  p=2*dy-dx;

  while(steps>0)
  {
   x=x+incrementx;
   if(p>0)
   {
    y=y+incrementy;
    p=p+2*(dy-dx);
   }
   else
   {
    p=p+2*dy;
   }

   if(sl>0)
   {
    putpixel((int)x,(int)y,15);
    ltwo((int)x,(int)y,x1,y2,x2,y1,r);
    ltwo((int)x,(int)y,x2,y1,x1,y2,l);
    --sl;
    if(sl==0)
    {
     bl=blanks;
    }
   }
   else if(bl>0)
   {
    --bl;
    if(bl==0)
    {
     sl=solids;
    }
   }
   steps--;
  }
 }
 else
 {
  steps=ady;
  p=2*dx-dy;
  while(steps>0)
  {
   y=y+incrementy;
   if(p>0)
   {
    x=x+incrementx;
    p=p+2*(dx-dy);
   }
   else
   {
    p=p+2*dx;
   }
   if(sl>0)
   {
    putpixel((int)x,(int)y,15);
    ltwo((int)x,(int)y,x1,y2,x2,y1,r);
    ltwo((int)x,(int)y,x2,y1,x1,y2,l);
    --sl;
    if(sl==0)
    {
     bl=blanks;
    }
   }
   else if(bl>0)
   {
    //printf("B");
    --bl;
    if(bl==0)
    {
     sl=solids;
    }
   }
   steps--;
  }
 }
}



int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;
   //int solids=2;
   //int blanks=2;

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

   /* draw a diagonal line */
  // line(0, 0, xmax, ymax);
    //line_Bresenham(200,400,100,200);
    //line_Bresenham(100,200,250,50);
    //line_Bresenham(250,50,350,170);
    //line_Bresenham(350,170,300,350);
    //line_Bresenham(300,350,270,280);
    //line_Bresenham(270,280,200,400);


    line_Bresenham(100,200,200,400,10,5,10);
    line_Bresenham(250,50,100,200,10,5,10);
    line_Bresenham(350,170,250,50,10,5,10);
    line_Bresenham(300,350,350,170,10,5,10);
    line_Bresenham(270,280,300,350,10,5,10);
    line_Bresenham(200,400,270,280,10,5,10);

    line_Bresenham(100,50,400,200,10,5,10);
    //line(400,50,100,400);

    //line(200,400,100,200);
    //line(100,200,250,50);
    //line(250,50,350,170);
    //line(350,170,300,350);
    //line(300,350,270,280);
    //line(270,280,200,400);
   getch();
   closegraph();
   return 0;
}
