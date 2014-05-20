/*
        Goal State

        1 2 3
        8 0 4
        7 6 5

        Score is based on manhattan distance from correct position

*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

#define i64 long long
#define pb push_back

int correct_xy[9][2];




struct game
{
    int arr[3][3];
    int score;
    int zero_posx,zero_posy;

    game()
    {

    }

    game(int **a)
    {
        int i,j;

        for(i=0;i<3;++i)
        {
            for(j=0;j<3;++j)
            {
                arr[i][j]=a[i][j];
                if(a[i][j]==0)
                {
                    zero_posx=i;
                    zero_posy=j;
                }
            }
        }

        //calc_score();
    }

    game(game *a)
    {
        int i,j;

        for(i=0;i<3;++i)
        {
            for(j=0;j<3;++j)
            {
                arr[i][j]=a->arr[i][j];
                if(a->arr[i][j]==0)
                {
                    zero_posx=i;
                    zero_posy=j;
                }
            }
        }
    }

    void calc_score()
    {
        int i,j;
        score=0;

        for(i=0;i<3;++i)
        {
            for(j=0;j<3;++j)
            {
                score+=abs(i-correct_xy[arr[i][j]][0]);
                score+=abs(j-correct_xy[arr[i][j]][1]);
            }
        }
    }

    int get_score()
    {
        return score;
    }

    bool operator<(game game2)
    {
        return this->score<game2.score;
    }


    void swapp(game *a,int oldx,int oldy,int newx,int newy)
    {
        int temp=a->arr[oldx][oldy];
        a->arr[oldx][oldy]=a->arr[newx][newy];
        a->arr[newx][newy]=temp;
    }

    game *move_left()
    {
        game *ret=NULL;

        if(this->zero_posy!=0)
        {
            ret=new game(this);
            swapp(ret,zero_posx,zero_posy,zero_posx,zero_posy-1);
            ret->zero_posy-=1;
            ret->calc_score();
        }

        return ret;
    }

    game *move_up()
    {
        game *ret=NULL;

        if(this->zero_posx!=0)
        {
            ret=new game(this);
            swapp(ret,zero_posx,zero_posy,zero_posx-1,zero_posy);
            ret->zero_posx-=1;
            ret->calc_score();
        }

        return ret;
    }

    game *move_right()
    {
        game *ret=NULL;

        if(this->zero_posy!=2)
        {
            ret=new game(this);
            swapp(ret,zero_posx,zero_posy,zero_posx,zero_posy+1);
            ret->zero_posy+=1;
            ret->calc_score();
        }

        return ret;
    }

    game *move_down()
    {
        game *ret=NULL;

        if(this->zero_posx!=2)
        {
            ret=new game(this);
            swapp(ret,zero_posx,zero_posy,zero_posx+1,zero_posy);
            ret->zero_posx+=1;
            ret->calc_score();
        }

        return ret;
    }

    void display()
    {
        printf("%d\n",get_score());

        int i,j;

        for(i=0;i<3;++i)
        {
            for(j=0;j<3;++j)
            {
                printf("%d\t",arr[i][j]);
            }
            printf("%\n");
        }

        printf("%\n\n\n\n");
    }

};





struct cmp
{
    bool operator()(game *a,game *b)
    {
        return a->get_score()>b->get_score();
    }
};


priority_queue<game *,vector<game *>,cmp> game_queue;
vector<game *> all_states;

bool is_equal_state(game *a,game *b)
{
    bool ret=true;

    int i,j;

    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            if(a->arr[i][j]!=b->arr[i][j])
            {
                ret=false;
                break;
            }
        }
        if(!ret)
        {
            break;
        }
    }

    return ret;
}

bool is_already_generated(game *a)
{
    int sz=all_states.size(),i;
    bool ret=false;
    for(i=0;i<sz;++i)
    {
        if(is_equal_state(a,all_states[i]))
        {
            ret=true;
            break;
        }
    }

    return ret;
}




void init()
{
    correct_xy[0][0]=1;
    correct_xy[0][1]=1;
    correct_xy[1][0]=0;
    correct_xy[1][1]=0;
    correct_xy[2][0]=0;
    correct_xy[2][1]=1;
    correct_xy[3][0]=0;
    correct_xy[3][1]=2;
    correct_xy[4][0]=1;
    correct_xy[4][1]=2;
    correct_xy[5][0]=2;
    correct_xy[5][1]=2;
    correct_xy[6][0]=2;
    correct_xy[6][1]=1;
    correct_xy[7][0]=2;
    correct_xy[7][1]=0;
    correct_xy[8][0]=1;
    correct_xy[8][1]=0;
}



int main()
{
    freopen("Eight Puzzle.txt","r",stdin);
    init();

    int i,j;
    game *curr=new game();


    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            //printf("DD\n");
            scanf("%d",&(curr->arr[i][j]));
            if(curr->arr[i][j]==0)
            {
                curr->zero_posx=i;
                curr->zero_posy=j;
            }
        }
    }



    curr->calc_score();

    game_queue.push(curr);
    all_states.pb(curr);


    while(!game_queue.empty())
    {

        curr=game_queue.top();
        game_queue.pop();

        curr->display();

        if(curr->get_score()==0)
        {
            break;
        }

        game *mov;

        mov=curr->move_left();
        if(mov!=NULL && !is_already_generated(mov))
        {
            game_queue.push(mov);
            all_states.pb(mov);
        }

        mov=curr->move_up();
        if(mov!=NULL && !is_already_generated(mov))
        {
            game_queue.push(mov);
            all_states.pb(mov);
        }

        mov=curr->move_right();
        if(mov!=NULL && !is_already_generated(mov))
        {
            game_queue.push(mov);
            all_states.pb(mov);
        }

        mov=curr->move_down();
        if(mov!=NULL && !is_already_generated(mov))
        {
            game_queue.push(mov);
            all_states.pb(mov);
        }
    }


    return 0;
}
