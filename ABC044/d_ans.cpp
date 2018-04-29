//
// Created by 今村秀明 on 2018/02/10.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
ll get(ll x, ll y)
    {
    ll s = 0;
    while(x)
        {
        s += x%y;
        x/=y;
    }
    return s;
}
int main()
    {
    ll n,s;
    scanf("%lld%lld",&n,&s);
    if(n==1)
        {
        if(s==1)return printf("2\n")*0;
        return printf("-1")*0;
    }
    set<ll> pos;
    ll x;
    pos.insert(n+1);
    if(n!=1)
    pos.insert(n);
    if(n > s)
        {
        ll dif = n-s;

        for(x=2;x*x<=dif;x++)if(dif%x==0)
            {
            pos.insert(x);
            pos.insert(x+1);
            if(x*x!=dif){
                pos.insert(dif/x);
                pos.insert(dif/x+1);
            }
        }
        if(dif!=1){
        pos.insert(dif);
            pos.insert(dif+1);
        }
    }
    for(x=2;x*x<=n;x++)pos.insert(x);
    set<ll>::iterator I;
    for(I=pos.begin();I!=pos.end();I++){
     //   printf("checking for %lld\n",*I);
        if(get(n,*I)==s)return printf("%lld\n",*I)*0;

}
        return printf("-1\n")*0;
  //  if(s==1)return printf("%lld\n",n)*0;

}

