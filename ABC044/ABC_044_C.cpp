//
// Created by 今村秀明 on 2016/09/04.
//

#include <stdio.h>

int main() {
    int N;
    int A;
    int x[51];
    scanf("%d", &N);
    scanf("%d", &A);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x[i]);
    }

    long int ans = 0;
    int X = 0;
    for (int i = 1; i <= N; i++) {
        if (X < x[i]) {
            X = x[i];
        }
    }
    if (X < A) X = A;
    long int dp[51][50][2500]; // dp[j][k][s]は、x1 .. xjの中からk枚選んでsにする選び方の総数

    for (int j = 0; j <= N; j++) {
        for (int k = 0; k <= j; k++) {
            for (long int s = 0; s <= k * X; s++) {
                if (j == 0 && k == 0 && s == 0) {
                    dp[j][k][s] = 1;
                } else if (x[j] > s && j >= 1) {
                    dp[j][k][s] = dp[j - 1][k][s];
                } else if (x[j] <= s && j >= 1 && k >= 1) {
                    dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j]];
                } else {
                    dp[j][k][s] = 0;
                }
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        ans += dp[N][k][k * A];
    }
    printf("%ld", ans);

    return 0;
}
