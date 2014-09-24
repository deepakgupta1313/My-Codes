#include<stdio.h>
#include<stdlib.h>

#define u64 unsigned long long

u64 bigMod(u64 b, u64 p, u64 m)
{
    u64 tmp = b, r = 1;
    while(p > 0)
    {
        if(p%2==1)
        {
            r = (r*tmp)%m;
        }
        p/=2;
        tmp  = (tmp*tmp)%m;
    }
    return r;
}

bool rabin(u64 p, int iteration)
{
    if(p<2)
        return false;

    if(p!=2 && p%2==0)
        return false;

    u64 s = p-1;
    int cnt = 0;

    while(s%2==0)
    {
        cnt++;
        s/=2;
    }
    for(int i = 0; i < iteration; ++i)
    {
        u64 a = rand()%(p-1)+1;
        unsigned long long mod;

        mod = bigMod(a,s,p);

        if(mod==1 || mod==p-1)
            continue;

        for(int j = 1; j < cnt; ++j)
        {
            mod = (mod*mod)%p;
            if(mod==p-1)
                break;
        }

        if(mod!=p-1)
            return false;
    }
    return true;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        u64 n;
        scanf("%llu",&n);

        if(n==3)
        {
            puts("2");
            continue;
        }

        --n;

        if(n%2==0)  /* to make sure that only the odd numbers are checked */
            --n;

        for( ; ; n-=2)
        if(rabin(n,10)==true)
        break;

        printf("%llu\n",n);
    }
    return 0;
}
