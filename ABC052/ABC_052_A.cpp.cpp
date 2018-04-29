//
// Created by 今村秀明 on 2017/01/20.
//

#include <stdio.h>

int main(){
    int a,b,c,d;
    int s,t;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    s = a * b;
    t = c * d;
    if(s==t){
        printf("%d", s);
    }else if (s > t) {
        printf("%d", s);
    }else{
        printf("%d", t);
    }
    return 0;
}