//
// Created by 今村秀明 on 2017/05/03.
//
#include <stdio.h>


int main(int argc, char ** argv){
    int a, b, c;
    bool flag = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (int i=1; i<=b; i++){
        if (a*i % b == c){
            flag = 1;
        }
    }
    if(flag){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}