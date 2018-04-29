//
// Created by 今村秀明 on 2016/09/04.
//
#include <stdio.h>
#include <math.h>

int N;
long long int x;
long long int a[2000];
long long int b[2000][2000];//呪文をk回唱えた時に色iのスライムを飼うのにかかる時間がb[k][i]

long long int min(long long int a, long long int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long long int sum(int k) {
    if (k == 0) {
        long long int ans = 0;
        for (int i = 0; i < N; i++) {
            b[0][i] = a[i];
            ans += a[i];
        }
        return ans;
    } else {
        long long int ans = 0;
        for (int i = 0; i < N; i++) {
            b[k][i] = min(b[k - 1][i], a[(i - k + N) % N]);
            ans += b[k][i];
        }
        return ans;
    }
}

int main() {
    scanf("%d %lld", &N, &x);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }

    long long int ans = sum(0);
    long long int tmp;
    for (int k = 1; k <= N - 1; k++) {
        tmp = k * x + sum(k);
        if (tmp < ans) ans = tmp;
    }

    printf("%lld\n", ans);

    return 0;
}