//
// Created by 今村秀明 on 2017/05/03.
//
#include <stdio.h>

int gcd(int a, int b){
    if (a < b){
        int tmp = b;
        b = a;
        a = tmp;
    }
    printf("a = %d, b = %d\n", a, b);
    while(b!=0){
        int tmp = b;
        b = a % b;
        a = tmp;
        printf("a = %d, b = %d\n", a, b);
    }
    return a;
}

int main(int argc, char **argv){
    int a, b, c, k;
    scanf("%d %d %d", &a, &b, &c);
    k = gcd(a, b);
    if (c % k == 0){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}