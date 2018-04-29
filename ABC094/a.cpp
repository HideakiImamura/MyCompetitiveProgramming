//
// Created by 今村秀明 on 2018/04/14.
//
#include <stdio.h>

int main() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    if (0 <= x - a &&  x - a <= b) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
