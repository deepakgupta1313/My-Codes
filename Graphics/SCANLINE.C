#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct edge_list{
 int ymax;
 int ymin;
 int xmin;
 int inv_m;
 struct edge_list *next;
};

struct point{
 int x;
 int y;
};

struct edge{
 struct point *start;
 struct point *end;
 int ymin;
 int xmin;
 int xymin;
 int ymax;
 float inv_m;
 int status;
};

float getp(int x1,int y1,int x2,int y2)
{
 float dx=x2-x1;
 float dy=y2-y1;
 float adx=abs(dx);
 float ady=abs(dy);
 float p;

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
 }
 else
 {
  p=2*dx-dy;
 }
 return p;
}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;
   int xs[]={200,100,250,350,300,270};
   int ys[]={400,200,50,170,350,280};
   int n=sizeof(xs)/sizeof(*xs);
   int i=0,j=0;
   float inverse_m[6];
   struct point *points[6];
   struct point *sortedy[6];
   struct point *sortedx[6];
   struct edge *edges[6];
   float p=0;

   for(i=0;i<n;i++)
   {
    points[i]=(struct point *)malloc(sizeof(struct point));
    points[i]->x=xs[i];
    points[i]->y=ys[i];
   }

   initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");

   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());

   for(i=0;i<n;i++)
   {
    if(i==(n-1))
    {
     line(xs[i],ys[i],xs[0],ys[0]);
    }
    else
    {
     line(xs[i],ys[i],xs[i+1],ys[i+1]);
    }
   }
   printf("%d\n",n);

   for(i=0;i<n;i++)
   {
    if(i==(n-1))
    {
     inverse_m[i]=(xs[i]-xs[0])/((float)(ys[i]-ys[0]));
    }
    else
    {
     inverse_m[i]=(xs[i]-xs[i+1])/((float)(ys[i]-ys[i+1]));
    }
   }

   for(i=0;i<n;i++)
   {
    printf("%d , %d\n",points[i]->x,points[i]->y);
   }

   for(i=0;i<n;i++)
   {
    edges[i]=(struct edge *)malloc(sizeof(struct edge));
    edges[i]->start=points[i];
    if(i==n-1)
    {
      edges[i]->end=points[0];
    }
    else
    {
     edges[i]->end=points[i+1];
    }
    edges[i]->inv_m=inverse_m[i];

    if((edges[i]->end->x)>(edges[i]->start->x))
    {
     edges[i]->xmin=edges[i]->start->x;
    }
    else
    {
     edges[i]->xmin=edges[i]->end->x;
    }

    if((edges[i]->end->y)>(edges[i]->start->y))
    {
     edges[i]->ymin=edges[i]->start->y;
     edges[i]->xymin=edges[i]->start->x;
    }
    else
    {
     edges[i]->ymin=edges[i]->end->y;
     edges[i]->xymin=edges[i]->end->x;
    }

    edges[i]->status=0;
   }

   for(i=0;i<n;i++)
   {
     struct edge *first=edges[i];
     struct edge *second;
     if(i==n-1)
     {
       second=edges[0];
     }
     else
     {
      second=edges[i+1];
     }

     if(first->start->y>first->end->y && second->end->y<second->start->y)
     {
      struct point *temp=(struct point*)malloc(sizeof(struct point));
      temp->y=second->start->y+1;

      p=getp(first->end->x,first->end->y,first->start->x,first->start->y);

      if(p>0)
      {
       if(first->end->x>first->start->x)
       {
	temp->x=first->end->x-1;
       }
       else
       {
	temp->x=first->end->x+1;
       }
      }
      else
      {
       temp->x=first->end->x;
      }
      first->end=temp;
     }
     else if(first->start->y<first->end->y && second->end->y>second->start->y)
     {
      struct point *temp=(struct point*)malloc(sizeof(struct point));
      temp->y=first->end->y+1;

      p=getp(second->start->x,second->start->y,second->end->x,second->end->y);

      if(p>0)
      {
	if(second->end->x>second->start->x)
	{
	  temp->x=second->start->x+1;
	}
	else
	{
	  temp->x=second->start->x-1;
	}
      }
      else
      {
       temp->x=second->start->x;
      }

      second->start=temp;
     }
   }

   for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
    {
     if(edges[j]->ymin>edges[j+1]->ymin)
     {
      struct edge *temp=edges[j];
      edges[j]=edges[j+1];
      edges[j+1]=temp;
     }
     else if(edges[j]->ymin==edges[j+1]->ymin)
     {
       if(edges[j]->xmin>edges[j+1]->xmin)
       {
	 struct edge *temp=edges[j];
	 edges[j]=edges[j+1];
	 edges[j+1]=temp;
       }
     }
    }
   }

   for(i=0;i<n;i++)
   {
    printf("startx=%d  ,  starty=%d  endx=%d  ,  endy=%d  xmin=%d  ,  ymin=%d xymin=%d \n ",edges[i]->start->x,edges[i]->start->y,edges[i]->end->x,edges[i]->end->y,edges[i]->xmin,edges[i]->ymin,edges[i]->xymin);
   }

   getch();
   closegraph();
   return 0;
}
