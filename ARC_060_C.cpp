//
// Created by 今村秀明 on 2016/09/07.
//
#include <stdio.h>

int n, a;
int x[51];

int main() {
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
    }

    int X = a;
    for (int i = 1; i <= n; ++i) {
        if (X < x[i]) X = x[i];
    }

    long long int dp[51][5000];//dp[j][t]はx1からxjから0枚以上選んで合計をt-NXにする選び方の総数
    int y[51];
    for (int i = 1; i <= n; ++i) {
        y[i] = x[i] - a;
    }

    for (int j = 0; j <= n; ++j) {
        for (int t = 0; t <= 2 * n * X; ++t) {
            if (j == 0 && t == n * X) {
                dp[j][t] = 1;
            } else if (j >= 1 && (2 * n * X < t - y[j] || t - y[j] < 0)) {
                dp[j][t] = dp[j - 1][t];
            } else if (j >= 1 && 0 <= t - y[j] && t - y[j] <= 2 * n * X) {
                dp[j][t] = dp[j - 1][t] + dp[j - 1][t - y[j]];
            } else {
                dp[j][t] = 0;
            }
        }
    }

    printf("%lld\n", dp[n][n * X] - 1);

    return 0;
}