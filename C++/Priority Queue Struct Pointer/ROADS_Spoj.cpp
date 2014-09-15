#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair







#define gc getchar


inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}







#define INF 999999999

#define MAX_COINS 10002
#define MAX_CITIES 102
#define MAX_ROADS 10003


struct data
{
    int distancee;
    int coins;
    int city;

    data(int x,int y,int z)
    {
        distancee=x;
        coins=y;
        city=z;
    }
};

struct data_pointer_comparator
{
    bool operator()(data *a,data *b)
    {
        if(a->distancee==b->distancee)
        {
            return a->coins>b->coins;
        }

        return (a->distancee>b->distancee);
    }
};



int num_cities;
int num_roads;
int num_coins;
int source_city;
int destination_city;

VI graphh[MAX_CITIES];
VI graphh_cost[MAX_CITIES];
VI graphh_dist[MAX_CITIES];
int shortest_distancee[MAX_CITIES];
int min_cost[MAX_CITIES];


void initt(int num_of_cities)
{
    int i;

    REP(i,num_of_cities)
    {
        graphh[i].clear();
        graphh_cost[i].clear();
        graphh_dist[i].clear();
        shortest_distancee[i]=INF;
        min_cost[i]=INF;
    }

}



void solve()
{
    priority_queue< data* , vector< data * > , data_pointer_comparator> get_nearest_city;

    get_nearest_city.push(new data(0,0,0));
    //shortest_distancee[0]=0;
    //min_cost[0]=0;

    data *shortest_pointer;
    int temp_coins;

    int i;

    while(!get_nearest_city.empty() && shortest_distancee[destination_city]==INF)
    {
        shortest_pointer=get_nearest_city.top();
        get_nearest_city.pop();
        //printf("DD\t%d\t%d\n",shortest_pointer->city,shortest_pointer->coins);

        if(min_cost[shortest_pointer->city]<=shortest_pointer->coins)
        {
            continue;
        }

        min_cost[shortest_pointer->city]=shortest_pointer->coins;

        shortest_distancee[shortest_pointer->city]=shortest_pointer->distancee;

        for(i=0;i<graphh[shortest_pointer->city].size();++i)
        {
            temp_coins=shortest_pointer->coins+graphh_cost[shortest_pointer->city][i];

            if(temp_coins<=num_coins)
            {
                get_nearest_city.push(new data(shortest_pointer->distancee+graphh_dist[shortest_pointer->city][i],temp_coins,graphh[shortest_pointer->city][i]));
            }
        }

        delete shortest_pointer;

    }
}


int main()
{
    freopen("Text/ROADS.txt","r",stdin);
    int cases,i;

    scanf("%d",&cases);
    int temp_coins,temp_source,temp_destination,temp_distancee;

    while(cases--)
    {
        //scanf("%d %d %d",&num_coins,&num_cities,&num_roads);
        num_coins=readPosInt();
        num_cities=readPosInt();
        num_roads=readPosInt();

        initt(num_cities);
        source_city=0;
        destination_city=num_cities-1;

        REP(i,num_roads)
        {
            //scanf("%d %d %d %d",&temp_source,&temp_destination,&temp_distancee,&temp_coins);
            temp_source=readPosInt();
            temp_destination=readPosInt();
            temp_distancee=readPosInt();
            temp_coins=readPosInt();

            if(temp_source==temp_destination)
            {
                continue;
            }

            --temp_source;
            --temp_destination;

            graphh[temp_source].PB(temp_destination);
            graphh_cost[temp_source].PB(temp_coins);
            graphh_dist[temp_source].PB(temp_distancee);

/*
            graphh[temp_destination].PB(temp_source);
            graphh_cost[temp_destination].PB(temp_coins);
            graphh_dist[temp_destination].PB(temp_distancee);
*/

        }

        solve();

        if(shortest_distancee[destination_city]==INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",shortest_distancee[destination_city]);
        }

    }

    return 0;
}


