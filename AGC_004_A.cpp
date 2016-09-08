//
// Created by 今村秀明 on 2016/09/04.
//
#include <stdio.h>

long long int min(long long int a, long long int b, long long int c) {
    long long int ans = a;

    if (b < ans) {
        ans = b;
    }
    if (c < ans) {
        ans = c;
    }
    return ans;
}

int main() {
    long long int A, B, C;

    scanf("%lld %lld %lld", &A, &B, &C);

    long long int ans;

    if (A % 2 == 0) {
        ans = 0;
    } else if (B % 2 == 0) {
        ans = 0;
    } else if (C % 2 == 0) {
        ans = 0;
    } else {
        ans = min(A * B, B * C, C * A);
    }

    printf("%lld", ans);

    return 0;
}