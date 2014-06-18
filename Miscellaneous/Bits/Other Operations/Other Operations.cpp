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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

int bit_count_32(int num)
{
    num=num-((num>>1)&0x55555555);
    num=num&0x33333333 + (num>>2)&0x33333333;
    num=(num + num>>4)&0x0F0F0F0F;
    num=(num*0x01010101)>>24;

    return num;
}

int bit_count_64(long long num)
{
    num=num-((num>>1)&0x5555555555555555);
    num=num&0x3333333333333333 + (num>>2)&0x3333333333333333;
    num=(num + num>>4)&0x0F0F0F0F0F0F0F0F;
    num=(num*0x0101010101010101)>>56;

    return num;
}

int b_sign_1(int num)
{
    // -1 or 0 is returned
    return -(num<0);
}

int b_sign_2(int num)
{
    // -1 or 0 is returned

    return -(int)((unsigned int)((int)num) >> (sizeof(int)*CHAR_BIT-1));
}

int b_sign_3(int num)
{
    // -1 or 0 or +1 is returned

    return (num!=0) | -(int)((unsigned int)((int)num) >> (sizeof(int)*CHAR_BIT-1));
}

int b_is_non_negative(int num)
{
    // 1 or 0 is returned

    return  1 ^ -(int)((unsigned int)((int)num) >> (sizeof(int)*CHAR_BIT-1));
}

bool have_opposite_sign(int num1,int num2)
{
    return (num1^num2)<0;
}


int b_abs_1(int num)
{
    unsigned int r;
    int const mask = num>>(sizeof(int) * CHAR_BIT -1);
    r=(num + mask) ^ mask;
    return r;
}

int b_abs_2(int num)
{
    unsigned int r;
    int const mask = num>>(sizeof(int) * CHAR_BIT -1);
    r=(num ^ mask) - mask;
    return r;
}


int b_min_1(int x,int y)
{
    int r=y^(x^y & -(x<y));

    return r;
}

int b_min_2(int x,int y)
{
    int r=y + ((x-y) & ((x-y)>>(sizeof(int)*CHAR_BIT-1)));

    return r;
}

int b_max_1(int x,int y)
{
    int r=x^(x^y & -(x<y));

    return r;
}

int b_max_2(int x,int y)
{
    int r=x - ((x-y) & ((x-y)>>(sizeof(int)*CHAR_BIT-1)));

    return r;
}

bool is_power_of_2(int num)
{
    return  num && !(num&(num-1));
}

int sign_extend_from_constant_bit_width_1(int x)
{
    struct
    {
        signed int y:5;
    } s;

    int r=s.y=x;

    return r;
}



template <typename T,unsigned B>
inline T signextend(const T x)
{
    struct
    {
        T x:B;
    } s;

    return s.x=x;
};

int sign_extend_from_constant_bit_width_2(int x)
{
    int r=signextend<signed int,5>(x);
    return r;
}


int sign_extend_from_ariable_bit_width(int x,unsigned b)
{
    int const m=1U<<(b-1);
    x=x&((1U<<b)-1);
    int r=(x^m)-m;

    return r;
}

int conditionally_set_or_clear_bits_1(unsigned int w,unsigned int m,bool f)
{
    w^=(-f ^ w) & m;

    return w;
}


int conditionally_set_or_clear_bits_2(unsigned int w,unsigned int m,bool f)
{
    w = (w & ~m) | (-f & m);

    return w;
}

int conditional_not_negate(int v,bool fDontNegate)
{
    int r=(fDontNegate ^ (fDontNegate-1)) * v;

    return r;
}

int conditional_negate(int v,bool fNegate)
{
    int r=(v ^ -fNegate)+fNegate;

    return r;
}


unsigned int merge_bits(unsigned int a,unsigned int b,unsigned int mask)
{
    // 1 for b and 0 for a

    unsigned int r = a ^ ( (a ^ b) & mask );
}

int b_bit_count1(unsigned int v)
{
    int c=0;

    for(c=0;v;v>>=1)
    {
        c+= v&1;
    }

    return c;
}



static unsigned char BitsSetTable[256]=
{
    #define B2(n) n , n+1 , n+1 , n+2
    #define B4(n) B2(n) , B2(n+1) , B2(n+1) , B2(n+2)
    #define B6(n) B4(n) , B4(n+1) , B4(n+1) , B4(n+2)

    B6(0) , B6(1) , B6(1) , B6(2)
};

int b_bit_count2(unsigned int v )
{
    int c=0;

    c   =   BitsSetTable[v & 0xff] + BitsSetTable[ (v>>8) & 0xff] +
            BitsSetTable[ (v>>16) & 0xff] + BitsSetTable[ (v>>24) & 0xff];

    return c;
}

int b_bit_count3(unsigned int v )
{
    for(int i=0;i<256;++i)
    {
        BitsSetTable[i] = (i & 1) + BitsSetTable[i/2];
    }

    int c=0;
    unsigned char *p = (unsigned char *) &v;

    c   =   BitsSetTable[p[0]] + BitsSetTable[ p[1] ] +
            BitsSetTable[ p[2] ] + BitsSetTable[ p[3] ];

    return c;
}

int b_bit_count4(unsigned int v )
{
    int c=0;
    for(c=0;v;++c)
    {
        v&=(v-1);
    }

    return c;
}


int b_get_column_64(unsigned long long num,int column)
{
    // 64 bit number is represented as 8x8 matrix rowwise

    num=(num<<column) & 0x8080808080808080ull;
    num*=0x2040810204081ull;

    int r=(num>>56) & 0xff;

    return r;
}





static const bool ParityTable256[256] =
{
#   define P2(n) n, n^1, n^1, n
#   define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#   define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
    P6(0), P6(1), P6(1), P6(0)
};

int b_parity(unsigned int v)
{
    v^=v>>16;
    v^=v>>8;

    return ParityTable256[v&0xff];
}






unsigned int b_swap_bits(unsigned int b,unsigned int n,unsigned int i,unsigned int j)
{
    unsigned int x=( (b>>i) ^ (b>>j) ) & ( (1U << n)-1 );
    int r=b ^ ((x<<i) | (x<<j));

    return r;
}








int b_reverse_bits1(unsigned int v)
{
    unsigned int r=v;
    int s=sizeof(v)*CHAR_BIT-1;

    for(v>>=1;v;v>>=1)
    {
        r<<=1;

        r |= v&1;
        --s;
    }

    r<<=s;

    return r;
}






static const unsigned char BitReverseTable256[256] =
{
#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
    R6(0), R6(2), R6(1), R6(3)
};

int b_reverse_bits2(unsigned int v)
{
    unsigned int c;

    c   =   (BitReverseTable256[v & 0xff]<<24) |
            (BitReverseTable256[(v>>8) & 0xff]<<16) |
            (BitReverseTable256[(v>>16) & 0xff]<<8) |
            (BitReverseTable256[(v>>24) & 0xff]);

    return c;
}






unsigned int mod_power_of_2(unsigned int n,unsigned int s)
{
    unsigned int d=1U<<s;
    unsigned int m= n&(d-1);

    return m;
}




int b_count_trailing_zeros(unsigned int v)
{
    int c;

    if(v)
    {
        v=(v^(v-1))>>1;

        for(c=0;v;++c)
        {
            v>>=1;
        }
    }
    else
    {
        c=sizeof(v) * CHAR_BIT;
    }

    return c;
}


unsigned int b_next_largest_power_of_2(unsigned int x)
{
    x |= (x>>1);
    x |= (x>>2);
    x |= (x>>4);
    x |= (x>>8);
    x |= (x>>16);

    return x+1;
}





int b_average1(int x,int y)
{
    return ((x&y) + (x|y))>>1;
}


int b_average2(int x,int y)
{
    return (x&y) + (x^y)>>1;
}




int main()
{

    printf("%d\n",b_bit_count2(-1));
    return 0;
}

