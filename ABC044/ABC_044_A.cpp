#include<stdio.h>

int main() {
    int N, K, X, Y, ans;
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &X);
    scanf("%d", &Y);

    if (N <= K) {
        ans = N * X;
    } else {
        ans = K * X + (N - K) * Y;
    }

    printf("%d", ans);

    return 0;
}