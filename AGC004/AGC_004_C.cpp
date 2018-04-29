//
// Created by 今村秀明 on 2016/09/04.
//
#include <stdio.h>

int H, W;
char a[501][501];
char red[501][501];
char blue[501][501];

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", a[i]);
    }

    for (int h = 0; h < H; h++) {
        if (h % 2 == 0) {
            for (int w = 0; w < W - 1; w++) {
                red[h][w] = '#';
            }
            red[h][W - 1] = '.';
        } else {
            for (int w = 1; w < W; w++) {
                red[h][w] = '.';
            }
            red[h][0] = '#';
        }
        red[h][W] = '\0';
    }

    for (int h = 0; h < H; h++) {
        if (h % 2 == 1) {
            for (int w = 1; w < W; w++) {
                blue[h][w] = '#';
            }
            blue[h][0] = '.';
        } else {
            for (int w = 0; w < W - 1; w++) {
                blue[h][w] = '.';
            }
            blue[h][W - 1] = '#';
        }
        blue[h][W] = '\0';
    }

    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (a[h][w] == '#') {
                if (h % 2 == 0) {
                    blue[h][w] = '#';
                } else {
                    red[h][w] = '#';
                }
            }
        }
    }

    for (int h = 0; h < H; h++) {
        printf("%s\n", red[h]);
    }
    printf("\n");
    for (int h = 0; h < H; h++) {
        printf("%s\n", blue[h]);
    }

    return 0;
}