//
// Created by 今村秀明 on 2018/02/18.
//

#include <stdio.h>

int main() {
    int c[3][3];
    for(int i = 0; i < 3; ++i) {
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
    }

    if (c[0][1] - c[0][0] == c[1][1] - c[1][0] &&
        c[1][1] - c[1][0] == c[2][1] - c[2][0] &&
        c[0][2] - c[0][0] == c[1][2] - c[1][0] &&
        c[1][2] - c[1][0] == c[2][2] - c[2][0]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}