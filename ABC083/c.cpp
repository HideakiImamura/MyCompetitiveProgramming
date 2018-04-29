//
// Created by 今村秀明 on 2017/12/27.
//
#include <stdio.h>

int main(){
    long long int x, y;
    scanf("%lld %lld", &x, &y);

    long long int ans = 0;
    while(x <= y){
        ans++;
        x *= 2;
    }
    printf("%lld\n", ans);

    return 0;
}
