//
// Created by 今村秀明 on 2017/12/27.
//
#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a + b > c + d) {
        printf("Left");
    } else if (a + b < c + d) {
        printf("Right");
    } else {
        printf("Balanced");
    }
    return 0;
}
