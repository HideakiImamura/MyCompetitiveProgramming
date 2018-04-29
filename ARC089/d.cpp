//
// Created by 今村秀明 on 2018/02/21.
//

#include <stdio.h>
#include <algorithm>

const int max_n = 1e5;
const int max_k = 1000;
int a[3 * max_k][3 * max_k];
int s[2][max_k][max_k];

void print(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < 3 * K; i++) {
        for (int j = 0; j < 3 * K; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            s[0][i][j] = 0;
            s[1][i][j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        if (c == 'W') {
            y += K;
        }
        x %= 2 * K;
        y %= 2 * K;
        a[x][y] += 1;
        a[x + K][y + K] += 1;
        a[x + K][y] -= 1;
        a[x][y + K] -= 1;
    }
    //print(3 * K, 3 * K);

    for (int i = 0; i < 3 * K; ++i) {
        for (int j = 1; j < 3 * K; ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
    //print(3 * K, 3 * K);

    for (int i = 1; i < 3 * K; ++i) {
        for (int j = 0; j < 3 * K; ++j) {
            a[i][j] += a[i - 1][j];
        }
    }
    //print(3 * K, 3 * K);

    for(int i = 0; i < 3 * K; ++i) {
        for(int j = 0; j < 3 * K; ++j) {
            int p = (i / K + j / K) % 2;
            s[p][i % K][j % K] += a[i][j];
        }
    }

    int ans = 0;
    for(int p = 0; p < 2; ++p) {
        for (int i = 0; i < 2 * K; ++i) {
            for (int j = 0; j < 2 * K; ++j) {
                ans = std::max(ans, s[p][i][j]);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}