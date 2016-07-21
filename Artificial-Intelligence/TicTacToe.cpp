#include<iostream>

using namespace std;

static int board[9];
static int move=1;

void printState()
{
 for(int i=0;i<9;i++)
 {
  if((i%3)!=0 || i==0)
  {
   cout<<board[i];
   cout<<"\t";        
  }
  else
  {
   cout<<endl<<endl;
   cout<<board[i];
   cout<<"\t"; 
  }
 }
 cout<<endl<<endl;     
}

bool checkWin(int player)
{
 if(player==1)
 {
  //          ROWS
  for(int i=0;i<=6;i+=3)
  {
   if(board[i]*board[i+1]*board[i+2]==27)
   {
    return true;    
   }
  }
  
  //       COLUMNS
  for(int i=0;i<3;i++)
  {
   if(board[i]*board[i+3]*board[i+6]==27)
   {
   
    return true;
                                         
   }        
  }
  
  //        DIAGONALS
  
  if(board[2]*board[4]*board[6]==27)
  {
  
    return true;
  
  }
  
  if(board[0]*board[4]*board[8]==27)
  {
  
    return true;
  
  }
  
  return 0;             
 }
 
 else
 {
  //          ROWS
  for(int i=0;i<=6;i+=3)
  {
   if(board[i]*board[i+1]*board[i+2]==125)
   {
    return true;   
   }
  }
  
  //       COLUMNS
  for(int i=0;i<3;i++)
  {
   if(board[i]*board[i+3]*board[i+6]==125)
   {
   
    return true;
                                         
   }        
  }
  
  //        DIAGONALS
  
  if(board[2]*board[4]*board[6]==125)
  {
  
    return true;
  
  }
  
  if(board[0]*board[4]*board[8]==125)
  {
  
    return true;
  
  }  
  return false;     
 }
}

int PosWin(int player)
{
 if(player==1)
 {
  //          ROWS
  for(int i=0;i<=6;i+=3)
  {
   if(board[i]*board[i+1]*board[i+2]==18)
   {
    if(board[i]==2)
    return i+1;
    
    if(board[i+1]==2)
    return i+2;
    
    if(board[i+2]==2)
    return i+3;    
   }
  }
  
  //       COLUMNS
  for(int i=0;i<3;i++)
  {
   if(board[i]*board[i+3]*board[i+6]==18)
   {
   
    if(board[i]==2)
    return i+1;
    
    if(board[i+3]==2)
    return i+4;
    
    if(board[i+6]==2)
    return i+7;
                                         
   }        
  }
  
  //        DIAGONALS
  
  if(board[2]*board[4]*board[6]==18)
  {
  
    if(board[2]==2)
    return 3;
    
    if(board[4]==2)
    return 5;
    
    if(board[6]==2)
    return 7;
  
  }
  
  if(board[0]*board[4]*board[8]==18)
  {
  
    if(board[0]==2)
    return 1;
    
    if(board[4]==2)
    return 5;
    
    if(board[8]==2)
    return 9;
  
  }
  
  return 0;             
 }
 
 else
 {
  //          ROWS
  for(int i=0;i<=6;i+=3)
  {
   if(board[i]*board[i+1]*board[i+2]==50)
   {
    if(board[i]==2)
    return i+1;
    
    if(board[i+1]==2)
    return i+2;
    
    if(board[i+2]==2)
    return i+3;    
   }
  }
  
  //       COLUMNS
  for(int i=0;i<3;i++)
  {
   if(board[i]*board[i+3]*board[i+6]==50)
   {
   
    if(board[i]==2)
    return i+1;
    
    if(board[i+3]==2)
    return i+4;
    
    if(board[i+6]==2)
    return i+7;
                                         
   }        
  }
  
  //        DIAGONALS
  
  if(board[2]*board[4]*board[6]==50)
  {
  
    if(board[2]==2)
    return 3;
    
    if(board[4]==2)
    return 5;
    
    if(board[6]==2)
    return 7;
  
  }
  
  if(board[0]*board[4]*board[8]==50)
  {
  
    if(board[0]==2)
    return 1;
    
    if(board[4]==2)
    return 5;
    
    if(board[8]==2)
    return 9;
  
  }  
  return 0;     
 }
}

int make2(int player)
{
 if(player==1)
 {
   if(board[6]==3)
   {
    if(board[1]==2)
    {
     return 3;
    }
    if(board[7]==2)
    {
     return 9;
    }
   }
   
   
   if(board[2]==3)
   {
    if(board[3]==2)
    {
     return 7;
    }
    if(board[5]==2)
    {
     return 9;
    }
   }
                  
 }    
}

void go(int position,int turn)
{
 if(turn==1)
 {
  board[position-1]=3;
  printState();
 }
 else
 {
  board[position-1]=5;
  printState();
 }
}
void computerC(int move)
{
 int pos=0;
 if(move==1)
 {
  pos=1;
  go(pos,1);
  return;
 }
 else if(move==3)
 {
  if(board[1]==5 || board[7]==5 || board[8]==5)
  {
   //cout<<"DDDDDD";
   pos=7;
   go(pos,1);
   return;
  }
  if(board[4]==5 || board[2]==5 || board[6]==5 )
  {
   pos=9;
   go(pos,1);
   return;
  }
  else
  {
   pos=3;
   go(pos,1);
   return;
  }  
 }
 
 else if(move==5)
 {
  pos=PosWin(1);
  if(pos==0)
  {
   pos=PosWin(2);
  }
  if(pos==0)
  {
   pos=make2(1);
  }
  go(pos,1);
 }
 
 else if(move==7)
 {
  pos=PosWin(1);
  if(pos==0)
  {
   pos=PosWin(2);
  }
  if(pos==0)
  {
   for(int i=0;i<9;i++)
   {
    if(board[i]==2)
    {
     pos=i+1;
     break;
    }
   }
  }
  go(pos,1);
 }
 
 else if(move==9)
 {
  for(int i=0;i<9;i++)
  {
   if(board[i]==2)
   {
    go(i+1,1);
    return;
   }
  }
 }
}

void human(int turn)
{
 int position=0;
 while(true)
 {
  cout<<"Your Move"<<endl;
  cin>>position;
  
  if(cin.fail())
  {
   cout<<"Invalid Input"<<endl;
   //Clear the fail state.
   cin.clear();
   //Ignore the rest of the wrong user input, till the end of the line.
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   continue;
  }
  else if(position<1 || position>9)
  {
   cout<<"Invalid Input"<<endl;
  }
  else if(board[position-1]!=2)
  {
   cout<<"Invalid Input"<<endl;
  }
  else if(board[position-1]==2)
  {
   go(position,turn);
   break;
  } 
 }
}

void computerH(int move)
{
 int pos=0;
 if(move==2)
 {
  if(board[4]==2)
  {
   pos=5;
  }
  else
  {
   pos=1;
  }
 }
 
 
 if(move==4)
 {
  pos=0;
  pos=PosWin(1);
  if(pos==0)
  {
   if(board[1]==2 && board[7]==2)
   {
    pos=2;
   }
   else if(board[3]==2 && board[5]==2)
   {
    pos=4; 
   }
   else if(board[1]==3 && board[5]==3)
   {
    pos=1;
   }
   
   else if(board[5]==3 && board[7]==3)
   {
    pos=3;
   }
   
   else if(board[7]==3 && board[3]==3)
   {
    pos=1;
   }
   
   else if(board[3]==3 && board[1]==3)
   {
    pos=3;
   } 
  }
 }
 
 
 if(move==6)
 {
  pos=0;
  pos=PosWin(2);
  if(pos==0)
  {
   pos=PosWin(1);
  }
  if(pos==0)
  {
      if(board[1]==3 && board[5]==3 && board[7]==3)
      {
       pos=1;
      }
      
      else if(board[5]==3 && board[7]==3 && board[3]==3)
      {
       pos=1;
      }
      
      else if(board[7]==3 && board[3]==3 && board[1]==3)
      {
       pos=3;
      }
      
      else if(board[3]==3 && board[1]==3 && board[5]==3)
      {
       pos=7;
      }      
  }
 }
 
 
 if(move==8)
 {
  pos=0;
  pos=PosWin(2);
  if(pos==0)
  {
   pos=PosWin(1);
  }
  if(pos==0)
  {
   for(int i=0;i<9;i++)
   {
    if(board[i]==2)
    {
     pos=i+1;
    }
   }            
  }  
 }
 
 
 go(pos,2);
}

void firstComputer()
{
 bool draw=true;
 
 cout<<"MOVE  "<<move<<endl;
 
 while(move<=9)
 {
  if((move%2)!=0)
  {
   computerC(move);
   if(checkWin(1))
   {
    draw=false;
    cout<<"Computer Wins"<<endl;
    break;
   }
  }
  else
  {
   human(2);
   if(checkWin(2))
   {
    draw=false;
    cout<<"You Win"<<endl;
    break;
   }
  }
  ++move;              
 }
 if(draw)
 {
  cout<<"The game is a draw"<<endl;
 }
}

void firstHuman()
{
 bool draw=true;
 
 while(move<=9)
 {
  if(move%2!=0)
  {
   human(1);
   if(checkWin(1))
   {
    draw=false;
    cout<<"You Win"<<endl;
    break;
   }
  }
  
  else
  {
   computerH(move);
   if(checkWin(2))
   {
    draw=false;
    cout<<"Computer Wins"<<endl;
    break;
   }   
  }              
 
  ++move;
 }
 
 if(draw)
 {
  cout<<"The game is a draw"<<endl;
 }
}

int main()
{
 int turn=0;
 
 for(int i=0;i<9;i++)
 {
   board[i]=2;        
 }
 
 printState();
 
 while(true)
 {
  cout<<"Press 1 to go first else 2."<<endl;          
  cin>>turn;
  
  if(cin.fail())
  {
   cout<<"Invalid Input"<<endl;
   //Clear the fail state.
   cin.clear();
   //Ignore the rest of the wrong user input, till the end of the line.
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   continue;
  }
  else if(turn==1)
  {
   cout<<"You chose to go first."<<endl;
   break;
  }
  else if(turn==2)
  {
    cout<<"You chose to go second."<<endl;
    break;    
  }
  else
  {
   cout<<"Invalid Input"<<endl;      
  }
 }
 
 if(turn==1)
 {
  firstHuman();
 }
 
 else
 {
  firstComputer();    
 }
 
 cin.get();
 cin.get();
 return 0;
    
}
