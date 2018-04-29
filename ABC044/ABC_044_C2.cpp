//
// Created by 今村秀明 on 2016/09/04.
//

#include <stdio.h>

int main() {
    int N, A;
    int y[51];

    scanf("%d %d", &N, &A);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &y[i]);
    }

    int X = 0;
    int dp[51][5000]; //dp[j][t]はy1..yjを1枚以上用いてt-NXにする場合の数

    for (int i = 1; i <= N; i++) {
        if (X < y[i]) X = y[i];
    }
    if (X < A) X = A;
    for (int i = 1; i <= N; i++) {
        y[i] -= A;
    }

    for (int t = 0; t <= 2 * N * X; t++) {
        for (int j = 0; j <= N; j++) {
            if (j == 0 && t == N * X) {
                dp[j][t] = 1;
            } else if (j >= 1 && (t - y[j] < 0 || t - y[j] > 2 * N * X)) {
                dp[j][t] = dp[j - 1][t];
            } else if (j >= 1 && t - y[j] >= 0 && t - y[j] <= 2 * N * X) {
                dp[j][t] = dp[j - 1][t] + dp[j - 1][t - y[j]];
            } else {
                dp[j][t] = 0;
            }
        }
    }

    int ans;

    ans = dp[N][N * X] - 1;

    printf("X=%d\nans=%d\n", X, ans);

    return 0;
}