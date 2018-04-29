//
// Created by 今村秀明 on 2017/12/27.
//
#include <stdio.h>

int sum_digit(int n) {
    int s = 0;
    while(n > 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int i, s;
    int ans = 0;
    for(i = 1; i <= n; ++i){
        s = sum_digit(i);
        if (a <= s && s <= b){
            ans += i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
